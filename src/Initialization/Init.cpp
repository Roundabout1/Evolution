
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