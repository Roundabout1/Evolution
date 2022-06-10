//
// Created by mrsiv on 08.06.2022.
//

#include <iostream>
#include <fstream>
#include "k-clusters.h"
#include "../Random/Random.h"
#include "../Other/DoubleOperations.h"
#include "../Pathes.h"
std::vector<int> k_means(std::vector<Point> &points, int k, int num_iterations) {
    //принадлежность к кластеру
    std::vector<int> cluster(points.size());
    //дистанция до ближайшего кластера
    std::vector<double> min_dist(points.size(), __DBL_MAX__);

    std::vector<Point> centroids;
    /*for(int i = 0; i < points.size(); i++){
        std::cout << points[i].getX() << ' ' << points[i].getY() << '\n';
    }*/
    std::vector<int> indexes(points.size());
    for(int i = 0; i < points.size(); i++)
        indexes[i] = i;
    for(int i = 0; i < k; i++) {
        int j = getRandomNumber(i, points.size()-1);
        std::swap(indexes[i], indexes[j]);
        centroids.push_back(Point(points[indexes[i]]));
    }
    for(int i = 0; i < num_iterations; i++){
        //назначем точку к кластеру
        for(int c = 0; c < k; c++){
            for(int p = 0; p < points.size(); p++){
                double dis = euclideanSquare(points[p], centroids[c]);
                if(dis < min_dist[p] || isEqual(dis, min_dist[p])){
                    //std::cout << i << '\n';
                    min_dist[p] = dis;
                    cluster[p] = c;
                }
            }
        }
        //вычисляем новые центроиды

        //количество точек в одном кластере
        std::vector<int> cluster_points(k, 0);
        //сумма координат по x и по y.
        std::vector<double> sumX(k, 0.0), sumY(k, 0.0);
        for(int p = 0; p < points.size(); p++){
            int c = cluster[p];
            cluster_points[c]++;
            sumX[c] += points[p].getX();
            sumY[c] += points[p].getY();
        }

        //новые центроиды
        for(int c = 0; c < k; c++){
            if(cluster_points[c] == 0)
                std::cout << "0!\n";
            centroids[c].setX(sumX[c]/cluster_points[c]);
            centroids[c].setY(sumY[c]/cluster_points[c]);
            //std::cout << "i = " << i << ' ' << " c = " << c << ' ' << centroids[c].getX() << ' ' << centroids[c].getY() << '\n';
        }
        double v = 0.0;
        for(int p = 0; p < points.size(); p++){
            v += euclideanSquare(points[p], centroids[cluster[p]]);
        }
        std::cout << i << ' ' << v << std::endl;
    }

    return cluster;

}

std::vector<int> k_means(std::vector<Gene> &points, int k, int num_iterations) {
    std::vector<Point> p;
    for(int i = 0; i < points.size(); i++)
        p.push_back(points[i].getPoint());
    return k_means(p, k, num_iterations);
}

std::vector<int> k_medoidsPY() {
    std::cout << py_exe + " " + k_medoids_script << std::endl;
    system((py_exe + " " + k_medoids_script).c_str());
    std::ifstream read(k_medoids_labels);
    std::vector<int> ans;
    int i;
    while(read >> i){
        ans.push_back(i);
    }
    return ans;
}

std::vector<int> k_meansPY() {
    system(k_means_script.c_str());
    std::ifstream read(k_means_labels);
    std::vector<int> ans;
    int i;
    while(read >> i){
        ans.push_back(i);
    }
    return ans;
}
