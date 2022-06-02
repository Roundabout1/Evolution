#include <vector>
#include <algorithm>
#include "../../../Gene/Gene.h"
#include "../../../Fitness/Fitness.h"
#include "../../Auxiliary/Stat.h"
#include "../../Auxiliary/ReadData.h"
#include "first_evolution.h"
int main() {

    int num_population, num_iterations;
    Genome points;
    readData(num_population, num_iterations, points);
    Genome result = first_evolution(num_population, num_iterations, points);
    Stat::gatherGenome(result);
    Stat::gatherFitness(fitness(result));
    return 0;
}