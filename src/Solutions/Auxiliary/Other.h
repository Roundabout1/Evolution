#ifndef EVOLUTIONALGORITHM_OTHER_H
#define EVOLUTIONALGORITHM_OTHER_H
#include "../../Gene/GenePoint.h"
#include "../../Fitness/Fitness.h"
int getBest(PopulationPoint &population, std::vector<double> &fit_vec);
int getBest(std::vector<double> &fit_vec);

std::vector<GenePoint> convert(std::vector<GeneCluster> &cluster, std::vector<std::vector<int>> &originalID);
GenomePoint convert(GenomePoint &points, std::vector<std::vector<int>> &originalID);
#endif //EVOLUTIONALGORITHM_OTHER_H
