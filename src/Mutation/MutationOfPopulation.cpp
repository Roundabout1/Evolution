
#include <algorithm>
#include "Mutation.h"
PopulationPoint mutation(std::vector<std::vector<GenePoint>> &population, int num_mutants, double probability, int begin, int end) {
    int num_genes = population[0].size();
    int num_population = population.size();
    PopulationPoint mutants = PopulationPoint(num_mutants);
    std::vector<int> indexes(num_population);
    //генерация чисел от 0 до num_population-1
    std::generate(indexes.begin(), indexes.end(), [n=0]() mutable{return n++;});
    //отбор мутантов случайным образом
    for(int i = 0; i < num_mutants; i++){
        int ind = getRandomNumber(i, num_population-1);
        std::swap(indexes[i], indexes[ind]);
    }
    for(int i = 0; i < num_mutants; i++){
        mutants[i] = mutation(population[indexes[i]], probability);
    }
    return mutants;
}
PopulationPoint mutation(std::vector<std::vector<GenePoint>> &population, int num_mutants, int begin, int end) {
    int num_genes = population[0].size();
    int num_population = population.size();
    PopulationPoint mutants = PopulationPoint(num_mutants);
    std::vector<int> indexes(num_population);
    //генерация чисел от 0 до num_population-1
    std::generate(indexes.begin(), indexes.end(), [n=0]() mutable{return n++;});
    //отбор мутантов случайным образом
    for(int i = 0; i < num_mutants; i++){
        int ind = getRandomNumber(i, num_population-1);
        std::swap(indexes[i], indexes[ind]);
    }
    for(int i = 0; i < num_mutants; i++){
        mutants[i] = mutation(population[indexes[i]]);
    }
    return mutants;
}