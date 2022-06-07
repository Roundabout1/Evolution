#include "Fix.h"
void fix(Population &population, Genome &example, void (*fix_operator)(std::vector<Gene> &, std::vector<Gene> &)) {
    for(int i = 0; i < population.size(); i++)
        fix_operator(population[i], example);
}
void fix(Population &population, Genome &example){
    fix(population, example, fix_random);
}