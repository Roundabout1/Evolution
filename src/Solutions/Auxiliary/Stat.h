#ifndef EVOLUTIONALGORITHM_STAT_H
#define EVOLUTIONALGORITHM_STAT_H
#include "Prints.h"
#include "../../Pathes.h"

class Stat {
private:
    int num_iterations;
    //int num_cities;
    //int num_population;
    int cur_iteration;
    std::string cur_output_path="";
public:
    Stat(int num_cities, int num_population, int num_iterations);

    Stat(int numIterations);

    void gatherAll(Population &population, std::vector<double> fit_vec);
    void gatherGenomes(Population &population);
    void gatherBestGenome(Population &population, std::vector<double> &fit_vec);
    void gatherFitness(std::vector<double> &fit_vec);
    void gatherFitnessStats(std::vector<double> &fit_vec);
    void gatherConvergence(Population &population);

    static void gatherGenome(Genome &genome);
    static void gatherFitness(double fitness_value);
};


#endif //EVOLUTIONALGORITHM_STAT_H
