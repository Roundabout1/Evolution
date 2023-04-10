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
#include "../../Crossover/Crossover.h"
#include "../../Other/DoubleOperations.h"
#include "../Auxiliary/Stat.h"

GenomePoint advanced_k_clusters(int num_population, int num_iterations, GenomePoint &points, bool  isClosed, measures distance_measure){
    std::vector<int> labels;
    {
        int clusterID;
        std::ifstream read(k_labels);
        while(read >> clusterID){
            labels.push_back(clusterID);
        }
        read.close();
    }

    std::vector<GenePoint> centers;
    {
        double x, y;
        int clusterID = 0;
        std::ifstream read(k_centers);
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
        GenePoint point = points[i];
        point.setType(clusters[clusterID].getCluster().size());
        clusters[clusterID].push_back(point);
    }

    //запуск генетического алгоритма на кластерах
    std::vector<GenomeCluster> cluster_solutions(k);
    for(auto i : clusters){
        int num_population = 2*i.getCluster().size();
        int num_iterations = i.getCluster().size();
        PopulationPoint cur_solutions = clusterGA(num_population, num_iterations, i.getCluster(), 0, distance_measure);
        for(auto j : cur_solutions) {
            cluster_solutions[i.getType()].push_back(GeneCluster(i.getType(), j, i.getCenter()));
        }
    }
    //порядок обхода кластеров
    std::vector<std::vector<int>> cluster_path(k, std::vector<int>(k));
    for(int i = 0; i < num_population && i < k; i++){
        GenomePoint path = nearest(centers, i, isClosed, distance_measure);
        for(int j = 0; j < path.size(); j++){
            cluster_path[i][j] = (path[j].getType());
        }
    }
    //начальная популяция
    PopulationCluster population(num_population);
    for(int i = 0; i < num_population; i++){
        for(int j = 0; j < cluster_path[i%k].size(); j++){
            int clusterID = cluster_path[i%k][j];
            int num_solutions = cluster_solutions[clusterID].size();
            population[i].push_back(cluster_solutions[clusterID][i%num_solutions]);
            if(getRandomNumber(1, k) == k){
                population[i][population[i].size()-1].setCluster(endsSwap(population[i][population[i].size()-1].getCluster()));
            }
        }
        if(getRandomNumber(0, 1))
            flip(population[i]);
    }
    std::vector<double> fit_vec(population.size());
    for(int j = 0; j < num_population; j++) {
        fit_vec[j] = 0;
        for(int i = 0; i < population[j].size(); i++){
            fit_vec[j] += fitness(population[j][i].getCluster(), isClosed, distance_measure);
        }
        if(population[j].size() >= 2) {
            Point p1_begin, p1_end, p2_begin, p2_end;
            p1_begin = population[j][0].getLastGenePoint().getPoint();
            p1_end = population[j][0].getLastGenePoint().getPoint();
            p2_begin = population[j][1].getGenePoint(0).getPoint();
            p2_end = population[j][1].getLastGenePoint().getPoint();
            double dis1 = distance(p1_begin, p2_begin, isClosed, distance_measure);
            double dis2 = distance(p1_begin, p2_end, isClosed, distance_measure);
            double dis3 = distance(p1_end, p2_begin, isClosed, distance_measure);
            double dis4 = distance(p1_end, p2_end, isClosed, distance_measure);
            if(dis3 < dis1 && dis3 < dis2 || dis4 < dis1 && dis4 < dis2){
                population[j][0].reverse();
            }
        }
        for (int i = 1; i < population[j].size(); i++) {
            Point p1_end = population[j][i - 1].getLastGenePoint().getPoint();
            Point p2_begin = population[j][i].getGenePoint(0).getPoint();
            Point p2_end = population[j][i].getLastGenePoint().getPoint();
            double dis1 = distance(p1_end, p2_begin, isClosed, distance_measure);
            double dis2 = distance(p1_end, p2_end, isClosed, distance_measure);
            if (dis2 < dis1) {
                population[j][i].reverse();
                fit_vec[j] += dis2;
            } else {
                fit_vec[j] += dis1;
            }
        }
    }
    int best_index = getBest(fit_vec);
    double best_fit = fit_vec[best_index];
    GenomeCluster best = population[best_index];
    //количество мутаций, воздействующих на расположение кластеров
    int num_mutants_perm = num_population;
    //количество мутаций на отдельно взятый кластер
    int num_mutants_single = num_population;
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        //добавление потомков
        for(int i = 0; i < num_population; i++){
            int j = getRandomNumber(0, num_population-1);
            if(i == j){
                j = (i+1)%num_population;
            }
            if(isEqual(fit_vec[i], fit_vec[j])){
                clustersMutation(population[j], std::max(1, k/2));
                randomChoice(population[i]);
                fit_vec[i] = fitness(population[i], isClosed, distance_measure);
                fit_vec[j] = fitness(population[j], isClosed, distance_measure);
            }
            PopulationCluster offspring = uniform(population[i], population[j]);
            for(int i = 0; i < offspring.size(); i++){
                population.push_back(offspring[i]);
            }
        }
        for(int i = 0; i < num_mutants_single; i++){
            int j = getRandomNumber(0, num_population-1);
            int c = getRandomNumber(0, k-1);
            GenomeCluster mutant = population[j];
            if(population[j][c].getCluster().size() > 2) {
                if (i < num_mutants_single / 3) {
                    mutant[c].setCluster(randomChoice(mutant[c].getCluster()));
                } else {
                    mutant[c].setCluster(endsSwap(mutant[c].getCluster()));
                }
            }else{
                mutant[c].reverse();
            }
            population.push_back(mutant);
        }

        for(int i = 0; i < num_mutants_perm; i++){
            int j = getRandomNumber(0, num_population-1);
            randomChoice(population[j]);
        }
        //вычисление ФП
        fit_vec.clear();
        for (int i = 0; i < population.size(); i++){
            fit_vec.push_back(fitness(population[i], isClosed, distance_measure));
        }
        tournament(population, num_population, fit_vec);
        int cur_best = getBest(fit_vec);
        if(!isEqual(fit_vec[cur_best], best_fit)){
            if(fit_vec[cur_best] < best_fit){
                best_fit = fit_vec[cur_best];
                best = population[cur_best];
                std::cout << terminator.getCurIteration() << '\n';
            }else{
                int j = getRandomNumber(0, num_population-1);
                fit_vec[j] = best_fit;
                population[j] = best;
            }
        }
        for(int i = 0; i < population.size(); i++){
            if(i == cur_best)
                continue;
            if(isEqual(fit_vec[i], fit_vec[cur_best])){
                flip(population[i]);
            }
        }
        terminator.update();
    }
    std::cout << fitness(best, isClosed, distance_measure) << '\n';
    //удаление дубликаторв
    int r = population.size();
    for(int i = 0; i < r - 1; i++){
        int j = i + 1;
        while(j < r){
            if(isEqual(fit_vec[i], fit_vec[j])){
                std::swap(population[j], population[r-1]);
                std::swap(fit_vec[j], fit_vec[r-1]);
                r--;
            }else{
                j++;
            }
        }
    }
    if(r != population.size())
        population.resize(r);
    std::cout << r << '\n';
    PopulationPoint init_population;
    for(int i = 0; i < r; i++){
        init_population.push_back(convert(population[i], originalID));
    }
    std::cout << print(points) << '\n';
    return clusterGA(num_population, num_iterations, points, isClosed, distance_measure, init_population);
}