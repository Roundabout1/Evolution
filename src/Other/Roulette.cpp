#include "Roulette.h"
#include "../Random/Random.h"

int roulette(std::vector<double> &prefix) {
    double p = getRandomNumber(0.0, 1.0);
    int l = 0, r = prefix.size();
    while(l < r - 1){
        int m = (l+r)/2;
        if(prefix[m] < p){
            l = m;
        }else{
            r = m;
        }
    }
    if(prefix[r] - p < p - prefix[l])
        return r;
    else
        return l;
}

std::vector<double> get_prefix(std::vector<int> &rank) {
    //префикс сумма вероятностей быть выбранным
    std::vector<double> prefix(rank.size());
    double sum = rank.size()*(rank.size()+1)/2;
    prefix[0] = 1.0 / sum;
    for(int i = 1; i < rank.size(); i++) {
        prefix[i] = prefix[i - 1] + (i+1) / sum;
    }
    return prefix;
}
