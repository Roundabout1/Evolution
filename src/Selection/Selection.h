#ifndef EVOLUTIONALGORITHM_SELECTION_H
#define EVOLUTIONALGORITHM_SELECTION_H

#include "../Gene/GenePoint.h"

PopulationPoint selection(PopulationPoint population, int num_selected);
void truncation(PopulationPoint &population, int num_selected, std::vector<double> &fit_vec);
void tournament(PopulationPoint &population, int num_selected, std::vector<double> &fit_vec);
PopulationPoint roulette(PopulationPoint &population, int num_selected, std::vector<double> &fit_vec);
PopulationPoint rank(PopulationPoint &population, int num_selected, std::vector<double> &fit_vec);
PopulationPoint rank2(PopulationPoint &population, int num_selected, std::vector<double> &fit_vec);
PopulationCluster tournament(PopulationCluster &population, int num_selected, std::vector<double> &fit_vec);
#endif //EVOLUTIONALGORITHM_SELECTION_H
