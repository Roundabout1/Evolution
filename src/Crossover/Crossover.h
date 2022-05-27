
#ifndef EVOLUTIONALGORITHM_CROSSOVER_H
#define EVOLUTIONALGORITHM_CROSSOVER_H
#include "../Gene/Gene.h"
#include <vector>
//begin - минимальное количество генов, которые гарантированно достанутся первому родителю
//end - второму
Population crossover(Population &population,int begin=0, int end=0);
#endif //EVOLUTIONALGORITHM_CROSSOVER_H
