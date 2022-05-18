

#include <vector>
#include "Fitness.h"
#include "Gen.h"
//оценка для задачи Коммивояжёра
double fitness(Genome genome) {
    double sum = genome[0].getPoint().distance(genome[genome.size()-1].getPoint());
    for(int i = 1; i < genome.size(); i++){
        sum += genome[i-1].getPoint().distance(genome[i].getPoint());
    }
    return sum;
}
