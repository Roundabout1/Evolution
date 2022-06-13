#include "nearest.h"
#include "../../Fitness/Fitness.h"

GenomePoint nearest(GenomePoint &points){
    int num_points = points.size();
    GenomePoint best = points;
    double best_result = fitness(points);
    for(int start = 0; start < num_points; start++){
        double cur_result = 0.0;
        GenomePoint cur = nearest(points, start, cur_result);
        if(cur_result < best_result){
            best_result = cur_result;
            best = cur;
        }
    }
    return best;
}

GenomePoint nearest(std::vector<GenePoint> &points, int start_point, double &result) {
    GenomePoint cur(points);
    std::swap(cur[0], cur[start_point]);
    double cur_result = 0.0;
    for(int i = 1; i < points.size(); i++){
        double res = distance(cur[i - 1].getPoint(), cur[i].getPoint());
        for(int j = i + 1; j < points.size(); j++){
            double dis = distance(cur[i - 1].getPoint(), cur[j].getPoint());
            if(dis < res){
                res = dis;
                std::swap(cur[i], cur[j]);
            }
            //res = std::min(res, distance(cur[i-1].getPoint(), cur[j].getPoint()));
        }
        cur_result += res;
    }
    result = cur_result;
    return cur;
}

GenomePoint nearest(std::vector<GenePoint> &points, int start_point) {
    double a = 0;
    return nearest(points, start_point, a);
}

GenomePoint nearest(std::vector<GenePoint> &points, bool isClosed, measures distance_measure) {
    int num_points = points.size();
    GenomePoint best = points;
    double best_result = fitness(points, isClosed, distance_measure);
    for(int start = 0; start < num_points; start++){
        double cur_result = 0.0;
        GenomePoint cur = nearest(points, start, cur_result, isClosed, distance_measure);
        if(cur_result < best_result){
            best_result = cur_result;
            best = cur;
        }
    }
    return best;
}

GenomePoint nearest(std::vector<GenePoint> &points, int start_point, bool isClosed, measures distance_measure) {
    double a = 0;
    return nearest(points, start_point, a, isClosed, distance_measure);
}

GenomePoint nearest(std::vector<GenePoint> &points, int start_point, double &result, bool isClosed,
                    measures distance_measure) {
    GenomePoint cur(points);
    std::swap(cur[0], cur[start_point]);
    double cur_result = 0.0;
    for(int i = 1; i < points.size(); i++){
        double res = distance(cur[i - 1].getPoint(), cur[i].getPoint(), isClosed, distance_measure);
        for(int j = i + 1; j < points.size(); j++){
            double dis = distance(cur[i - 1].getPoint(), cur[j].getPoint(), isClosed, distance_measure);
            if(dis < res){
                res = dis;
                std::swap(cur[i], cur[j]);
            }
            //res = std::min(res, distance(cur[i-1].getPoint(), cur[j].getPoint()));
        }
        cur_result += res;
    }
    result = cur_result;
    return cur;
}
