
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