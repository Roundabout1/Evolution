#include "Fitness.h"
double distance(const Point &a, const Point &b) {
    return std::abs(a.getX() - b.getX()) + std::abs(a.getY() - b.getY());
    //std::cout << p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY() << '\n';
    //return sqrt((p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY()));
}
double get_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example) {
    double res = 0.0;
    if(pos_genome != 0){
        res += distance(genome[pos_genome-1].getPoint(), example[pos_example].getPoint());
    }
    if(pos_genome != genome.size()-1){
        res += distance(genome[pos_genome+1].getPoint(), example[pos_example].getPoint());
    }
    return res;
}

double get_distance(std::vector<GenePoint> &genome, int pos) {
    double res = 0.0;
    if(pos != 0){
        res += distance(genome[pos-1].getPoint(), genome[pos].getPoint());
    }
    if(pos != genome.size()-1){
        res += distance(genome[pos+1].getPoint(), genome[pos].getPoint());
    }
    return res;
}

double get_left_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example) {
    double res = 0.0;
    if(pos_genome != 0){
        res += distance(genome[pos_genome-1].getPoint(), example[pos_example].getPoint());
    }
    return res;
}