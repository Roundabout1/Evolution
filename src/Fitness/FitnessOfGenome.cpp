#include <vector>
#include "Fitness.h"
#include "../Distance_measures.h"

//оценка для задачи Коммивояжёра
double fitness(GenomePoint &genome, bool isClosed, measures distance_measure){
    double sum = 0;
    if(isClosed){
        sum = distance(genome[0].getPoint(), genome[genome.size() - 1].getPoint(), isClosed, distance_measure);
    }
    for(int i = 1; i < genome.size(); i++){
        sum += distance(genome[i - 1].getPoint(), genome[i].getPoint(), isClosed, distance_measure);
    }
    return sum;
}
double fitness(GenomeCluster &cluster,bool isClosed, measures distance_measure){
    double sum = 0;
    for(int i = 0; i < cluster.size(); i++){
        sum += fitness(cluster[i].getCluster(), isClosed, distance_measure);
    }
    for(int i = 1; i < cluster.size(); i++){
        Point p1_end = cluster[i - 1].getLastGenePoint().getPoint();
        Point p2_begin = cluster[i].getGenePoint(0).getPoint();
        double dis = distance(p1_end, p2_begin, isClosed, distance_measure);
        sum += dis;
    }
    if(isClosed){
        Point p1_end = cluster[cluster.size()-1].getLastGenePoint().getPoint();
        Point p2_begin = cluster[0].getGenePoint(0).getPoint();
        double dis = distance(p1_end, p2_begin, isClosed, distance_measure);
        sum += dis;
    }
    return sum;
}
