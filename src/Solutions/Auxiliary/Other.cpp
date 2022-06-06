#include "Other.h"
int getBest(Population &population, std::vector<double> &fit_vec){
    int best = 0;
    for(int i = 1; i < population.size(); i++){
        if(fit_vec[i] < fit_vec[best])
            best = i;
    }
    return best;
}

