#ifndef EVOLUTIONALGORITHM_NEAREST_H
#define EVOLUTIONALGORITHM_NEAREST_H
#include <vector>
#include "../../Gene/GenePoint.h"
#include "../../Distance_measures.h"
GenomePoint nearest(GenomePoint &points, bool isClosed, measures distance_measure);
GenomePoint nearest(GenomePoint &points, int start_point, bool isClosed, measures distance_measure);
GenomePoint nearest(GenomePoint &points, int start_point, double &result, bool isClosed, measures distance_measure);
#endif //EVOLUTIONALGORITHM_NEAREST_H
