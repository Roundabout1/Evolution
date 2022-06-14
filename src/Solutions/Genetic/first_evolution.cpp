#include "GeneticSolutions.h"
#include <vector>
#include "../../Other/Point.h"
#include "../../Gene/GenePoint.h"
#include "../../Termination/Terminator.h"
#include "../../Crossover/Crossover.h"
#include "../../Fix/Fix.h"
#include "../../Selection/Selection.h"
#include "../../Mutation/Mutation.h"
#include "../../Initialization/Init.h"
#include "../../Fitness/Fitness.h"
#include "../Auxiliary/Stat.h"

GenomePoint first_evolution(int num_population, int num_iterations, GenomePoint &points, bool  isClosed, measures distance_measure){
    int num_points = points.size();
    PopulationPoint population = random_init(points, num_population);
    Stat stat = Stat(num_iterations);
    //double best_fit = fitness(population[0]);
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        PopulationPoint mutants = mutation(population, num_population, 2.0 / num_points);
        PopulationPoint offspring = crossover_random_parents(population);
        fix(offspring, points);
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {offspring, mutants};
        PopulationPoint united = concat(populations);
        //если предпосчитать fit_vec, то вычисления идут примерно в два раза быстрее
        std::vector<double> fit_vec = fitness(united, isClosed, distance_measure);
        //population = rank(united, num_population, fit_vec);
        tournament(united, num_population, fit_vec);
        //truncation(united, num_population, fit_vec);
        population = united;
        terminator.update();
        fit_vec = fitness(population, isClosed, distance_measure);
        stat.gatherAll(population, fit_vec);
    }
    return population[0];
}
