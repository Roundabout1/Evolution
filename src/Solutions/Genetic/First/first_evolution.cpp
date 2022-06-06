#include "first_evolution.h"
#include <vector>
#include "../../../Other/Point.h"
#include "../../../Gene/Gene.h"
#include "../../../Termination/Terminator.h"
#include "../../../Crossover/Crossover.h"
#include "../../../Fix/Fix.h"
#include "../../../Selection/Selection.h"
#include "../../../Mutation/Mutation.h"
#include "../../../Initialization/Init.h"
#include "../../../Fitness/Fitness.h"
#include "../../Auxiliary/Stat.h"

Genome first_evolution(int num_population, int num_iterations, Genome &points){
    int num_points = points.size();
    Population population = random_init(points, num_population);
    Stat stat = Stat(num_iterations);
    //double best_fit = fitness(population[0]);
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        Population mutants = mutation(population, num_population, 2.0/num_points);
        Population offspring = crossover_random_parents(population);
        fix(offspring, points);
        std::vector<Population> populations = std::vector<Population> {population, offspring, mutants};
        Population united = concat(populations);
        //если предпосчитать fit_vec, то вычисления идут примерно в два раза быстрее
        std::vector<double> fit_vec = fitness(united);
        population = rank(united, num_population, fit_vec);
        //population = united;
        terminator.update();
        stat.gatherAll(population, fitness(population));
    }
    return population[0];
}