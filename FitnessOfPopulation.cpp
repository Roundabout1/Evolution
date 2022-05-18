#include <vector>
#include "Fitness.h"
std::vector<double> fitness(Population population){
    std::vector<double> fitness_population;
    for(auto i : population){
        fitness_population.push_back(fitness(i));
    }
    return fitness_population;
}
/*std::generate(fitness_population.begin(), fitness_population.end(),
                  [&population](){
                    static int n = -1;
                    n++;
                    return fitness(population[n]);});*/