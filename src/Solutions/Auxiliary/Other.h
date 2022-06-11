//
// Created by mrsiv on 28.05.2022.
//

#ifndef EVOLUTIONALGORITHM_OTHER_H
#define EVOLUTIONALGORITHM_OTHER_H
#include "../../Gene/GenePoint.h"
#include "../../Fitness/Fitness.h"
int getBest(PopulationPoint &population, std::vector<double> &fit_vec);
GenomePoint getBest(PopulationPoint &population);
#endif //EVOLUTIONALGORITHM_OTHER_H
