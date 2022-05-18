

#include <algorithm>
#include "Selection.h"
#include "Fitness.h"
//элитарный отбор, отбираются лучшие select особей
Population selection(Population &population, int num_selected){
    int num_population = population.size();
    Population selected = Population(population);
    std::sort(selected.begin(), selected.end(),[&](Genome &a, Genome &b){
        return fitness(a) < fitness(b);
    });
    selected.resize(num_selected);
    return selected;
}