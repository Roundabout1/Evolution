#include <iostream>
#include <fstream>
#include "GeneticSolutions.h"
#include "../../K-clusters/k-clusters.h"
#include "../../Pathes.h"
#include "../Auxiliary/Prints.h"
#include "../../Random/Random.h"
#include "../../Selection/Selection.h"
#include "../Auxiliary/Other.h"
#include "../../Fix/Fix.h"
#include "../../Crossover/Crossover.h"
#include "../../Mutation/Mutation.h"
#include "../../Termination/Terminator.h"
#include "../Auxiliary/Stat.h"
#include "../../Other/PopulationSort.h"

Genome k_clusters_evolution(int num_population, int num_iterations, Genome &points){
    std::ifstream read(k_medoids_labels);
    std::vector<int> labels;
    int clusterID;
    while(read >> clusterID){
        labels.push_back(clusterID);
    }
    read.close();
    /*for(auto i : labels)
        std::cout << i << ' ';*/

    int k = std::round(std::sqrt(points.size()) + 0.5);
    std::vector<Genome> clusters(k);
    std::vector<std::vector<int> > originalID(k);
    for(int i = 0; i < points.size(); i++){
        clusterID = labels[i];
        int cluster_points = clusters[clusterID].size();
        Gene new_gene = Gene(cluster_points, points[i].getPoint());
        clusters[clusterID].push_back(new_gene);
        originalID[clusterID].push_back(points[i].getType());
        //std::cout << cluster_points << ' ' << points[i].getType() << '\n';
    }
    //ln
    Population cluster_solutions;
    for(auto i : clusters){
        int num_population = 2*i.size();
        int num_iterations = 2*i.size();
        cluster_solutions.push_back(second_evolution(num_population, num_iterations, i));
        //cluster_solutions.push_back(mutation_based(num_population, num_iterations, i));
    }
    //возвращаем оригинальные ID точкам
    for(int i = 0; i < k; i++){
        for(int j = 0; j < cluster_solutions[i].size(); j++){
            //Gene gene = cluster_solutions[i][j];
            //std::cout <<gene.getType() << ' ' << originalID[i][gene.getType()] << '\n';
            cluster_solutions[i][j].setType(originalID[i][cluster_solutions[i][j].getType()]);
        }
    }
    //формируем начальную популяцию
    /*Population population(num_population);
    for(int i = 0; i < num_population; i++){
        //int sz = cluster_solutions[i].size();
        for(int j = 0; j < k; j++) {
            for (int h = 0; h < cluster_solutions[j].size(); h++) {
                population[i].push_back(cluster_solutions[j][h]);
            }
        }
        int pos1 = getRandomNumber(0, k-1), pos2 = getRandomNumber(0, k-1);
        if(pos1 == pos2)
            pos2 = (pos1+1)%k;
        std::swap(cluster_solutions[pos1], cluster_solutions[pos2]);
        //pref += sz;
    }*/
    Population nearest_clusters(k);
    Population reversed_clusters(k);
    for(int i = 0; i < k; i++){
        nearest_clusters[i] = cluster_solutions[i];
        reversed_clusters[i] = cluster_solutions[i];
        inversion(reversed_clusters[i]);
    }
    std::cout << print(cluster_solutions);
    ln
    std::cout << print(reversed_clusters);
    Population population;
    for(int i = 0; i < 2*k; i++){
        Genome cur_path;
        if(i < k)
            cur_path = Genome(nearest_clusters[i]);
        else
            cur_path = Genome(reversed_clusters[i]);
        for(int j = 1; j < k; j++){
            double min1 = distance(cur_path[j-1][cur_path[j-1].size()-1].getPoint(), cur_path[j][0].getPoint());
            double min2 = distance(cur_path[j-1][cur_path[i].size()-1].getPoint(), cur_path[j][0].getPoint());
        }
    }
//    for(int i = 0; i < k; i++){
//        nearest_clusters[0] = cluster_solutions[i];
//        for(int j = 1; j < k; j++){
//            double min = distance(nearest_clusters[j-1][nearest_clusters.size()-1].getPoint(), nearest_clusters[j][0].getPoint());
//            int cur_best = j;
//            for(int h = j+1; h < k; h++){
//                double cur = distance(nearest_clusters[j-1][nearest_clusters.size()-1].getPoint(), nearest_clusters[h][0].getPoint());
//                if(cur < min){
//                    min = cur;
//                    std::swap(j, h);
//                }
//            }
//        }
//    }
//    //std::cout << print(population);
//    std::vector<double> fit_vec = fitness(population);
//    int best_index = getBest(population, fit_vec);
//    double best_fit = fit_vec[best_index];
//    Genome best = population[best_index];
//    //Stat stat = Stat(num_iterations);
//    Terminator terminator = Terminator(num_iterations);
//    double mutation_chance = 0.1;
//    //std::cout << mutation_chance << std::endl;
//    //std::cout << "a\n";
//    //std::cout << fit_vec[best_index] << std::endl;
//    while(!terminator.isSatisfied()){
//        int invs = std::max(1, num_population/10);
//        for(int i = 0; i < invs; i++) {
//            int j = getRandomNumber(0, num_population-1);
//            inversion(population[i]);
//        }
//        Population mutants(num_population-1);
//        for(int i = 0; i < num_population-1; i++){
//            mutants[i] = randomChoice(population[i]);
//        }
//        /*for(int i = 0; i < num_population/2; i++){
//            int j = getRandomNumber(0, num_population-1);
//            mutants.push_back(single_migration(population[j]));
//        }*/
//        //fit_vec = fitness(population);
//        //sort(population, fit_vec, true);
//        //Population offspring = crossover_similar(population, fit_vec);
//        //Population offspring = ordered(population);
//        //Population offspring = crossover_different2(population, fit_vec, 2);
//        Population offspring = crossover_random_parents(population);
//        fix(offspring, points, fix_greedy_left);
//        //std::cout << terminator.getCurIteration() << " generation\n" << print(fitness(offspring)) << '\n';
//        std::vector<Population> populations = std::vector<Population> {offspring, mutants};
//        Population united = concat(populations);
//        fit_vec = fitness(united);
//        int cur_best = getBest(united, fit_vec);
//        bool isProgressed = fit_vec[cur_best] < best_fit;
//        if(isProgressed) {
//            best = united[cur_best];
//            best_fit = fit_vec[cur_best];
//            std::cout << terminator.getCurIteration() << std::endl;
//            united.push_back(randomChoice(population[getRandomNumber(0, num_population-1)]));
//            fit_vec.push_back(fitness(united[united.size()-1]));
//        }else{
//            united.push_back(best);
//            fit_vec.push_back(best_fit);
//        }
//        //truncation(united, num_population, fit_vec);
//        tournament(united, num_population, fit_vec);
//        population = united;
//        //sort(united, fit_vec, false);
//        //population = rank2(united, num_population, fit_vec);
//        terminator.update();
//        //stat.gatherAll(population, fitness(population));
//    }
//    //std::cout << best_fit << std::endl;
//    //std::cout << "b\n";
//    return best;
    return points;
}