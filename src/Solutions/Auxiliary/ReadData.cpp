#include <iostream>
#include "ReadData.h"
#include "../../Distance_measures.h"
void readData(int &num_population, int &num_iterations, std::vector<GenePoint> &points, bool &isClosed, measures &distance_measure,
              std::string conf_dest, std::string points_dest) {

    std::ifstream conf(conf_dest);
    std::string dis;
    conf >> num_population >> num_iterations >> isClosed >> dis;
    if(dis == "eu")
        distance_measure = euclid;
    if(dis == "manh")
        distance_measure = manhattan;
    conf.close();
    readData(points, points_dest);
}

void readData(std::vector<GenePoint> &points, std::string points_dest) {
    std::ifstream poi(points_dest);
    float x, y;
    int i = 0;
    while(poi >> x >> y){
        points.push_back(GenePoint(i, Point(x, y)));
        i++;
    }
    poi.close();
}
