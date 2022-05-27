//
// Created by mrsiv on 27.05.2022.
//

#include "ReadData.h"
void readData(int &num_cities, int &num_population, int &num_iterations, std::vector<Gene> &points) {
    std::ifstream conf(conf_path);
    conf >> num_cities >> num_population >> num_iterations;
    conf.close();

    points.resize(num_cities);
    std::ifstream p(points_path);
    for(int i = 0; i < num_cities; i++){
        double x, y;
        p >> x >> y;
        Point point = Point(x, y);
        points[i] = Gene(i, point);
    }
    p.close();
}
