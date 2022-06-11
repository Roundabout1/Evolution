#include <fstream>
#include <iostream>
#include "GeneticSolutions.h"
#include "../../Pathes.h"
#include "../Auxiliary/Prints.h"
#include "../../Fitness/Fitness.h"
#include "../Non-genetic/nearest.h"
#include "../../Random/Random.h"
#include "../../Termination/Terminator.h"

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
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        terminator.update();
    }
    return points;
}