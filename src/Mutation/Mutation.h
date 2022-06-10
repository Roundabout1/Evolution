
#ifndef EVOLUTIONALGORITHM_MUTATION_H
#define EVOLUTIONALGORITHM_MUTATION_H
#include <vector>
#include "../Random/Random.h"
#include "../Gene/Gene.h"
//begin и end определяют диапазон в пределах которого осуществляется мутация
//begin - 0 + begin - индекс с которого можно мутировать гены
//end - genome.size() - 1 - end - индекс на котором нужно закончить мутацию
Genome mutation(Genome &genome, double probability, int begin=0, int end=0);
Genome mutation(Genome &genome, int begin=0, int end=0);
Genome migration(Genome &genome, int begin=0, int end=0);
Genome randomChoice(Genome &genome, int begin=0, int end=0);
void inversion(Genome &genome);
Genome single_migration(Genome &genome, int begin=0, int end=0);
Population mutation(Population &population, int num_mutants, double probability, int begin=0, int end=0);
Population mutation(Population &population, int num_mutants, int begin=0, int end=0);
#endif //EVOLUTIONALGORITHM_MUTATION_H
