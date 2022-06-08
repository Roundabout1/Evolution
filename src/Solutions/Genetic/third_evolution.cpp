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
Genome mutation_based(int num_population, int num_iterations, std::vector<Gene> &points) {
    int num_points = points.size();
    Population population = greedy_init(points, num_population);
    std::vector<double> fit_vec = fitness(population);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    Genome best = population[best_index];
    //std::cout << fit_vec[0] << std::endl;
    //Stat stat = Stat(num_iterations);
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        //std::cout << terminator.getCurIteration() << std::endl;
        Population mutants = mutation(population, num_population);
        //sort(population, fit_vec, false);
        //Population offspring = multi_fit_crossover(population, fit_vec, num_population);
        //fix(offspring, points, fix_greedy2);
        //Population offspring_mutants = mutation(offspring, offspring.size());
        //std::cout << terminator.getCurIteration() << " generation\n" << print(fitness(offspring)) << '\n';
        std::vector<Population> populations = std::vector<Population> {population, mutants};
        Population united = concat(populations);
        fit_vec = fitness(united);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
            //std::cout << terminator.getCurIteration() << std::endl;
        }
        //population = rank(united, num_population, fit_vec);
        truncation(united, num_population, fit_vec);
        population = united;
        terminator.update();
        //stat.gatherAll(population, fitness(population));
    }
    //std::cout << "b\n";
    return best;
}
