#include <iostream>
#include <processthreadsapi.h>
#include <memory>
#include "Gene/GenePoint.h"
#include "Initialization/Init.h"
#include "Crossover/Crossover.h"
#include "Other/FileOperations.h"
#include "Solutions/Auxiliary/ReadData.h"
#include "Solutions/Auxiliary/Prints.h"
#include "Solutions/Non-genetic/nearest.h"
#include "Selection/Selection.h"
#include "Fitness/Fitness.h"
#include "Mutation/Mutation.h"
#include "Other/PopulationSort.h"
#include "Other/Roulette.h"
#include "Fix/Fix.h"
#include "K-clusters/k-clusters.h"
#include "Solutions/Genetic/GeneticSolutions.h"
void g(std::vector<Gene *> &gene){
    std::cout << gene[0]->getType();
}
int main(){
    GenomePoint points;
    int num_population, num_iterations;
    readData(num_population, num_iterations, points);
    //k_clusters_evolution(num_population, num_iterations, points);
    std::cout << print(points);
    ln
    //advanced_k_clusters(num_population, num_iterations, points);
    /*PopulationPoint p = clusterGA(num_iterations, num_population, points);
    std::cout << print(p) << '\n';
    std::cout << print(fitness(p));*/
    advanced_k_clusters(num_population, num_iterations, points);
    /*inversion(points);
    std::cout << print(points);
    ln
    std::vector<Gene *> ge;
    ge.push_back(&points[0]);
    g(ge);
    points[0].setType(-1);
    g(ge);*/
    return 0;
}
/*Genome points;
   int num_population, num_iterations;
   readData(num_population, num_iterations, points);
   int k = std::round(std::sqrt(points.size()) + 0.5);
   std::vector<int> cluster = k_means(points, k, 10);
   std::ofstream c("data/clusters.txt");
   for(auto i : cluster)
       c << i << ' ';
   c.close();
   std::cout << k << std::endl;*/
/*int num_population, num_iterations;
Genome points;
readData(num_population, num_iterations, points);
Genome n = mutation(points, 1.0);
Genome m = mutation(points, 1.0);
double fit = fitness(n);
double fit2 = fitness(m);
std::cout << print(n) << '\n' << print(m) << '\n';
std::cout << fit << ' ' << fit2 << '\n';
//Population c = collision(n, m, getRandomNumber(1.0, fit), getRandomNumber(1.0, fit2));
Population c = ordered(n, m);
std::cout << print(c) << std::endl;
fix(c, points, fix_greedy2);
std::cout << print(c) << std::endl;
std::vector<double> fit_vec = fitness(c);
std::cout << print(fit_vec) << std::endl;*/
/*std::cout << print(ini);
ln

std::vector<double> fit_vec = fitness(ini);
std::cout << print(fit_vec);
ln
//tournament(ini, 2, fit_vec);
ini = rank(ini, 10, fit_vec);
std::cout << print(ini);
ln
std::cout << print(fitness(ini));*/
//STARTUPINFO info={sizeof(info)};
//PROCESS_INFORMATION processInfo;
//CreateProcess(NULL, "first_solution", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
//copyFileTo(solution_path, tests_path+"/solution_copy.txt");
//std::cout << ("copy " + solution_path + " " + tests_path).c_str();
//system(("copy " + solution_path + " " + tests_path).c_str());
/*int num_population, num_iterations;
Genome points;
readData(num_population, num_iterations, points);
Population ini = init(points, 3);
Genome nea = nearest(points);

std::cout << print(ini);
ln
std::vector<double> fit_vec = fitness(ini);
std::cout << print(fit_vec);
ln
ini = rank(ini, 1, fit_vec);
std::cout << print(ini);
ln
std::cout << print(fitness(ini));*/