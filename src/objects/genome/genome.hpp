#ifndef GENOME_H
#define GENOME_H
#include "../gen/gen.hpp"
#include "../../random/random.hpp"
#include <vector>
#include <string>
#include <algorithm>
class Genome{

private:
    //хромосома
    std::vector <Gen> chrom;

public:
    Genome();

    Genome(int num_genes);

    Gen getGen(int i);
    void setGen(int i, Gen gen);
    int size();
    std::string toString();
    void mutation();
};
#endif