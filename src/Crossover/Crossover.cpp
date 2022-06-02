#include "Crossover.h"
#include "../Random/Random.h"

//begin - минимальное количество генов, которые гарантированно достанутся первому родителю
//end - второму
Population crossover(std::vector<std::vector<Gene>> &population, int begin, int end) {
    int num_population = population.size();
    int num_genes = population[0].size();
    Population offspring(num_population*2, Genome(num_genes));
    for(int p1 = 0; p1 < num_population; p1++){
        int p2 = getRandomNumber(0, num_population - 1);
        if(p1 == p2)
            p2 = (p1 + 1)%num_population;
        int cross_point = getRandomNumber(begin, num_genes- 1 - end);
        for(int i = 0; i < num_genes; i++){
            if(i < cross_point){
                offspring[p1][i] = population[p1][i];
                offspring[p1+num_population][i] = population[p2][i];
            }else{
                offspring[p1][i] = population[p2][i];
                offspring[p1+num_population][i] = population[p1][i];
            }
        }
    }
    return offspring;
}
