#include "Roulette.h"
#include "../Random/Random.h"
#include "DoubleOperations.h"

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
    //сумма вероятностей быть выбранным
    std::vector<double> prefix(rank.size());
    prefix[0] = rank[0];
    for(int i = 1; i < rank.size(); i++) {
        prefix[i] = prefix[i - 1] + rank[i];
    }
    double sum = prefix[rank.size()-1];
    for(int i = 0; i < rank.size(); i++) {
        prefix[i] /= sum;
    }
    return prefix;
}
//fit должен быть отсортированным
std::vector<int> get_rank(std::vector<double> &fit) {
    std::vector<int> rank(fit.size());
    rank[0] = 1;
    for(int i = 1; i < fit.size(); i++){
        rank[i] = rank[i-1];
        if(!isEqual(fit[i-1], fit[i]))
            rank[i]++;
    }
    return rank;
}
