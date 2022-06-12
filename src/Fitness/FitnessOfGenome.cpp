#include <vector>
#include "Fitness.h"
//оценка для задачи Коммивояжёра
double fitness(GenomePoint &genome) {
    //double sum = distance(genome[0].getPoint(), genome[genome.size()-1].getPoint());
    double sum = 0;
    for(int i = 1; i < genome.size(); i++){
        sum += distance(genome[i-1].getPoint(), genome[i].getPoint());
    }
    return sum;
}
double fitness(GenomeCluster &cluster){
    double sum = 0;
    for(int i = 0; i < cluster.size(); i++){
        sum += fitness(cluster[i].getCluster());
    }
//    Point p1_begin, p1_end, p2_begin, p2_end;
//    if(cluster.size() >= 2) {
//        p1_begin = cluster[0].getLastGenePoint().getPoint();
//        p1_end = cluster[0].getLastGenePoint().getPoint();
//        p2_begin = cluster[1].getGenePoint(0).getPoint();
//        p2_end = cluster[1].getLastGenePoint().getPoint();
//        double dis1 = distance(p1_begin, p2_begin);
//        double dis2 = distance(p1_begin, p2_end);
//        double dis3 = distance(p1_end, p2_begin);
//        double dis4 = distance(p1_end, p2_end);
//        if(dis3 < dis1 && dis3 < dis2 || dis4 < dis1 && dis4 < dis2){
//            cluster[0].reverse();
//        }
//    }
    for(int i = 1; i < cluster.size(); i++){
//        Point p1_end = cluster[i - 1].getLastGenePoint().getPoint();
//        Point p2_begin = cluster[i].getGenePoint(0).getPoint();
//        Point p2_end = cluster[i].getLastGenePoint().getPoint();
//        double dis1 = distance(p1_end, p2_begin);
//        double dis2 = distance(p1_end, p2_end);
//        if(dis2 < dis1){
//            cluster[i].reverse();
//            sum += dis2;
//        }else{
//            sum += dis1;
//        }
        Point p1_end = cluster[i - 1].getLastGenePoint().getPoint();
        Point p2_begin = cluster[i].getGenePoint(0).getPoint();
        double dis = distance(p1_end, p2_begin);
        sum += dis;
    }
    return sum;
}