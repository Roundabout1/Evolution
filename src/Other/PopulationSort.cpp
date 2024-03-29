#include <algorithm>
#include "PopulationSort.h"

void sort(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec, bool increase) {
    std::vector<int> indexes(population.size());
    for(int i = 0; i < population.size(); i++)
        indexes[i] = i;
    std::sort(indexes.begin(), indexes.end(),[&](int &a, int &b){
        if(increase)
            return fit_vec[a] < fit_vec[b];
        else
            return fit_vec[a] > fit_vec[b];
    });
    PopulationPoint sorted;
    std::vector<double> sorted_fit;
    for(int i = 0; i < population.size(); i++){
        sorted.push_back(population[indexes[i]]);
        sorted_fit.push_back(fit_vec[indexes[i]]);
    }
    population = sorted;
    fit_vec = sorted_fit;
}
