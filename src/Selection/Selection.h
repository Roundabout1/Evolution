
#ifndef EVOLUTIONALGORITHM_SELECTION_H
#define EVOLUTIONALGORITHM_SELECTION_H

#include "../Gene/Gene.h"

Population selection(Population population, int num_selected);
void selection(Population &population, int num_selected, std::vector<double> &fit_vec);
#endif //EVOLUTIONALGORITHM_SELECTION_H
