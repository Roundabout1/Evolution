#include <algorithm>
#include <iostream>
#include "Selection.h"
#include "../Fitness/Fitness.h"
#include "../Random/Random.h"
#include "../Solutions/Auxiliary/Prints.h"
#include "../Pathes.h"
#include "../Other/Roulette.h"

void truncation(std::vector<std::vector<GenePoint>> &population, int num_selected, std::vector<double> &fit_vec) {
    std::vector<int> indexes(population.size());
    for(int i = 0; i < population.size(); i++)
        indexes[i] = i;
    std::sort(indexes.begin(), indexes.end(),[&](int &a, int &b){
        return fit_vec[a] < fit_vec[b];
    });
    PopulationPoint sorted;
    std::vector<double> sorted_fit;
    for(int i = 0; i < population.size(); i++){
        sorted.push_back(population[indexes[i]]);
        sorted_fit.push_back(fit_vec[indexes[i]]);
    }
    population = sorted;
    fit_vec = sorted_fit;
    population.resize(num_selected);
    fit_vec.resize(num_selected);
}

void tournament(std::vector<std::vector<GenePoint>> &population, int num_selected, std::vector<double> &fit_vec) {
    int num_population = population.size();
    int num_participated = num_population/num_selected;
    int rounds = num_population/num_participated;
    if(num_population%num_participated != 0)
        rounds++;
    for(int l = 0, r = num_population-1; l < rounds; l++){
        int i = r;
        while(l <= i && r - i < num_participated){
            int j = getRandomNumber(l, i);
            std::swap(population[j], population[i]);
            std::swap(fit_vec[j], fit_vec[i]);
            i--;
        }
        i++;
        int best = i;
        for(int j = i+1; j <= r; j++){
            if(fit_vec[j] < fit_vec[best])
                best = j;
        }
        std::swap(population[best], population[i]);
        std::swap(fit_vec[best], fit_vec[i]);
        std::swap(population[l], population[i]);
        std::swap(fit_vec[l], fit_vec[i]);
        r = i;
    }
    population.resize(rounds);
    fit_vec.resize(rounds);
}

//ранговая селекция
PopulationPoint rank(std::vector<std::vector<GenePoint>> &population, int num_selected, std::vector<double> &fit_vec) {
    int num_population = population.size();
    //здесь хранятся ранги
    std::vector<int> indexes(num_population);
    for(int i = 0; i < num_population; i++)
        indexes[i] = i;
    //Определеяет ранги благодаря сортировке в убывающем порядке
    std::sort(indexes.begin(), indexes.end(),[&](int &a, int &b){
        return fit_vec[a] > fit_vec[b];
    });
    //префикс сумма вероятностей быть выбранным
    std::vector<double> prefix(num_population);
    double sum = num_population*(num_population+1)/2;
    prefix[0] = 1.0 / sum;
    for(int i = 1; i < num_population; i++) {
        prefix[i] = prefix[i - 1] + (i+1) / sum;
    }
    PopulationPoint selected;
    for(int i = 0; i < num_selected; i++){
        //программа выбирает случайное число в диапазоне от 0 до 1,
        //после чего при помощи бинарного поиска она находит наиболее близкое к загаданному числу элемент массива prefix
        //и выбирает соответствующее по рангу число
        double p = getRandomNumber(0.0, 1.0);
        int l = 0, r = num_population;
        while(l < r - 1){
            int m = (l+r)/2;
            if(prefix[m] < p){
                l = m;
            }else{
                r = m;
            }
        }
        if(prefix[r] - p < p - prefix[l])
            selected.push_back(population[indexes[r]]);
        else
            selected.push_back(population[indexes[l]]);
    }
    return selected;
}

PopulationPoint rank2(std::vector<std::vector<GenePoint>> &population, int num_selected, std::vector<double> &fit_vec) {
    std::vector<int> rank = get_rank(fit_vec);
    std::vector<double> prefix = get_prefix(rank);
    PopulationPoint selected;
    for(int i = 0; i < num_selected; i++){
        int p = roulette(prefix);
        selected.push_back(population[p]);
    }
    return selected;
}

//турнирная селекция
PopulationCluster tournament(std::vector<std::vector<GeneCluster>> &population, int num_selected,
                             std::vector<double> &fit_vec) {
    int num_population = population.size();
    int num_participants = num_population / num_selected;
    int rounds = num_population / num_participants;
    if(num_population % num_participants != 0)
        rounds++;
    for(int l = 0, r = num_population-1; l < rounds; l++){
        int i = r;
        while(l <= i && r - i < num_participants){
            int j = getRandomNumber(l, i);
            std::swap(population[j], population[i]);
            std::swap(fit_vec[j], fit_vec[i]);
            i--;
        }
        i++;
        int best = i;
        for(int j = i+1; j <= r; j++){
            if(fit_vec[j] < fit_vec[best])
                best = j;
        }
        std::swap(population[best], population[i]);
        std::swap(fit_vec[best], fit_vec[i]);
        std::swap(population[l], population[i]);
        std::swap(fit_vec[l], fit_vec[i]);
        r = i;
    }
    population.resize(num_selected);
    fit_vec.resize(num_selected);
    return population;
}

