#ifndef EVOLUTIONALGORITHM_PRINTS_H
#define EVOLUTIONALGORITHM_PRINTS_H
#include "../../Gene/GenePoint.h"
#include <string>
std::string print(GenomePoint &genome);
std::string print(PopulationPoint &population);
std::string print(std::vector<double> v);
#define ln std::cout << '\n';
#endif //EVOLUTIONALGORITHM_PRINTS_H
