#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "../genome/genome.hpp"
//популяция - это множество генов
class Population{
private:
    std::vector<Genome> genomes;
public:
    Population();
    Population(int num_population, int num_genes);
    Genome get(int index);
    size_t size();
    void set(int index, Genome genome);
    void merge(Population other);
};
#endif