
#include "Fix.h"
void fix(Population &population, Genome &example){
    for(int i = 0; i < population.size(); i++)
        fix(population[i], example);
}