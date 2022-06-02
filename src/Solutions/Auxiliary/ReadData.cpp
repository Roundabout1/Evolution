#include <iostream>
#include "ReadData.h"
void readData(int &num_population, int &num_iterations, std::vector<Gene> &points,
              std::string conf_dest, std::string points_dest) {

    std::ifstream conf(conf_dest);
    conf >> num_population >> num_iterations;
    conf.close();
    readData(points, points_dest);
}

void readData(std::vector<Gene> &points, std::string points_dest) {
    std::ifstream poi(points_dest);
    float x, y;
    int i = 0;
    while(poi >> x >> y){
        points.push_back(Gene(i, Point(x, y)));
        i++;
    }
    poi.close();
}
