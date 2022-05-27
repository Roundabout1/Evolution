
#ifndef EVOLUTIONALGORITHM_FITNESS_H
#define EVOLUTIONALGORITHM_FITNESS_H

#include "../Gene/Gene.h"

double fitness(Genome &genome);
std::vector<double> fitness(Population &population);
double distance(const Point &a, const Point &b);
#endif //EVOLUTIONALGORITHM_FITNESS_H
