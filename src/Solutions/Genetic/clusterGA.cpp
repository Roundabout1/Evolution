#include "GeneticSolutions.h"
#include "../../Selection/Selection.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../Initialization/Init.h"
#include "../../Termination/Terminator.h"
#include "../../Mutation/Mutation.h"
#include "../../Fitness/Fitness.h"
#include "../../Crossover/Crossover.h"
#include "../../Fix/Fix.h"
#include "../Auxiliary/Other.h"
#include "../Auxiliary/Stat.h"
#include "../../Other/PopulationSort.h"
#include "../../Other/DoubleOperations.h"
#include "../Non-genetic/nearest.h"

GenomePoint clusterGA(int num_population, int num_iterations, GenomePoint &points, bool isClosed, measures distance_measure, PopulationPoint &init_population){
    if(points.size() <= 2){
        return points;
    }
    PopulationPoint population = init_population;
    while(population.size() < num_population){
        int j = getRandomNumber(0, population.size()-1);
        population.push_back(mutation(population[j]));
    }
    std::vector<double> fit_vec = fitness(population, isClosed, distance_measure);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    GenomePoint best = population[best_index];
    Terminator terminator = Terminator(num_iterations);
    Stat stat = Stat(num_iterations);
    while(!terminator.isSatisfied()){
        int invs = std::max(1, num_population/10);
        for(int i = 0; i < invs; i++) {
            int j = getRandomNumber(0, num_population-1);
            inversion(population[j]);
        }
        PopulationPoint mutants;
        for(int i = 0; i < num_population; i++){
            int j = getRandomNumber(0, num_population-1);
            mutants.push_back(randomChoice(population[j]));
        }
        
        PopulationPoint offspring;
        for(int i = 0; i < num_population; i++){
            int j = getRandomNumber(0, num_population-1);
            if(i == j){
                j = (i+1)%num_population;
            }
            
            if(isEqual(fit_vec[i], fit_vec[j])){
                population[j] = randomChoice(population[j]);
                fit_vec[j] = fitness(population[j], isClosed, distance_measure);
                
            }
           
            PopulationPoint off = ordered(population[i], population[j]);
            offspring.push_back(off[0]);
            offspring.push_back(off[1]);
        }
       
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {offspring, mutants};
        PopulationPoint united = concat(populations);
        fit_vec = fitness(united, isClosed, distance_measure);
        tournament(united, num_population, fit_vec);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
            std::cout << terminator.getCurIteration() << std::endl;
        }else{
            int i = getRandomNumber(0, united.size()-1);
            if(i == cur_best)
                i = (i + 1)%united.size();
            fit_vec[i] = best_fit;
            united[i] = best;
        }
        population = united;
       
        std::vector<double> fitn = fitness(population, isClosed, distance_measure);
        
        stat.gatherAll(population, fitn);
        
        terminator.update();
    }
    return best;
}
PopulationPoint clusterGA(int num_population, int num_iterations, GenomePoint &points, bool  isClosed, measures distance_measure){
    if(points.size() <= 2){
        PopulationPoint res;
        res.push_back(points);
        return res;
    }
    PopulationPoint population = greedy_init(points, num_population, isClosed, distance_measure);
    std::vector<double> fit_vec = fitness(population, isClosed, distance_measure);
    int best_index = getBest(population, fit_vec);
    double best_fit = fit_vec[best_index];
    GenomePoint best = population[best_index];
    Terminator terminator = Terminator(num_iterations);
    
    while(!terminator.isSatisfied()){
        int invs = std::max(1, num_population/10);
        for(int i = 0; i < invs; i++) {
            int j = getRandomNumber(0, num_population-1);
            inversion(population[j]);
        }
        PopulationPoint mutants;
        for(int i = 0; i < num_population; i++){
            int j = getRandomNumber(0, num_population-1);
            mutants.push_back(randomChoice(population[j]));
        }
        PopulationPoint offspring = crossover_random_parents(population);
        fix(offspring, points, fix_greedy_left, isClosed, distance_measure);
        std::vector<PopulationPoint> populations = std::vector<PopulationPoint> {offspring, mutants};
        PopulationPoint united = concat(populations);
        fit_vec = fitness(united, isClosed, distance_measure);
        int cur_best = getBest(united, fit_vec);
        bool isProgressed = fit_vec[cur_best] < best_fit;
        if(isProgressed) {
            best = united[cur_best];
            best_fit = fit_vec[cur_best];
        }
        //на последней итерации отбираются только лучшие решения
        if(terminator.getCurIteration() + 1 == terminator.getMaxIterations()){
            truncation(united, num_population, fit_vec);
        }else{
            tournament(united, num_population, fit_vec);
        }
        population = united;
        terminator.update();
       
    }
    population.push_back(best);
    fit_vec.push_back(best_fit);
    //удаление дубликаторв
    int r = population.size();
    for(int i = 0; i < r - 1; i++){
        int j = i + 1;
        while(j < r){
            if(isEqual(fit_vec[i], fit_vec[j])){
                std::swap(population[j], population[r-1]);
                std::swap(fit_vec[j], fit_vec[r-1]);
                r--;
            }else{
                j++;
            }
        }
    }
    if(r != population.size())
        population.resize(r);
    return population;
}