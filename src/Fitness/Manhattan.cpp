#include "Fitness.h"
double distance(const Point &a, const Point &b) {
    return std::abs(a.getX() - b.getX()) + std::abs(a.getY() - b.getY());
}
double get_distance(Genome &genome, Genome &example, int pos_genome, int pos_example) {
    double res = 0.0;
    if(pos_genome != 0){
        res += distance(genome[pos_genome-1].getPoint(), example[pos_example].getPoint());
    }
    if(pos_genome != genome.size()-1){
        res += distance(genome[pos_genome+1].getPoint(), example[pos_example].getPoint());
    }
    return res;
}

double get_distance(std::vector<Gene> &genome, int pos) {
    double res = 0.0;
    if(pos != 0){
        res += distance(genome[pos-1].getPoint(), genome[pos].getPoint());
    }
    if(pos != genome.size()-1){
        res += distance(genome[pos+1].getPoint(), genome[pos].getPoint());
    }
    return res;
}
