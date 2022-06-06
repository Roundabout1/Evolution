//
// Created by mrsiv on 05.06.2022.
//

#include <algorithm>
#include "PopulationSort.h"

void sort(std::vector<std::vector<Gene>> &population, std::vector<double> &fit_vec) {
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
}
