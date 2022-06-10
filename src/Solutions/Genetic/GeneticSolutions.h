#ifndef EVOLUTIONALGORITHM_GENETICSOLUTIONS_H
#define EVOLUTIONALGORITHM_GENETICSOLUTIONS_H
#include "../../Gene/Gene.h"
Genome first_evolution(int num_population, int num_iterations, Genome &points);
Genome second_evolution(int num_population, int num_iterations, Genome &points);
Genome mutation_based(int num_population, int num_iterations, Genome &points);
Genome k_clusters_evolution(int num_population, int num_iterations, Genome &points);
#endif //EVOLUTIONALGORITHM_GENETICSOLUTIONS_H
