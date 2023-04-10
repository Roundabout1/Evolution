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
#include "../../Distance_measures.h"
#include "../../Other/DoubleOperations.h"

GenomePoint second_evolution(int num_population, int num_iterations, std::vector<GenePoint> &points, bool isClosed, measures distance_measure) {
    int num_points = points.size();
    PopulationPoint population = random_init(points, num_population);
    //PopulationPoint population = greedy_init(points, num_population, isClosed, distance_measure);
    std::vector<double> fit_vec = fitness(population, isClosed, distance_measure);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    GenomePoint best = population[best_index];
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        PopulationPoint mutants;
        for(int i = 0; i < num_population; i++){
            int j = getRandomNumber(0, num_population-1);
            //mutants.push_back(randomChoice(population[j]));
            mutants.push_back(mutation(population[j]));
        }
        PopulationPoint offspring;
        for(int p1 = 0; p1 < num_population; p1++){
            int p2 = getRandomNumber(0, num_population - 1);
            if(p1 == p2)
                p2 = (p1 + 1)%num_population;
            if(isEqual(fit_vec[p1], fit_vec[p2]))
                population[p2] = mutation(population[p2]);
            PopulationPoint children = crossover(population[p1], population[p2]);
            offspring.push_back(children[0]);
            offspring.push_back(children[1]);
        }
        fix(offspring, points, fix_greedy2, isClosed, distance_measure);
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {offspring, mutants};
        PopulationPoint united = concat(populations);
        fit_vec = fitness(united, isClosed, distance_measure);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
        }
        tournament(united, num_population, fit_vec);
        population = united;
        terminator.update();
    }
    return best;
}
