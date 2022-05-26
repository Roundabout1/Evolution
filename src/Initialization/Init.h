
#ifndef EVOLUTIONALGORITHM_INIT_H
#define EVOLUTIONALGORITHM_INIT_H

#include <vector>
#include "../Gene/Gene.h"
#include "../Random/Random.h"

//num_genes - количество генов в одной хромосоме
Population init(Genome &possible_genes, int num_population);

#endif //EVOLUTIONALGORITHM_INIT_H