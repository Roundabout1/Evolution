
#ifndef EVOLUTIONALGORITHM_FIX_H
#define EVOLUTIONALGORITHM_FIX_H
#include "../Gene/GenePoint.h"
#include <vector>
void fix(PopulationPoint &population, GenomePoint &example);
void fix(PopulationPoint &population, GenomePoint &example, void (*fix_operator)(GenomePoint &genome, GenomePoint &example));
//genome - геном, который требуется исправить
//example - пример правильного генома, дожен быть того же размера, что и genome и
//быть упорядоченным по type от 0 до type.size()-1, то есть иметь вид [0, 1, .., size-1]
void fix_random(GenomePoint &genome, GenomePoint &example);
void fix_greedy(GenomePoint &genome, GenomePoint &example);
void fix_greedy2(GenomePoint &genome, GenomePoint &example);
//жадно чинит гены, смотря только на левую сторону
void fix_greedy_left(std::vector<GenePoint> &genome, std::vector<GenePoint> &example);
#endif //EVOLUTIONALGORITHM_FIX_H
