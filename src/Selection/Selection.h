
#ifndef EVOLUTIONALGORITHM_SELECTION_H
#define EVOLUTIONALGORITHM_SELECTION_H

#include "../Gene/Gene.h"

Population selection(Population population, int num_selected);
void truncation(Population &population, int num_selected, std::vector<double> &fit_vec);
void tournament(Population &population, int num_participated, std::vector<double> &fit_vec);
Population roulette(Population &population, int num_selected, std::vector<double> &fit_vec);
Population rank(Population &population, int num_selected, std::vector<double> &fit_vec);
Population rank2(Population &population, int num_selected, std::vector<double> &fit_vec);
#endif //EVOLUTIONALGORITHM_SELECTION_H
