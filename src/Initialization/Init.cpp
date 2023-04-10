#include <iostream>
#include "Init.h"
#include "../Solutions/Non-genetic/nearest.h"
#include "../Mutation/Mutation.h"

PopulationPoint random_init(GenomePoint &possible_genes, int num_population){
    int num_genes = possible_genes.size();
    PopulationPoint population(num_population, GenomePoint(num_genes));
    for(int i = 0; i < num_population; i++){
        //копируем гены
        for(int j = 0; j < num_genes; j++){
            population[i][j] = possible_genes[j];
        }
        //переставляем случайным гены
        for(int j = 0; j < num_genes; j++){
            int k = getRandomNumber(0, num_genes-1);
            std::swap(population[i][j], population[i][k]);
        }
    }
    return population;
}

PopulationPoint k_cluster_init(std::vector<GenePoint> &possible_genes, int num_population) {
    return std::vector<std::vector<GenePoint>>();
}

PopulationPoint greedy_init(std::vector<GenePoint> &possible_genes, int num_population, bool isClosed,
                            measures distance_measure) {
    int num_genes = possible_genes.size();
    PopulationPoint population;
    for(int i = 0; i < num_population && i < num_genes; i++)
        population.push_back(nearest(possible_genes, i, isClosed, distance_measure));
    for(int i = num_genes; i < num_population; i++){
        int j = getRandomNumber(0, num_genes-1);
        population.push_back(mutation(population[j]));
    }
    return population;
}