#include "second_evolution.h"
#include <vector>
#include <algorithm>
#include "../../../Initialization/Init.h"
#include "../../../Termination/Terminator.h"
#include "../../../Mutation/Mutation.h"
#include "../../../Fitness/Fitness.h"
#include "../../../Crossover/Crossover.h"
#include "../../../Fix/Fix.h"
#include "../../../Selection/Selection.h"
#include "../../Auxiliary/Other.h"
#include "second_evolution.h"
Genome second_evolution(int num_population, int num_iterations, std::vector<Gene> &points) {
    int num_points = points.size();
    Population population = init(points, num_population);
    std::vector<double> fit_vec = fitness(population);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    Genome best = population[best_index];
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        Population mutants = mutation(population, num_population, 2.0/num_points);
        Population offspring = crossover(population);
        fix(offspring, points);
        std::vector<Population> populations = std::vector<Population> {mutants, offspring};
        Population united = concat(populations);
        fit_vec = fitness(united);
        selection(united, num_population, fit_vec);
        population = united;
        int cur_best = getBest(population, fit_vec);
        if(fit_vec[cur_best] < best_fit){
            best = population[cur_best];
            best_fit = fit_vec[cur_best];
        }
        terminator.update();
        //stat.gatherAll(population, fitness(population));
    }
    return best;
}
