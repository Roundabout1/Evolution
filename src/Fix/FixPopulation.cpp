#include "Fix.h"
void fix(PopulationPoint &population, GenomePoint &example){
    for(int i = 0; i < population.size(); i++)
        fix_random(population[i], example);
}

void fix(PopulationPoint &population, GenomePoint &example, void (*fix_operator)(GenomePoint &genome, GenomePoint &example, bool  isClosed, measures distance_measures), bool isClosed, measures distance_measure){
    for(int i = 0; i < population.size(); i++)
        fix_operator(population[i], example, isClosed, distance_measure);
}