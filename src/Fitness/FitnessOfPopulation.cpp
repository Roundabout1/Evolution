#include <vector>
#include "Fitness.h"
#include "../Distance_measures.h"

std::vector<double> fitness(PopulationPoint &population){
    std::vector<double> fitness_population;
    for(auto i : population){
        fitness_population.push_back(fitness(i));
    }
    return fitness_population;
}
std::vector<double> fitness(PopulationPoint &population, bool isClosed, measures distance_measure){
    std::vector<double> fitness_population;
    for(auto i : population){
        fitness_population.push_back(fitness(i, isClosed, distance_measure));
    }
    return fitness_population;
}

/*std::generate(fitness_population.begin(), fitness_population.end(),
                  [&population](){
                    static int n = -1;
                    n++;
                    return fitness(population[n]);});*/