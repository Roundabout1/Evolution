#ifndef EVOLUTIONALGORITHM_GENETICSOLUTIONS_H
#define EVOLUTIONALGORITHM_GENETICSOLUTIONS_H
#include "../../Gene/GenePoint.h"
#include "../../Distance_measures.h"

GenomePoint first_evolution(int num_population, int num_iterations, GenomePoint &points);
GenomePoint second_evolution(int num_population, int num_iterations, GenomePoint &points, bool isClosed, measures distance_measure);
GenomePoint mutation_based(int num_population, int num_iterations, GenomePoint &points);
GenomePoint k_clusters_evolution(int num_population, int num_iterations, GenomePoint &points);
GenomePoint advanced_k_clusters(int num_population, int num_iterations, GenomePoint &points);
PopulationPoint clusterGA(int num_population, int num_iterations, GenomePoint &points);
GenomePoint clusterGA(int num_population, int num_iterations, GenomePoint &points, PopulationPoint &init_population);
#endif //EVOLUTIONALGORITHM_GENETICSOLUTIONS_H
