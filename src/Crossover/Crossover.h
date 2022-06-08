#ifndef EVOLUTIONALGORITHM_CROSSOVER_H
#define EVOLUTIONALGORITHM_CROSSOVER_H
#include "../Gene/Gene.h"
#include <vector>
//begin - минимальное количество генов, которые гарантированно достанутся первому родителю
//end - второму
Population crossover_random_parents(Population &population, int k=1, int begin= 1, int end= 1);
//если similar = true, то подбираются наиболее похожие друг на друга партнеры, иначе наиболее отличающиеся друг от друга
Population crossover_similar(Population &population, std::vector<double> &fit_vec, int k=1, int begin= 1, int end= 1);
Population crossover_different(Population &population, std::vector<double> &fit_vec, int k=1, int begin= 1, int end= 1);
//скрещивание двух родителей, вовзращает двух потомков
//k - количество точек разрыва
Population crossover(Genome &parent1, Genome &parent2, int k=1, int begin=1, int end=1);
Population uniform_crossover(Population &population);
Population uniform_crossover(Genome &parent1, Genome &parent2);
Population crossover_different2(std::vector<std::vector<Gene>> &population, std::vector<double> &fit_vec, int k=1, int begin=0, int end=0);
//population отсортирован по функции приспособленности
Population multi_fit_crossover(Population &population, std::vector<double> &fit_vec, int num_offspring);
Population rank_fit_crossover(Population &population, std::vector<double> &fit_vec, int num_pairs_offspring);
Population collision(Population &population, std::vector<double> &fit_vec);
Population collision(Genome &g1, Genome &g2, double velocity1, double velocity2);
Population ordered(Population &population);
Population ordered(Genome &g1, Genome &g2);
#endif //EVOLUTIONALGORITHM_CROSSOVER_H
