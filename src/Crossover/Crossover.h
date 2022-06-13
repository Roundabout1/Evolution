#ifndef EVOLUTIONALGORITHM_CROSSOVER_H
#define EVOLUTIONALGORITHM_CROSSOVER_H
#include "../Gene/GenePoint.h"
#include "../Distance_measures.h"
#include <vector>
//begin - минимальное количество генов, которые гарантированно достанутся первому родителю
//end - второму
PopulationPoint crossover_random_parents(PopulationPoint &population, int k=1, int begin= 1, int end= 1);
//если similar = true, то подбираются наиболее похожие друг на друга партнеры, иначе наиболее отличающиеся друг от друга
PopulationPoint crossover_similar(PopulationPoint &population, std::vector<double> &fit_vec, int k=1, int begin= 1, int end= 1);
PopulationPoint crossover_different(PopulationPoint &population, std::vector<double> &fit_vec, int k=1, int begin= 1, int end= 1);
//скрещивание двух родителей, вовзращает двух потомков
//k - количество точек разрыва
PopulationPoint crossover(GenomePoint &parent1, GenomePoint &parent2, int k=1, int begin=1, int end=1);
PopulationPoint uniform_crossover(PopulationPoint &population);
PopulationPoint uniform_crossover(GenomePoint &parent1, GenomePoint &parent2);
PopulationPoint crossover_different2(std::vector<std::vector<GenePoint>> &population, std::vector<double> &fit_vec, int k=1, int begin=0, int end=0);
//population отсортирован по функции приспособленности
PopulationPoint multi_fit_crossover(PopulationPoint &population, std::vector<double> &fit_vec, int num_offspring);
PopulationPoint rank_fit_crossover(PopulationPoint &population, std::vector<double> &fit_vec, int num_pairs_offspring);
PopulationPoint collision(PopulationPoint &population, std::vector<double> &fit_vec, bool isClosed, measures distance_measure);
PopulationPoint collision(GenomePoint &g1, GenomePoint &g2, double velocity1, double velocity2, bool isClosed, measures distance_measure);
PopulationPoint ordered(PopulationPoint &population);
PopulationPoint ordered(GenomePoint &g1, GenomePoint &g2);
PopulationCluster uniform(GenomeCluster &p1, GenomeCluster &g2);
#endif //EVOLUTIONALGORITHM_CROSSOVER_H
