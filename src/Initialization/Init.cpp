#include "Init.h"
#include "../Solutions/Non-genetic/nearest.h"
#include "../Mutation/Mutation.h"

Population random_init(Genome &possible_genes, int num_population){
    int num_genes = possible_genes.size();
    Population population(num_population, Genome(num_genes));
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

Population greedy_init(std::vector<Gene> &possible_genes, int num_population) {
    int num_genes = possible_genes.size();
    Population population;
    for(int i = 0; i < num_population && i < num_genes; i++)
        population.push_back(nearest(possible_genes, i));
    for(int i = num_genes; i < num_population; i++){
        int j = getRandomNumber(0, num_genes-1);
        population.push_back(mutation(population[j]));
    }
    return population;
}

Population k_cluster_init(std::vector<Gene> &possible_genes, int num_population) {
    return std::vector<std::vector<Gene>>();
}
/*
 #include "Init.h"
Population init(Genome &possible_genes, int num_population){
    int num_genes = possible_genes.size();
    Population population(num_population, Genome(num_genes));
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
 */