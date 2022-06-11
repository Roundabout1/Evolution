#include <vector>
#include "Fitness.h"
//оценка для задачи Коммивояжёра
double fitness(GenomePoint &genome) {
    //double sum = distance(genome[0].getPoint(), genome[genome.size()-1].getPoint());
    double sum = 0;
    for(int i = 1; i < genome.size(); i++){
        sum += distance(genome[i-1].getPoint(), genome[i].getPoint());
    }
    return sum;
}
