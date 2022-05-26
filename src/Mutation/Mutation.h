
#ifndef EVOLUTIONALGORITHM_MUTATION_H
#define EVOLUTIONALGORITHM_MUTATION_H
#include <vector>
#include "../Random/Random.h"
#include "../Gene/Gene.h"
Genome mutation(Genome &genome, double probability);
Population mutation(Population &population, int num_mutants, double probability);
#endif //EVOLUTIONALGORITHM_MUTATION_H
