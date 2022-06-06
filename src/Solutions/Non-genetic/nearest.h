//
// Created by mrsiv on 02.06.2022.
//

#ifndef EVOLUTIONALGORITHM_NEAREST_H
#define EVOLUTIONALGORITHM_NEAREST_H
#include <vector>
#include "../../Gene/Gene.h"
Genome nearest(Genome &points);
Genome nearest(Genome &points, int start_point);
Genome nearest(Genome &points, int start_point, double &result);
#endif //EVOLUTIONALGORITHM_NEAREST_H
