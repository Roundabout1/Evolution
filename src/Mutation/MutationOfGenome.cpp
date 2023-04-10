
#include <iostream>
#include <algorithm>
#include "Mutation.h"
GenomePoint mutation(std::vector<GenePoint> &genome, double probability, int begin, int end) {
    int num_genes = genome.size();
    GenomePoint mutant = GenomePoint(num_genes);
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

//выбирается случайный отрезок, который затем переворачивается
GenomePoint mutation(std::vector<GenePoint> &genome, int begin, int end) {
    int a = getRandomNumber(begin, genome.size()-1-end);
    int b = getRandomNumber(begin, genome.size()-1-end);
    if(a == b)
        b = (a + 1)%genome.size();
    if(a > b)
        std::swap(a, b);
    GenomePoint mutant = GenomePoint(genome.size());
    for(int i = 0; i < genome.size(); i++)
        mutant[i] = genome[i];
    for(int i = 0; i <= b-a; i++){
        mutant[a+i] = genome[b-i];
    }
    return mutant;
}

GenomePoint single_migration(GenomePoint &genome, int begin, int end){
    GenomePoint mutant = GenomePoint(genome);
    int ending = genome.size()-1-end;
    int dir = getRandomNumber(0, 1) ? 1 : -1;
    //позиция откуда мигрируют гены
    int pos_from;
    int steps;
    if(dir == 1) {
        pos_from = getRandomNumber(begin, ending - 1);
        steps = getRandomNumber(1, ending - pos_from);
    }else{
        pos_from = getRandomNumber(begin + 1, ending);
        steps = getRandomNumber(1, pos_from - begin);
    }
    for(int i = 0; i < steps; i++) {
        int cur = pos_from + i * dir;
        int next = cur + dir;
        std::swap(mutant[cur], mutant[next]);
    }
    return mutant;
}

void inversion(std::vector<GenePoint> &genome) {
    std::reverse(genome.begin(), genome.end());
}

GenomePoint randomChoice(std::vector<GenePoint> &genome, int begin, int end) {
    int mut = getRandomNumber(0, 1);
    switch (mut) {
        case 0: return mutation(genome, begin, end);
        case 1: return single_migration(genome, begin, end);
    }
}
void flip(GenomeCluster &genome, int begin, int end){
    int a = getRandomNumber(begin, genome.size()-1-end);
    int b = getRandomNumber(begin, genome.size()-1-end);
    if(a == b)
        b = (a + 1)%genome.size();
    if(a > b)
        std::swap(a, b);
    for(int i = a, j = b; i < j; i++, j--){
        std::swap(genome[i], genome[j]);
    }
}

void neighbourSwap(std::vector<GeneCluster> &genome, int begin, int end) {
    int a = getRandomNumber(begin, genome.size()-1-end);
    int b = (a+1)%(genome.size()-end) + begin;
    std::swap(genome[a], genome[b]);
}

void single_migration(std::vector<GeneCluster> &mutant, int begin, int end) {
    int ending = mutant.size()-1-end;
    int dir = getRandomNumber(0, 1) ? 1 : -1;
    //позиция откуда мигрируют гены
    int pos_from;
    int steps;
    if(dir == 1) {
        pos_from = getRandomNumber(begin, ending - 1);
        steps = getRandomNumber(1, ending - pos_from);
    }else{
        pos_from = getRandomNumber(begin + 1, ending);
        steps = getRandomNumber(1, pos_from - begin);
    }
    for(int i = 0; i < steps; i++) {
        int cur = pos_from + i * dir;
        int next = cur + dir;
        std::swap(mutant[cur], mutant[next]);
    }
}

void randomChoice(std::vector<GeneCluster> &genome, int begin, int end) {
    int mut = getRandomNumber(0, 3);
    switch (mut) {
        case 0:
            flip(genome, begin, end);
            break;
        case 1:
            single_migration(genome, begin, end);
            break;
        case 2:
            neighbourSwap(genome, begin, end);
            break;
        case 3:
            randomReverse(genome, begin, end);
            break;
    }
}

GenomePoint neighbourSwap(std::vector<GenePoint> &genome, int begin, int end) {
    int a = getRandomNumber(begin, genome.size()-1-end);
    int b = (a+1)%(genome.size()-end) + begin;
    GenomePoint mutant = GenomePoint(genome);
    std::swap(mutant[a], mutant[b]);
    return mutant;
}

GenomePoint endsSwap(std::vector<GenePoint> &genome, int begin, int end) {
    GenomePoint mutant = GenomePoint(genome);
    int a, b;
    if(getRandomNumber(0, 1)){
        a = begin;
    }else{
        a = genome.size() - 1 - end;
    }
    b = getRandomNumber(begin, genome.size() - end - 1);
    if(b == a)
        b = (a + 1)%(genome.size() - end) + begin;
    return mutant;
}

void randomReverse(std::vector<GeneCluster> &cluster, int begin, int end) {
    int c = getRandomNumber(begin, cluster.size()-1-end);
    cluster[c].reverse();
}

void clustersMutation(std::vector<GeneCluster> &cluster, int num_mutations, int begin, int end) {
    for(int i = 0; i < num_mutations; i++){
        int j = getRandomNumber(begin, cluster.size() - 1 - end);
        cluster[j].setCluster(randomChoice(cluster[j].getCluster()));
    }
}

