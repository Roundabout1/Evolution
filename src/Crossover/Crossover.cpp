#include <iostream>
#include <algorithm>
#include "Crossover.h"
#include "../Random/Random.h"
#include "../Other/Roulette.h"
#include "../Fitness/Fitness.h"
#include "../Other/DoubleOperations.h"

//begin - минимальное количество генов, которые гарантированно достанутся первому родителю
//end - второму
PopulationPoint crossover_random_parents(std::vector<std::vector<GenePoint>> &population, int k, int begin, int end) {
    int num_population = population.size();
    PopulationPoint offspring;
    for(int p1 = 0; p1 < num_population; p1++){
        int p2 = getRandomNumber(0, num_population - 1);
        if(p1 == p2)
            p2 = (p1 + 1)%num_population;
        PopulationPoint children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

PopulationPoint crossover(std::vector<GenePoint> &parent1, std::vector<GenePoint> &parent2, int k, int begin, int end) {
    int num_genes = parent1.size();
    PopulationPoint offspring(2, GenomePoint (num_genes));
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

PopulationPoint uniform_crossover(std::vector<std::vector<GenePoint>> &population) {
    int num_population = population.size();
    PopulationPoint offspring;
    for (int p1 = 0; p1 < num_population; p1++) {
        int p2 = getRandomNumber(0, num_population - 1);
        if (p1 == p2)
            p2 = (p1 + 1) % num_population;
        PopulationPoint children = uniform_crossover(population[p1], population[p2]);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}
PopulationPoint uniform_crossover(std::vector<GenePoint> &parent1, std::vector<GenePoint> &parent2){
    int num_genes = parent1.size();
    PopulationPoint offspring(2, GenomePoint (num_genes));

    for (int i = 0; i < num_genes; i++) {
        bool turn = getRandomNumber(0, 1);
        offspring[0][i] = (turn) ? parent1[i] : parent2[i];
        offspring[1][i] = (turn) ? parent2[i] : parent1[i];
    }
    return offspring;
}

PopulationPoint crossover_similar(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec, int k, int begin, int end) {
    int num_population = population.size();
    PopulationPoint offspring;
    for (int p1 = 0; p1 < num_population; p1+=2) {
        int p2 = p1 + 1;
        if(p2 >= num_population)
            p2 = std::max(0, num_population-2);
        PopulationPoint children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

PopulationPoint crossover_different(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec, int k, int begin, int end) {
    int num_population = population.size();
    PopulationPoint offspring;
    for (int p1 = 0; p1 < num_population/2; p1++) {
        int p2 = num_population-1-p1;
        PopulationPoint children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}
PopulationPoint crossover_different2(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec, int k, int begin, int end) {
    int num_population = population.size();
    PopulationPoint offspring;
    for (int p1 = 0; p1 < num_population; p1++) {
        int p2 = 0.0;
        if(p1 < num_population/2){
            p2 = num_population - 1;
        }else{
            p2 = 0;
        }
        PopulationPoint children = crossover(population[p1], population[p2], k, begin, end);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}
//population отсортирован по функции приспособленности
PopulationPoint multi_fit_crossover(PopulationPoint &population, std::vector<double> &fit_vec, int num_offspring) {
    std::vector<int> rank = get_rank(fit_vec);
    std::vector<double> prefix = get_prefix(rank);
    PopulationPoint offspring(num_offspring, GenomePoint(population[0].size()));
    for(int i = 0; i < num_offspring; i++){
        for(int j = 0; j < offspring[i].size(); j++){
            int k = roulette(prefix);
            //std::cout << k << std::endl;
            offspring[i][j] = population[k][j];
        }
    }
    return offspring;
}

PopulationPoint rank_fit_crossover(PopulationPoint &population, std::vector<double> &fit_vec, int num_pairs_offspring){
    std::vector<int> rank = get_rank(fit_vec);
    std::vector<double> prefix = get_prefix(rank);
    PopulationPoint offspring;
    for(int i = 0; i < num_pairs_offspring; i++){
        int k = roulette(prefix);
        if(k == i)
            k = (k+1)%population.size();
        PopulationPoint children = crossover(population[i], population[k]);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

PopulationPoint collision(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec) {
    PopulationPoint offspring;
    int num_population = population.size();
    for(int p1 = 0; p1 < num_population; p1++){
        int p2 = getRandomNumber(0, num_population - 1);
        if(p1 == p2)
            p2 = (p1 + 1)%num_population;
        //Population children = collision(population[p1], population[p2], getRandomNumber(1.0, fit_vec[p1]), getRandomNumber(1.0, fit_vec[p2]));
        PopulationPoint children = collision(population[p1], population[p2], 1.0, 1.0);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

PopulationPoint collision(std::vector<GenePoint> &g1, std::vector<GenePoint> &g2, double velocity1, double velocity2) {
    velocity2 = -velocity2;
    PopulationPoint offspring(2, GenomePoint(g1.size()));
    for(int i = 0; i < g1.size(); i++){
        double mass1 = get_distance(g1, i);
        double mass2 = get_distance(g2, i);
        double sum = mass1 + mass2;
        double dif = mass1 - mass2;
        double v1 = dif/sum*velocity1 + 2*mass2/sum*velocity2;
        double v2 = 2*mass1/sum*velocity1 - dif/sum*velocity2;
        //std::cout << sum << ' ' <<dif << '\n';
        //std::cout << mass1 << ' ' << mass2 << '\n';
        if(v1 < 0.0 || isEqual(v1, 0)){
            offspring[0][i] = g1[i];
        }else{
            offspring[0][i] = g2[0];
        }
        if(v2 > 0.0 || isEqual(v1, 0)){
            offspring[1][i] = g2[i];
        }else{
            offspring[1][i] = g1[0];
        }
    }
    return offspring;
}

PopulationPoint ordered(std::vector<std::vector<GenePoint>> &population) {
    int num_population = population.size();
    PopulationPoint offspring;
    for(int p1 = 0; p1 < num_population; p1++){
        int p2 = getRandomNumber(0, num_population - 1);
        if(p1 == p2)
            p2 = (p1 + 1)%num_population;
        //Population children = collision(population[p1], population[p2], getRandomNumber(1.0, fit_vec[p1]), getRandomNumber(1.0, fit_vec[p2]));
        PopulationPoint children = ordered(population[p1], population[p2]);
        offspring.push_back(children[0]);
        offspring.push_back(children[1]);
    }
    return offspring;
}

PopulationPoint ordered(std::vector<GenePoint> &g1, std::vector<GenePoint> &g2) {
    PopulationPoint offspring(2, GenomePoint(g1.size()));
    int l = getRandomNumber(1, g1.size()-2);
    int r = getRandomNumber(1, g1.size()-2);
    if(l == r)
        r = (l+1)%g1.size();
    if(l > r)
        std::swap(l, r);
    std::vector<bool> used1(g1.size()), used2(g2.size());
    for(int i = l; i <= r; i++){
        offspring[0][i] = g1[i];
        offspring[1][i] = g2[i];
        used1[g1[i].getType()] = 1;
        used2[g2[i].getType()] = 1;
    }
    GenomePoint unused1, unused2;
    for(int i = 0; i < g1.size(); i++){
        if(!used1[g2[i].getType()]){
            unused1.push_back(g2[i]);
        }
        if(!used2[g1[i].getType()]){
            unused2.push_back(g1[i]);
        }
    }
    //std::cout << "l r " << l << ' ' << r << '\n';
    //std::cout << "unused " << unused1.size() << '\n';
    for(int i = 0, j = 0; i < g1.size(); i++){
        //std::cout << i << ' ' << j << std::endl;
        offspring[0][i] = unused1[j];
        offspring[1][i] = unused2[j];
        j++;
        if(i == l-1)
            i = r;
    }
    return offspring;
}

PopulationCluster uniform(std::vector<GeneCluster> &p1, std::vector<GeneCluster> &p2) {
    PopulationCluster offspring(4);
    std::vector<int> cluster_order1(p1.size()), cluster_order2(p2.size());
    //bool isEq = true;
    for(int i = 0; i < p1.size(); i++){
        cluster_order1[p1[i].getType()] = i;
        cluster_order2[p2[i].getType()] = i;
        /*if(p1[i].getType() != p2[i].getType())
            isEq = false;*/
    }
    /*if(isEq){
        int i = getRandomNumber(0, p2.size()-1);
        int j = (i+1)%p2.size();
        std::swap(cluster_order1[i], cluster_order2[j]);
    }*/
    for(int i = 0; i < 4; i+=2) {
        for (int j = 0; j < p1.size(); j++) {
            int id1;
            int id2;
            if(i < 2){
                id1 = j;
                id2 = cluster_order2[p1[id1].getType()];
            }else{
                id2 = j;
                id1 = cluster_order1[p2[id2].getType()];
            }
            if (getRandomNumber(0, 1)) {
                offspring[i].push_back(p1[id1]);
                offspring[i+1].push_back(p2[id2]);
            }else{
                offspring[i].push_back(p2[id2]);
                offspring[i+1].push_back(p1[id1]);
            }
        }
    }
    return offspring;
}
