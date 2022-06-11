#include <vector>
#include <algorithm>
#include "../../Gene/GenePoint.h"
#include "../../Fitness/Fitness.h"
#include "../Auxiliary/Stat.h"
#include "../Auxiliary/ReadData.h"
#include "GeneticSolutions.h"
#include "../Non-genetic/nearest.h"

int main() {
    int num_population, num_iterations;
    GenomePoint points;
    readData(num_population, num_iterations, points);
    //Genome result = first_evolution(num_population, num_iterations, points);
    //Genome result = second_evolution(num_population, num_iterations, points);
    GenomePoint result = k_clusters_evolution(num_population, num_iterations, points);
    //Genome result = mutation_based(num_population, num_iterations, points);
    //Genome result = nearest(points);
    Stat::gatherGenome(result);
    Stat::gatherFitness(fitness(result));
    return 0;
}
