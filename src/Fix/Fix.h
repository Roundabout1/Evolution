
#ifndef EVOLUTIONALGORITHM_FIX_H
#define EVOLUTIONALGORITHM_FIX_H
#include "../Gene/Gene.h"
#include <vector>
void fix(Population &population, Genome &example);
//genome - геном, который требуется исправить
//example - пример правильного генома, дожен быть того же размера, что и genome и
//быть упорядоченным по type от 0 до type.size()-1, то есть иметь вид [0, 1, .., size-1]
void fix(Genome &genome, Genome &example);
#endif //EVOLUTIONALGORITHM_FIX_H
