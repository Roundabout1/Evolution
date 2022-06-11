#include <fstream>
#include <iostream>
#include "GeneticSolutions.h"
#include "../../Pathes.h"
#include "../Auxiliary/Prints.h"
#include "../../Fitness/Fitness.h"
#include "../Non-genetic/nearest.h"
#include "../../Random/Random.h"
#include "../../Termination/Terminator.h"
#include "../../Mutation/Mutation.h"
#include "../../Selection/Selection.h"
#include "../Auxiliary/Other.h"

GenomePoint advanced_k_clusters(int num_population, int num_iterations, GenomePoint &points){
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
    //количество кластеров
    int k = centers.size();
    //кластеры
    std::vector<GeneCluster> clusters;
    for(int i = 0; i < k; i++){
        clusters.push_back(GeneCluster(i, centers[i].getPoint()));
    }
    //изначальные индексы точек
    std::vector<std::vector<int> > originalID(k);
    //заполнение кластеров точками
    for(int i = 0; i < points.size(); i++){
        int clusterID = labels[i];
        originalID[clusterID].push_back(points[i].getType());
        points[i].setType(clusters[clusterID].getCluster().size());
        clusters[clusterID].push_back(points[i]);
    }

    //запуск генетического алгоритма на кластерах
    std::vector<GenomeCluster> cluster_solutions(k);
    for(auto i : clusters){
        int num_population = 2*i.getCluster().size();
        int num_iterations = i.getCluster().size();
        PopulationPoint cur_solutions = clusterGA(num_population, num_iterations, i.getCluster());
        for(auto j : cur_solutions) {
            cluster_solutions[i.getType()].push_back(GeneCluster(i.getType(), j, i.getCenter()));
        }
    }
    //порядок обхода кластеров
    std::vector<std::vector<int>> cluster_path(num_population, std::vector<int>(k));
    for(int i = 0; i < num_population && i < k; i++){
        GenomePoint path = nearest(centers, i);
        for(int j = 0; j < path.size(); j++){
            cluster_path[i][j] = (path[j].getType());
        }
    }
    for(int i = k; i < num_population; i++){
        int j = getRandomNumber(0, i - 1);
        /*for(int h = 0; h < k; h++){
            cluster_path[i].push_back(cluster_path[j][h]);
        }*/
        //переворачивается случайный отрезок
        int a = getRandomNumber(0, k-1);
        int b = getRandomNumber(0, k-1);
        if(a == b)
            a = (a+1)%k;
        if(a > b)
            std::swap(a, b);
        for(int h = 0; h < k; h++)
            cluster_path[i][h] = cluster_path[j][h];
        for(int h = 0; h <= b-a; h++){
            cluster_path[i][a+h] = cluster_path[j][b-h];
        }
    }
    /*for(int i = 0; i < cluster_path.size(); i++){
        for(int j = 0; j < cluster_path[i].size(); j++){
            std::cout << cluster_path[i][j] << ' ';
        }
        std::cout << '\n';
    }*/
    //начальная популяция
    PopulationCluster population(num_population);
    for(int i = 0; i < num_population; i++){
        for(int j = 0; j < cluster_path[i].size(); j++){
            int clusterID = cluster_path[i][j];
            int num_solutions = cluster_solutions[clusterID].size();
            //std::cout << i%num_solutions << '\n';
            population[i].push_back(cluster_solutions[clusterID][i%num_solutions]);
        }
    }
    /*for(int i = 0; i < num_population; i++){
        for(int j = 0; j < population[i].size(); j++){
           std::cout << population[i][j].getType() << ' ';
        }
        std::cout << '\n';
    }*/
    std::vector<double> fit_vec(num_population);
    for (int i = 0; i < fit_vec.size(); i++){
        fit_vec[i] = fitness(population[i]);
    }
    /*PopulationPoint testPop(num_population);
    for(int i = 0; i < num_population; i++){
        for(int j = 0; j < population[i].size(); j++){
            for(int h = 0; h < population[i][j].getCluster().size(); h++){
                testPop[i].push_back(population[i][j].getCluster()[h]);
                //std::cout << population[i][j].getCluster()[h].getType() << ' ';
                int clusterID = population[i][j].getType();
                //std::cout << testPop[i][testPop[i].size()-1].getType() << ' ';
                testPop[i][testPop[i].size()-1].setType(originalID[clusterID][testPop[i][testPop[i].size()-1].getType()]);
                //std::cout << testPop[i][testPop[i].size()-1].getType() << ' ';
            }
        }
    }
    std::cout << print(fitness(testPop));*/
    int best_index = getBest(fit_vec);
    double best_fit = fit_vec[best_index];
    GenomeCluster best = population[best_index];
    //количество мутаций, воздействующих на расположение кластеров
    int num_mutants_perm = num_population;
    //количество мутаций на отдельно взятый кластер
    int num_mutants_single = num_population;
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        //PopulationCluster mutants;
        for(int i = 0; i < num_mutants_perm; i++){
            int j = getRandomNumber(0, num_population-1);
            population.push_back(randomChoice(population[j]));
        }
        for(int i = 0; i < num_mutants_single; i++){
            int j = getRandomNumber(0, num_population-1);
            int c = getRandomNumber(0, k-1);
            //std::cout << fitness(population[j][c].getCluster()) << '\n';
            GenomeCluster mutant = population[j];
            if(i < num_mutants_single/3) {
                mutant[c].setCluster(randomChoice(mutant[c].getCluster()));
            }else{
                mutant[c].setCluster(endsSwap(mutant[c].getCluster()));
            }
            population.push_back(mutant);
            //std::cout << fitness(mutant[c].getCluster()) << '\n';
        }
        //вычисление ФП
        fit_vec.clear();
        for (int i = 0; i < population.size(); i++){
            fit_vec.push_back(fitness(population[i]));
        }
        int cur_best = getBest(fit_vec);
        if(fit_vec[cur_best] < best_fit){
            best_fit = fit_vec[cur_best];
            best = population[cur_best];
            std::cout << terminator.getCurIteration() << '\n';
        }
        tournament(population, num_population, fit_vec);
        terminator.update();
    }
    GenomePoint result;
    for(int i = 0; i < best.size(); i++){
        for(int j = 0; j < best[i].getCluster().size(); j++){
            GenePoint point = best[i].getGenePoint(j);
            int clusterID = best[i].getType();
            point.setType(originalID[clusterID][point.getType()]);
            result.push_back(point);
        }
        std::cout << best[i].isReversed() << ' ';
    }
    std::cout << '\n';
    return result;
}