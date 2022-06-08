#ifndef EVOLUTIONALGORITHM_K_MEANS_H
#define EVOLUTIONALGORITHM_K_MEANS_H

#include "../Other/Point.h"
#include "../Fitness/Fitness.h"
#include <vector>
//метод k-средних
//возвращает массив из целых чисел, которые являются номерами кластеров к которым назначена та, или иная точка
std::vector<int> k_means(std::vector<Point> &points, int k, int num_iterations);
std::vector<int> k_means(Genome &points, int k, int num_iterations);
#endif //EVOLUTIONALGORITHM_K_MEANS_H
