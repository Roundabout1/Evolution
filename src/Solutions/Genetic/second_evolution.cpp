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
    //std::cout << print(fit_vec) << '\n';
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    GenomePoint best = population[best_index];
    //Stat stat = Stat(num_iterations);
    Terminator terminator = Terminator(num_iterations);
    //double mutation_chance = 0.1;
    //std::cout << mutation_chance << std::endl;
    //std::cout << "a\n";
    //std::cout << fit_vec[best_index] << std::endl;
    while(!terminator.isSatisfied()){
        /*int invs = std::max(1, num_population/10);
        for(int i = 0; i < invs; i++) {
            int j = getRandomNumber(0, num_population-1);
            inversion(population[j]);
        }*/
        PopulationPoint mutants;
        for(int i = 0; i < num_population; i++){
            int j = getRandomNumber(0, num_population-1);
            //mutants.push_back(randomChoice(population[j]));
            mutants.push_back(mutation(population[j]));
        }
        //fit_vec = fitness(population, isClosed, distance_measure);
        //sort(population, fit_vec, true);
        //Population offspring = crossover_similar(population, fit_vec);
        //PopulationPoint offspring = ordered(population);
        //PopulationPoint offspring = crossover_random_parents(population);
        //Population offspring = crossover_different2(population, fit_vec, 2);
        //PopulationPoint offspring = collision(population, fit_vec, isClosed, distance_measure);
        //PopulationPoint offspring = rank_fit_crossover(population, fit_vec, num_population);
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
        //fix(offspring, points);
        //std::cout << terminator.getCurIteration() << " generation\n" << print(fitness(offspring)) << '\n';
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {offspring, mutants};
        PopulationPoint united = concat(populations);
        fit_vec = fitness(united, isClosed, distance_measure);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
            //std::cout << terminator.getCurIteration() << std::endl;
            //united.push_back(randomChoice(population[getRandomNumber(0, num_population-1)]));
            //fit_vec.push_back(fitness(united[united.size()-1]));
        }/*else{
            united.push_back(best);
            fit_vec.push_back(best_fit);
        }*/
        //truncation(united, num_population, fit_vec);
        //std::cout << "uni = " << united.size() << '\n';
        tournament(united, num_population, fit_vec);
        //std::cout << "pop = " << united.size() << '\n';
        population = united;
        //sort(united, fit_vec, false);
        //population = rank2(united, num_population, fit_vec);
        terminator.update();
        //stat.gatherAll(population, fit_vec);
    }
    //std::cout << best_fit << std::endl;
    //std::cout << "b\n";
    return best;
}
