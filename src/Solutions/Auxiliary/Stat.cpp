#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <vector>
#include "Stat.h"
#include "Other.h"
#include "../../Other/FileOperations.h"
Stat::Stat(int numIterations) : num_iterations(numIterations) {
    cur_iteration = 0;
    createFolders(output_path, generation_name, numIterations);
}

void Stat::gatherAll(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec) {
    cur_output_path = output_path + "/" + generation_name + " " + std::to_string(cur_iteration+1) + "/";
    gatherGenomes(population);
    gatherBestGenome(population, fit_vec);
    gatherFitness(fit_vec);
    gatherFitnessStats(fit_vec);
    gatherConvergence(population);
    cur_iteration++;
}

void Stat::gatherGenomes(std::vector<std::vector<GenePoint>> &population) {
    std::ofstream out_g(cur_output_path + file_genomes);
    out_g << print(population);
    out_g.close();
}

void Stat::gatherBestGenome(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec) {
    std::ofstream out(cur_output_path + file_best_solution);
    out << print(population[getBest(population, fit_vec)]);
    out.close();
}

void Stat::gatherFitness(std::vector<double> &fit_vec) {
    std::ofstream out_f(cur_output_path + file_fitness);
    out_f << print(fit_vec);
    out_f.close();
}

void Stat::gatherFitnessStats(std::vector<double> &fit_vec) {
    std::ofstream out(cur_output_path + file_fitness_stats);
    double min = *std::min_element(fit_vec.begin(), fit_vec.end());
    double max = *std::max_element(fit_vec.begin(), fit_vec.end());
    double sum =  0.0;
    for(auto i : fit_vec)
        sum += i;
    double mean = sum/fit_vec.size();
    out << min << '\n';
    out << max << '\n';
    out << mean << '\n';
    out.close();
}

void Stat::gatherConvergence(std::vector<std::vector<GenePoint>> &population) {
    double convergence = 0.0;
    for(int i = 0; i < population.size() - 1; i++){
        for(int j = i + 1; j < population.size(); j++){
            for(int g = 0; g < population[i].size(); g++){
                int overlap = 0;
                if(population[i][g].getType() == population[j][g].getType()){
                    overlap++;
                }
                convergence += 2.0*((double)overlap/(double) population[i].size());
            }
            //std::cout << convergence << std::endl;
        }
    }
    convergence = convergence/(population.size()*population.size());
    std::ofstream out(cur_output_path + file_convergence);
    out << convergence;
    out.close();
}


void Stat::gatherGenome(std::vector<GenePoint> &genome) {
    std::ofstream out(solution_path);
    out << print(genome);
    out.close();
}

void Stat::gatherFitness(double fitness_value) {
    std::ofstream out(fitness_value_path);
    out << fitness_value;
    out.close();
}
