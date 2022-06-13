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
GenomePoint mutation_based(int num_population, int num_iterations, std::vector<GenePoint> &points, bool  isClosed, measures distance_measure) {
    int num_points = points.size();
    PopulationPoint population = greedy_init(points, num_population, isClosed, distance_measure);
    std::vector<double> fit_vec = fitness(population, isClosed, distance_measure);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    GenomePoint best = population[best_index];
    //std::cout <<"before " << best_fit << std::endl;
    //Stat stat = Stat(num_iterations);
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        //std::cout << terminator.getCurIteration() << std::endl;
        PopulationPoint mutants = mutation(population, num_population);
        //sort(population, fit_vec, false);
        //Population offspring = multi_fit_crossover(population, fit_vec, num_population);
        //fix(offspring, points, fix_greedy2);
        //Population offspring_mutants = mutation(offspring, offspring.size());
        //std::cout << terminator.getCurIteration() << " generation\n" << print(fitness(offspring)) << '\n';
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {population, mutants};
        PopulationPoint united = concat(populations);
        fit_vec = fitness(united, isClosed, distance_measure);
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
    std::cout << best_fit << std::endl;
    return best;
}
