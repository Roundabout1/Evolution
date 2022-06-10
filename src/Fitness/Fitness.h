
#ifndef EVOLUTIONALGORITHM_FITNESS_H
#define EVOLUTIONALGORITHM_FITNESS_H

#include "../Gene/Gene.h"

double fitness(Genome &genome);
std::vector<double> fitness(Population &population);
double distance(const Point &a, const Point &b);
double get_distance(Genome &genome, Genome &example, int pos_genome, int pos_example);
double get_left_distance(Genome &genome, Genome &example, int pos_genome, int pos_example);
double get_distance(Genome &genome, int pos);
double euclidean(const Point &p1, const Point &p2);
double euclideanSquare(const Point &p1, const Point &p2);
#endif //EVOLUTIONALGORITHM_FITNESS_H
