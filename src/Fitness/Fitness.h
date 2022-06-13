#ifndef EVOLUTIONALGORITHM_FITNESS_H
#define EVOLUTIONALGORITHM_FITNESS_H

#include "../Gene/GenePoint.h"
#include "../Distance_measures.h"
double fitness(GenomePoint &genome);
double fitness(GenomePoint &genome, bool isClosed, measures distance_measure);
double fitness(GenomeCluster &cluster);
std::vector<double> fitness(PopulationPoint &population);
std::vector<double> fitness(PopulationPoint &population, bool isClosed, measures distance_measure);
double distance(const Point &a, const Point &b);
double get_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example);
double get_left_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example);
double get_distance(GenomePoint &genome, int pos);
double distance(const Point &a, const Point &b, bool isClosed, measures distance_measure);
double get_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example, bool isClosed, measures distance_measure);
double get_left_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example, bool isClosed, measures distance_measure);
double get_distance(GenomePoint &genome, int pos, bool isClosed, measures distance_measure);
double euclidean_distance(const Point &p1, const Point &p2);
double manhattan_distance(const Point &a, const Point &b);
double euclidean_square(const Point &p1, const Point &p2);
#endif //EVOLUTIONALGORITHM_FITNESS_H