#include "nearest.h"
#include "../../Fitness/Fitness.h"

Genome nearest(Genome &points){
    int num_points = points.size();
    Genome best = points;
    double best_result = fitness(points);
    for(int start = 0; start < num_points; start++){
        Genome cur(points);
        std::swap(cur[0], cur[start]);
        double cur_result = 0.0;
        for(int i = 1; i < num_points - 1; i++){
            double res = distance(cur[i-1].getPoint(), cur[i].getPoint());
            for(int j = i + 1; j < num_points; j++){
                double dis = distance(cur[i-1].getPoint(), cur[j].getPoint());
                if(dis < res){
                    res = dis;
                    std::swap(cur[i], cur[j]);
                }
                res = std::min(res, distance(cur[i-1].getPoint(), cur[j].getPoint()));
            }
            cur_result += res;
        }
        if(cur_result < best_result){
            best_result = cur_result;
            best = cur;
        }
    }
    return best;
}