
#ifndef EVOLUTIONALGORITHM_FIX_H
#define EVOLUTIONALGORITHM_FIX_H
#include "../Gene/Gene.h"
#include <vector>
void fix(Population &population, Genome &example);
void fix(Population &population, Genome &example, void (*fix_operator)(Genome &genome, Genome &example));
//genome - геном, который требуется исправить
//example - пример правильного генома, дожен быть того же размера, что и genome и
//быть упорядоченным по type от 0 до type.size()-1, то есть иметь вид [0, 1, .., size-1]
void fix_random(Genome &genome, Genome &example);
void fix_greedy(Genome &genome, Genome &example);
void fix_greedy2(Genome &genome, Genome &example);
double get_distance(Genome &genome, Genome &example, int pos_genome, int pos_example);
#endif //EVOLUTIONALGORITHM_FIX_H
