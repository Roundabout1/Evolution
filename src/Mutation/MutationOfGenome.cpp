
#include <iostream>
#include "Mutation.h"
Genome mutation(std::vector<Gene> &genome, double probability, int begin, int end) {
    int num_genes = genome.size();
    Genome mutant = Genome(num_genes);
    for(int i = 0; i < num_genes; i++){
        mutant[i] = genome[i];
    }
    for(int i = begin; i < num_genes - 1 - end; i++){
        if(getRandomNumber(0.0, 1.0) <= probability){
            int j = getRandomNumber(1, num_genes-1);
            std::swap(mutant[i], mutant[j]);
        }
    }
    return mutant;
}

//выбирается случайный отрезок, который затем перворачивается
Genome mutation(std::vector<Gene> &genome, int begin, int end) {
    int a = getRandomNumber(begin, genome.size()-1-end);
    int b = getRandomNumber(begin, genome.size()-1-end);
    if(a == b)
        b = (a + 1)%genome.size();
    if(a > b)
        std::swap(a, b);
    Genome mutant = Genome(genome.size());
    for(int i = 0; i < genome.size(); i++)
        mutant[i] = genome[i];
    for(int i = 0; i <= b-a; i++){
        mutant[a+i] = genome[b-i];
    }
    return mutant;
}

