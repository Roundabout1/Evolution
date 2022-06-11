
#ifndef EVOLUTIONALGORITHM_INIT_H
#define EVOLUTIONALGORITHM_INIT_H

#include <vector>
#include "../Gene/GenePoint.h"
#include "../Random/Random.h"

//num_genes - количество генов в одной хромосоме
PopulationPoint random_init(GenomePoint &possible_genes, int num_population);
PopulationPoint greedy_init(GenomePoint &possible_genes, int num_population);
PopulationPoint k_cluster_init(GenomePoint &possible_genes, int num_population);
#endif //EVOLUTIONALGORITHM_INIT_H
