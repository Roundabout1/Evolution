#include <iostream>
#include <algorithm>
#include "Crossover.h"
#include "../Random/Random.h"
#include "../Other/Roulette.h"

//begin - минимальное количество генов, которые гарантированно достанутся первому родителю
//end - второму
Population crossover_random_parents(std::vector<std::vector<Gene>> &population, int k, int begin, int end) {
    int num_population = population.size();
    Population offspring;
    for(int p1 = 0; p1 < num_population; p1++){
        int p2 = getRandomNumber(0, num_population - 1);
        if(p1 == p2)
            p2 = (p1 + 1)%num_population;
        Population children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

Population crossover(std::vector<Gene> &parent1, std::vector<Gene> &parent2, int k, int begin, int end) {
    int num_genes = parent1.size();
    Population offspring(2, Genome (num_genes));
    std::vector<int> cross_points;
    for(int i = 0; i < k; i++){
        cross_points.push_back(getRandomNumber(begin, num_genes - 1 - end));
    }
    std::sort(cross_points.begin(), cross_points.end(), [](int &a, int &b){return a < b;});
    int cur_cross = 0;
    bool turn = 1;
    //std::cout << cross_points[cur_cross] << std::endl;
    for (int i = 0; i < num_genes; i++) {
        if (cur_cross < k && i >= cross_points[cur_cross]) {
            //std::cout << cross_points[cur_cross] << std::endl;
            turn = !turn;
            cur_cross++;
        }
        offspring[0][i] = (turn) ? parent1[i] : parent2[i];
        offspring[1][i] = (turn) ? parent2[i] : parent1[i];
    }
    return offspring;
}

Population uniform_crossover(std::vector<std::vector<Gene>> &population) {
    int num_population = population.size();
    Population offspring;
    for (int p1 = 0; p1 < num_population; p1++) {
        int p2 = getRandomNumber(0, num_population - 1);
        if (p1 == p2)
            p2 = (p1 + 1) % num_population;
        Population children = uniform_crossover(population[p1], population[p2]);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}
Population uniform_crossover(std::vector<Gene> &parent1, std::vector<Gene> &parent2){
    int num_genes = parent1.size();
    Population offspring(2, Genome (num_genes));

    for (int i = 0; i < num_genes; i++) {
        bool turn = getRandomNumber(0, 1);
        offspring[0][i] = (turn) ? parent1[i] : parent2[i];
        offspring[1][i] = (turn) ? parent2[i] : parent1[i];
    }
    return offspring;
}

Population crossover_similar(std::vector<std::vector<Gene>> &population, std::vector<double> &fit_vec, int k, int begin, int end) {
    int num_population = population.size();
    Population offspring;
    for (int p1 = 0; p1 < num_population; p1+=2) {
        int p2 = p1 + 1;
        if(p2 >= num_population)
            p2 = std::max(0, num_population-2);
        Population children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

Population crossover_different(std::vector<std::vector<Gene>> &population, std::vector<double> &fit_vec, int k, int begin, int end) {
    int num_population = population.size();
    Population offspring;
    for (int p1 = 0; p1 < num_population/2; p1++) {
        int p2 = num_population-1-p1;
        Population children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}
Population crossover_different2(std::vector<std::vector<Gene>> &population, std::vector<double> &fit_vec, int k, int begin, int end) {
    int num_population = population.size();
    Population offspring;
    for (int p1 = 0; p1 < num_population; p1++) {
        int p2 = 0.0;
        if(p1 < num_population/2){
            p2 = num_population - 1;
        }else{
            p2 = 0;
        }
        Population children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}
//population отсортирован по функции приспособленности
Population multi_fit_crossover(Population &population, std::vector<double> &fit_vec, int num_offspring) {
    std::vector<int> rank = get_rank(fit_vec);
    std::vector<double> prefix = get_prefix(rank);
    Population offspring(num_offspring, Genome(population[0].size()));
    for(int i = 0; i < num_offspring; i++){
        for(int j = 0; j < offspring[i].size(); j++){
            int k = roulette(prefix);
            //std::cout << k << std::endl;
            offspring[i][j] = population[k][j];
        }
    }
    return offspring;
}

