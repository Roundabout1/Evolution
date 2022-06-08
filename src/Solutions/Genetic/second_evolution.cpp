#include "GeneticSolutions.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../Initialization/Init.h"
#include "../../Termination/Terminator.h"
#include "../../Mutation/Mutation.h"
#include "../../Fitness/Fitness.h"
#include "../../Crossover/Crossover.h"
#include "../../Fix/Fix.h"
#include "../../Selection/Selection.h"
#include "../Auxiliary/Other.h"
#include "../Auxiliary/Stat.h"
#include "../../Other/PopulationSort.h"

Genome second_evolution(int num_population, int num_iterations, std::vector<Gene> &points) {
    int num_points = points.size();
    Population population = random_init(points, num_population);
    //Population population = greedy_init(points, num_population);
    std::vector<double> fit_vec = fitness(population);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    Genome best = population[best_index];
    Stat stat = Stat(num_iterations);
    Terminator terminator = Terminator(num_iterations);
    double mutation_chance = 0.1;
    //std::cout << mutation_chance << std::endl;
    //std::cout << "a\n";
    std::cout << fit_vec[best_index] << std::endl;
    while(!terminator.isSatisfied()){
        Population mutants = mutation(population, num_population);
        fit_vec = fitness(population);
        sort(population, fit_vec, true);
        //Population offspring = crossover_similar(population, fit_vec);
        //Population offspring = ordered(population);
        Population offspring = crossover_random_parents(population);
        //Population offspring = crossover_different2(population, fit_vec, 2);
        //Population offspring = crossover_random_parents(population, 2);
        fix(offspring, points, fix_greedy2);
        //std::cout << terminator.getCurIteration() << " generation\n" << print(fitness(offspring)) << '\n';
        std::vector<Population> populations = std::vector<Population> {population, offspring, mutants};
        Population united = concat(populations);
        fit_vec = fitness(united);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
            //std::cout << terminator.getCurIteration() << std::endl;
        }
        //truncation(united, num_population, fit_vec);
        //population = united;
        sort(united, fit_vec, false);
        population = rank2(united, num_population, fit_vec);
        terminator.update();
        stat.gatherAll(population, fitness(population));
    }
    //std::cout << "b\n";
    return best;
}
