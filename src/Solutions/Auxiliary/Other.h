//
// Created by mrsiv on 28.05.2022.
//

#ifndef EVOLUTIONALGORITHM_OTHER_H
#define EVOLUTIONALGORITHM_OTHER_H
#include "../../Gene/Gene.h"
#include "../../Fitness/Fitness.h"
int getBest(Population &population, std::vector<double> &fit_vec);
Genome getBest(Population &population);
#endif //EVOLUTIONALGORITHM_OTHER_H
