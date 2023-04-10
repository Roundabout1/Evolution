#ifndef EVOLUTIONALGORITHM_ROULETTE_H
#define EVOLUTIONALGORITHM_ROULETTE_H

#include <vector>

int roulette(std::vector<double> &prefix);
std::vector<double> get_prefix(std::vector<int> &rank);
std::vector<int> get_rank(std::vector<double> &fit);
#endif //EVOLUTIONALGORITHM_ROULETTE_H
