
#include <iostream>
#include <algorithm>
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


Genome migration(Genome &genome, int begin, int end){
    /*Genome mutant = Genome(genome);
    int ending = genome.size()-1-end;
    //количество мигрирующих генов
    int k = getRandomNumber(1, ending-begin);
    int steps = getRandomNumber(1, ending-begin-2);
    //позиция откуда мигрируют гены
    int pos_from = getRandomNumber(begin, ending);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < steps; j++){
            int cur = (pos_from+j)%ending+begin;
            int next = (cur+1)%ending+begin;
            std::swap(mutant[cur], mutant[next]);
        }
    }*/
    Genome mutant = Genome(genome);
    int ending = genome.size()-1-end;
    //позиция откуда мигрируют гены
    int pos_from = getRandomNumber(begin+1, ending-1);
    //количество мигрирующих генов
    int k = 0;
    int steps = 0;
    bool forward = getRandomNumber(0, 1);
    if(forward){
        k = getRandomNumber(1, ending-pos_from);
        steps = getRandomNumber(1, ending-pos_from-k+1);
    }else{
        k = getRandomNumber(1, pos_from - begin);
        steps = getRandomNumber(-(pos_from - begin - k + 1), -1);
    }
    int first = pos_from + steps;
    int last = pos_from;
    std::vector<bool> used(genome.size());
    for(int i = 0; i < k; i++){
        int j = (forward) ? i : -i;
        int cur = pos_from+j;
        int next = cur+steps;
        mutant[next] = genome[cur];
        last = next;
        used[genome[cur].getType()] = 1;
    }
    if(first > last)
        std::swap(first, last);
    for(int i = 0, j = 0; i < genome.size(); i++, j++){
        mutant[i] = genome[j];
        if(i+1 == first)
            i = last;
    }

    for(int i = 0; i < k; i++){
        int cur = (pos_from+i)%ending+begin;
        int next = (cur+steps)%ending+begin;
        mutant[next] = genome[cur];
        used[genome[cur].getType()] = true;
    }
    std::cout << pos_from << ' ' << k << ' ' << steps << '\n';
    return mutant;
}

Genome single_migration(Genome &genome, int begin, int end){
    Genome mutant = Genome(genome);
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
    //std::cout << dir << ' ' << pos_from << ' ' << steps << '\n';
    for(int i = 0; i < steps; i++) {
        int cur = pos_from + i * dir;
        int next = cur + dir;
        //std::cout << cur << ' ' << next << '\n';
        std::swap(mutant[cur], mutant[next]);
    }
    return mutant;
}

void inversion(std::vector<Gene> &genome) {
    std::reverse(genome.begin(), genome.end());
}

Genome randomChoice(std::vector<Gene> &genome, int begin, int end) {
    bool mut = getRandomNumber(0, 1);
    if(mut){
        return mutation(genome, begin, end);
    }
    return single_migration(genome, begin, end);
}
