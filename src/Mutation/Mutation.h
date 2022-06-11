
#ifndef EVOLUTIONALGORITHM_MUTATION_H
#define EVOLUTIONALGORITHM_MUTATION_H
#include <vector>
#include "../Random/Random.h"
#include "../Gene/GenePoint.h"
//begin и end определяют диапазон в пределах которого осуществляется мутация
//begin - 0 + begin - индекс с которого можно мутировать гены
//end - genome.size() - 1 - end - индекс на котором нужно закончить мутацию
GenomePoint mutation(GenomePoint &genome, double probability, int begin=0, int end=0);
GenomePoint mutation(GenomePoint &genome, int begin=0, int end=0);
GenomePoint migration(GenomePoint &genome, int begin=0, int end=0);
GenomePoint neighbourSwap(GenomePoint &genome, int begin=0, int end=0);
GenomePoint endsSwap(GenomePoint &genome, int begin=0, int end=0);
GenomePoint randomChoice(GenomePoint &genome, int begin=0, int end=0);
void inversion(std::vector<GenePoint> &genome);
GenomePoint single_migration(GenomePoint &genome, int begin=0, int end=0);
PopulationPoint mutation(PopulationPoint &population, int num_mutants, double probability, int begin=0, int end=0);
PopulationPoint mutation(PopulationPoint &population, int num_mutants, int begin=0, int end=0);
GenomeCluster flip(GenomeCluster &cluster, int begin=0, int end=0);
GenomeCluster neighbourSwap(GenomeCluster &cluster, int begin=0, int end=0);
GenomeCluster single_migration(GenomeCluster &cluster, int begin=0, int end=0);
GenomeCluster randomChoice(GenomeCluster &genome, int begin=0, int end=0);
void flip_void(GenomeCluster &cluster, int begin=0, int end=0);
#endif //EVOLUTIONALGORITHM_MUTATION_H
