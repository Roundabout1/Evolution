

#include <algorithm>
#include <iostream>
#include "Selection.h"
#include "../Fitness/Fitness.h"
//элитарный отбор, отбираются лучшие select особей
Population selection(Population population, int num_selected){
    std::sort(population.begin(), population.end(),[&](Genome &a, Genome &b){
        return fitness(a) < fitness(b);
    });
    population.resize(num_selected);
    return population;
}

void selection(std::vector<std::vector<Gene>> &population, int num_selected, std::vector<double> &fit_vec) {
    std::vector<int> indexes(population.size());
    for(int i = 0; i < population.size(); i++)
        indexes[i] = i;
    std::sort(indexes.begin(), indexes.end(),[&](int &a, int &b){
        return fit_vec[a] < fit_vec[b];
    });
    Population sorted;
    std::vector<double> sorted_fit;
    for(int i = 0; i < population.size(); i++){
        sorted.push_back(population[indexes[i]]);
        sorted_fit.push_back(fit_vec[indexes[i]]);
    }
    population = sorted;
    fit_vec = sorted_fit;
    population.resize(num_selected);
    fit_vec.resize(num_selected);
}

