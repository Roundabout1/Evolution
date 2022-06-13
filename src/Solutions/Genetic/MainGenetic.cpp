#include <vector>
#include <algorithm>
#include <iostream>
#include "../../Gene/GenePoint.h"
#include "../../Fitness/Fitness.h"
#include "../Auxiliary/Stat.h"
#include "../Auxiliary/ReadData.h"
#include "GeneticSolutions.h"
#include "../Non-genetic/nearest.h"

int main() {
    int num_population, num_iterations;
    bool isClosed;
    measures distance_measure;
    GenomePoint points;
    readData(num_population, num_iterations, points, isClosed, distance_measure);
    //GenomePoint result = first_evolution(num_population, num_iterations, points, isClosed, distance_measure);
    //GenomePoint result = second_evolution(num_population, num_iterations, points, isClosed, distance_measure);
    //GenomePoint result = k_clusters_evolution(num_population, num_iterations, points, isClosed, distance_measure);
    //GenomePoint result = mutation_based(num_population, num_iterations, points, isClosed, distance_measure);
    //GenomePoint result = nearest(points, isClosed, distance_measure);
    GenomePoint result = advanced_k_clusters(num_population, num_iterations, points, isClosed, distance_measure);
    Stat::gatherGenome(result);
    Stat::gatherFitness(fitness(result, isClosed, distance_measure));
    return 0;
}
