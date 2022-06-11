
#ifndef EVOLUTIONALGORITHM_FITNESS_H
#define EVOLUTIONALGORITHM_FITNESS_H

#include "../Gene/GenePoint.h"

double fitness(GenomePoint &genome);
std::vector<double> fitness(PopulationPoint &population);
double distance(const Point &a, const Point &b);
double get_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example);
double get_left_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example);
double get_distance(GenomePoint &genome, int pos);
double euclidean(const Point &p1, const Point &p2);
double euclideanSquare(const Point &p1, const Point &p2);
#endif //EVOLUTIONALGORITHM_FITNESS_H
