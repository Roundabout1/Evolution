#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../Gene/Gene.h"
#include "../../Initialization/Init.h"
#include "../../Termination/Terminator.h"
#include "../../Mutation/Mutation.h"
#include "../../Fitness/Fitness.h"
#include "../../Crossover/Crossover.h"
#include "../../Fix/Fix.h"
#include "../../Selection/Selection.h"

std::string print(Genome &genome){
    std::string output = "";
    for(int i = 0; i < genome.size(); i++){
        output += std::to_string(genome[i].getType()) + " ";
    }
    return output;
}

std::string print(Population &population){
    std::string output = "";
    for(int i = 0; i < population.size(); i++){
        output += print(population[i]) + "\n";
    }
    return output;
}

std::string print(std::vector<double> v){
    std::string output = "";
    for(int i = 0; i < v.size(); i++){
        output += std::to_string(v[i]) + "\n";
    }
    return output;
}

#define ln std::cout << '\n';

int main() {
    std::string const output_path = "data/output";
    std::string const file_best_solution = "best_solution.txt";
    std::string const file_fitness = "fitness.txt";
    std::string const file_fitness_stats = "fitness_stats.txt";
    std::string const file_genomes = "genomes.txt";
    std::string const conf_path = "data/input/conf.txt";
    std::string const points_path = "data/input/points.txt";
    std::string const generation_name= "generation";

    int num_cities, num_population, num_iterations;
    std::ifstream conf(conf_path);
    conf >> num_cities >> num_population >> num_iterations;
    std::cout << num_iterations << std::endl;
    conf.close();

    Genome points(num_cities);
    std::ifstream p(points_path);
    for(int i = 0; i < num_cities; i++){
        double x, y;
        p >> x >> y;
        Point point = Point(x, y);
        points[i] = Gene(i, point);
    }
    p.close();

    //создание папок и файлов с выходными данными
    std::string bat_name = "createFiles.bat";
    std::string number = std::to_string(num_iterations);
    system((bat_name + " " + output_path + " " + number +  " " + generation_name + " " +
    file_best_solution + " " + file_genomes + " " + file_fitness_stats + " " + file_fitness).c_str());

    Population population = init(points, num_population);
    print(population[0]);
    ln
    Terminator terminator = Terminator(num_iterations);
    while(!terminator.isSatisfied()){
        Population mutants = mutation(population, num_population, 1.0/num_population);
        Population offspring = crossover(population, 2, 1);
        fix(offspring, points);
        std::vector<Population> populations = std::vector<Population> {population, offspring, mutants};
        Population united = concat(populations);
        Population selected = selection(united, num_population);
        population = selected;
        terminator.update();

        std::string cur_output_path = output_path + "/" + generation_name + " " + std::to_string(terminator.getCurIteration()) + "/";

        std::ofstream out_f(cur_output_path + file_fitness);
        std::vector<double> fit_vec = fitness(population);
        out_f << print(fit_vec);
        out_f.close();

        std::ofstream out_g(cur_output_path + file_genomes);
        out_g << print(population);
        out_g.close();

        std::ofstream out_fs(cur_output_path + file_fitness_stats);
        double min = *std::min_element(fit_vec.begin(), fit_vec.end());
        double max = *std::max_element(fit_vec.begin(), fit_vec.end());
        double sum =  std::accumulate(fit_vec.begin(), fit_vec.end(),
                                                     decltype(fit_vec)::value_type(0.0));
        double mean = sum/fit_vec.size();
        out_fs << min << '\n';
        out_fs << max << '\n';
        out_fs << mean << '\n';
        out_fs.close();

        std::ofstream out_bg(cur_output_path + file_best_solution);
        out_bg << print(population[0]);
        out_bg.close();
    }
    print(population[0]);
    ln
    return 0;
}
