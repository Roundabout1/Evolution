#include <iostream>
#include <processthreadsapi.h>
#include "Gene/Gene.h"
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

int main(){
    int num_population, num_iterations;
    Genome points;
    readData(num_population, num_iterations, points);
    Genome n = nearest(points);
    double fit = fitness(n);
    std::cout << print(n);
    ln
    std::cout << fit;
    return 0;
}
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