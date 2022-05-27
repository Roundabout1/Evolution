#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../Gene/Gene.h"
#include "../../Initialization/Init.h"
#include "../../Termination/Terminator.h"
#include "../../Mutation/Mutation.h"
#include "../../Fitness/Fitness.h"
#include "../../Crossover/Crossover.h"
#include "../../Fix/Fix.h"
#include "../../Selection/Selection.h"
#include "Pathes.h"
#include "Stat.h"
#include "ReadData.h"
#include "Prints.h"

int main() {

    int num_cities, num_population, num_iterations;
    Genome points;
    readData(num_cities, num_population, num_iterations, points);

    Stat stat = Stat(num_iterations);

    Population population = init(points, num_population);
    print(population[0]);
    ln
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        Population mutants = mutation(population, num_population, 1.0/num_population);
        Population offspring = crossover(population);
        fix(offspring, points);
        std::vector<Population> populations = std::vector<Population> {population, offspring, mutants};
        Population united = concat(populations);
        Population selected = selection(united, num_population);
        population = selected;
        terminator.update();

        stat.gatherAll(population, fitness(population));
    }
    print(population[0]);
    ln
    return 0;
}
