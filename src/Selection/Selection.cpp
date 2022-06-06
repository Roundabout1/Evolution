

#include <algorithm>
#include <iostream>
#include "Selection.h"
#include "../Fitness/Fitness.h"
#include "../Random/Random.h"
#include "../Solutions/Auxiliary/Prints.h"
#include "../Pathes.h"
//элитарный отбор, отбираются лучшие select особей
Population selection(Population population, int num_selected){
    std::sort(population.begin(), population.end(),[&](Genome &a, Genome &b){
        return fitness(a) < fitness(b);
    });
    population.resize(num_selected);
    return population;
}

void truncation(std::vector<std::vector<Gene>> &population, int num_selected, std::vector<double> &fit_vec) {
    std::vector<int> indexes(population.size());
    for(int i = 0; i < population.size(); i++)
        indexes[i] = i;
    std::sort(indexes.begin(), indexes.end(),[&](int &a, int &b){
        return fit_vec[a] < fit_vec[b];
    });
    Population sorted;
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

void tournament(std::vector<std::vector<Gene>> &population, int num_participated, std::vector<double> &fit_vec) {
    int num_population = population.size();
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
        std::swap(population[i], population[l]);
        std::swap(fit_vec[i], fit_vec[l]);
        int best = l;
        for(int j = i+1; j < r; j++){
            if(fit_vec[j] < fit_vec[best])
                best = j;
        }
        std::swap(population[best], population[l]);
        std::swap(fit_vec[best], fit_vec[l]);
        r = r - num_participated + 1;
        /*std::cout << l << std::endl;
        std::cout <<print(fit_vec);
        ln*/
    }
    population.resize(rounds);
    fit_vec.resize(rounds);
}

//ранговая селекция
Population rank(std::vector<std::vector<Gene>> &population, int num_selected, std::vector<double> &fit_vec) {
    int num_population = population.size();
    //здесь храняться ранги
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
    Population selected;
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
        //std::cout << l << ' ' << r << std::endl;
        if(prefix[r] - p < p - prefix[l])
            selected.push_back(population[indexes[r]]);
        else
            selected.push_back(population[indexes[l]]);
    }
    return selected;
}


