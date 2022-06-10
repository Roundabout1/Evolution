#ifndef EVOLUTIONALGORITHM_K_CLUSTERS_H
#define EVOLUTIONALGORITHM_K_CLUSTERS_H

#include "../Other/Point.h"
#include "../Fitness/Fitness.h"
#include <vector>
//метод k-средних
//возвращает массив из целых чисел, которые являются номерами кластеров к которым назначена та, или иная точка
std::vector<int> k_means(std::vector<Point> &points, int k, int num_iterations);
std::vector<int> k_means(Genome &points, int k, int num_iterations);
std::vector<int> k_medoids(std::vector<Point> &points, int k, int num_iterations);
std::vector<int> k_medoids(Genome &points, int k, int num_iterations);
std::vector<int> k_meansPY();
std::vector<int> k_medoidsPY();
#endif //EVOLUTIONALGORITHM_K_CLUSTERS_H
