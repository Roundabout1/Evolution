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
#include "../Non-genetic/nearest.h"
#include "../../Other/DoubleOperations.h"

GenomePoint k_clusters_evolution(int num_population, int num_iterations, GenomePoint &points, bool  isClosed, measures distance_measure){
    std::vector<int> labels;
    {
        int clusterID;
        std::ifstream read(k_medoids_labels);
        while(read >> clusterID){
            labels.push_back(clusterID);
        }
        read.close();
    }
    std::vector<GenePoint> centers;
    {
        double x, y;
        int clusterID = 0;
        std::ifstream read(k_medoids_centers);
        while(read >> x >> y){
            centers.push_back(GenePoint(clusterID, Point(x, y)));
            clusterID++;
        }
        read.close();
    }
    //int k = std::round(std::sqrt(points.size()) + 0.5);
    int k = centers.size();
    std::vector<GenomePoint> clusters(k);
    std::vector<std::vector<int> > originalID(k);
    for(int i = 0; i < points.size(); i++){
        int clusterID = labels[i];
        int cluster_points = clusters[clusterID].size();
        GenePoint new_gene = GenePoint(cluster_points, points[i].getPoint());
        clusters[clusterID].push_back(new_gene);
        originalID[clusterID].push_back(points[i].getType());
       
    }
    //ln
    PopulationPoint cluster_solutions;
  
    for(auto i : clusters){
        int num_population = 2*i.size();
        int num_iterations = 2*i.size();
        cluster_solutions.push_back(second_evolution(num_population, num_iterations, i, 0, distance_measure));
    }
    //возвращаем оригинальные ID точкам
    for(int i = 0; i < k; i++){
        for(int j = 0; j < cluster_solutions[i].size(); j++){
            cluster_solutions[i][j].setType(originalID[i][cluster_solutions[i][j].getType()]);
        }
    }
    //изначальные обходы кластеров
    std::vector<std::vector<GenePoint> > cluster_tour;
    for(int i = 0; i < k && i < num_population; i++){
        cluster_tour.push_back(nearest(centers, i, isClosed, distance_measure));
    }
    //первёрнутые кластерные решения
    PopulationPoint cluster_solutions_reversed(k);
    for(int i = 0; i < k && i < num_population; i++){
        cluster_solutions_reversed[i] = cluster_solutions[i];
        inversion(cluster_solutions_reversed[i]);
    }
    //формируем начальную популяцию
    PopulationPoint population(num_population, GenomePoint(points.size()));
    for(int i = 0; i < 2*k && i < num_population; i++){
        //std::cout << i << ' ';
        for(int j = 0, g = 0; j < k; j++) {
            int clusterID =  cluster_tour[i%k][j].getType();
            GenomePoint cur_cluster_solution;
            if(j > 0){
                int curLastIndex = cluster_tour[clusterID].size()-1;
                Point prePointEnd = population[i][std::max(0,g-1)].getPoint();
                Point curPointBegin = cluster_solutions[clusterID][0].getPoint();
                Point curPointEnd = cluster_solutions[clusterID][curLastIndex].getPoint();
                if(distance(prePointEnd, curPointEnd, isClosed, distance_measure) > distance(prePointEnd, curPointBegin, isClosed, distance_measure)){
                    cur_cluster_solution = cluster_solutions[clusterID];
                }else{
                    cur_cluster_solution = cluster_solutions_reversed[clusterID];
                }
            }else{
                if(i < k){
                    cur_cluster_solution = cluster_solutions[clusterID];
                }else{
                    cur_cluster_solution = cluster_solutions_reversed[clusterID];
                }
            }
            for (int h = 0; h < cur_cluster_solution.size(); h++) {
                population[i][g] = cur_cluster_solution[h];
                g++;
            }
        }
    }
    for(int i = 2*k; i < num_population; i++){
        int j = getRandomNumber(0, i-1);
        population[i] = mutation(population[j]);
    }

    std::cout << print(fitness(population, isClosed, distance_measure)) << '\n';
    std::vector<double> fit_vec = fitness(population, isClosed, distance_measure);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    GenomePoint best = population[best_index];
    Terminator terminator = Terminator(num_iterations);
    double mutation_chance = 0.1;
    while(!terminator.isSatisfied()){
        PopulationPoint mutants(num_population - 1);
        for(int i = 0; i < num_population-1; i++){
            mutants[i] = mutation(population[i]);
        }
        PopulationPoint offspring;
        for(int p1 = 0; p1 < num_population; p1++){
            int p2 = getRandomNumber(0, num_population - 1);
            if(p1 == p2)
                p2 = (p1 + 1)%num_population;
            if(isEqual(fit_vec[p1], fit_vec[p2]))
                population[p2] = mutation(population[p2]);
            PopulationPoint children = crossover(population[p1], population[p2]);
            offspring.push_back(children[0]);
            offspring.push_back(children[1]);
        }
        fix(offspring, points, fix_greedy_left, isClosed, distance_measure);
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {offspring, mutants};
        PopulationPoint united = concat(populations);
        fit_vec = fitness(united, isClosed, distance_measure);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
        }

        //truncation(united, num_population, fit_vec);
        tournament(united, num_population, fit_vec);
        population = united;
        terminator.update();
    }
    return best;
}