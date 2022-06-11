//
// Created by mrsiv on 02.06.2022.
//

#ifndef EVOLUTIONALGORITHM_NEAREST_H
#define EVOLUTIONALGORITHM_NEAREST_H
#include <vector>
#include "../../Gene/GenePoint.h"
GenomePoint nearest(GenomePoint &points);
GenomePoint nearest(GenomePoint &points, int start_point);
GenomePoint nearest(GenomePoint &points, int start_point, double &result);
#endif //EVOLUTIONALGORITHM_NEAREST_H
