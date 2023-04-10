#include <vector>
#include "Fitness.h"
#include "../Distance_measures.h"

std::vector<double> fitness(PopulationPoint &population, bool isClosed, measures distance_measure){
    std::vector<double> fitness_population;
    for(auto i : population){
        fitness_population.push_back(fitness(i, isClosed, distance_measure));
    }
    return fitness_population;
}