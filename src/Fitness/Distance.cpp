#include "Fitness.h"
double distance(const Point &a, const Point &b) {
    return std::abs(a.getX() - b.getX()) + std::abs(a.getY() - b.getY());
}
double manhattan_distance(const Point &a, const Point &b){
    return std::abs(a.getX() - b.getX()) + std::abs(a.getY() - b.getY());
}
double get_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example) {
    double res = 0.0;
    if(pos_genome != 0){
        res += distance(genome[pos_genome - 1].getPoint(), example[pos_example].getPoint());
    }
    if(pos_genome != genome.size()-1){
        res += distance(genome[pos_genome + 1].getPoint(), example[pos_example].getPoint());
    }
    return res;
}

double get_distance(std::vector<GenePoint> &genome, int pos) {
    double res = 0.0;
    if(pos != 0){
        res += distance(genome[pos - 1].getPoint(), genome[pos].getPoint());
    }
    if(pos != genome.size()-1){
        res += distance(genome[pos + 1].getPoint(), genome[pos].getPoint());
    }
    return res;
}

double get_left_distance(GenomePoint &genome, GenomePoint &example, int pos_genome, int pos_example) {
    double res = 0.0;
    if(pos_genome != 0){
        res += distance(genome[pos_genome - 1].getPoint(), example[pos_example].getPoint());
    }
    return res;
}
double euclidean_distance(const Point &p1, const Point &p2){
    return std::sqrt(euclidean_square(p1, p2));
}
double euclidean_square(const Point &p1, const Point &p2){
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}

double distance(const Point &a, const Point &b, bool isClosed, measures distance_measure) {
    switch (distance_measure) {
        case measures::manhattan:
            return manhattan_distance(a, b);
        case measures::euclid:
            return euclidean_distance(a, b);

    }
    return 0;
}

double get_distance(std::vector<GenePoint> &genome, std::vector<GenePoint> &example, int pos_genome, int pos_example,
                    bool isClosed, measures distance_measure) {
    double res = 0.0;
    int pos1 = pos_genome-1, pos2 = pos_genome+1;
    if(isClosed){
        if(pos1 < 0)
            pos1 = genome.size()-pos1;
        pos2%=genome.size();
    }
    if(pos1 >= 0){
        res += distance(genome[pos1].getPoint(), example[pos_example].getPoint(), isClosed, distance_measure);
    }
    if(pos2 < genome.size()){
        res += distance(genome[pos2].getPoint(), example[pos_example].getPoint(), isClosed, distance_measure);
    }
    return res;
}

double
get_left_distance(std::vector<GenePoint> &genome, std::vector<GenePoint> &example, int pos_genome, int pos_example,
                  bool isClosed, measures distance_measure) {
    double res = 0.0;
    int pos_left = pos_genome-1;
    if(isClosed && pos_left < 0)
        pos_left = genome.size() - pos_left;
    if(pos_left >= 0){
        res += distance(genome[pos_left].getPoint(), example[pos_example].getPoint(), isClosed, distance_measure);
    }
    return res;
}

double get_distance(std::vector<GenePoint> &genome, int pos, bool isClosed, measures distance_measure) {
    double res = 0.0;
    int pos1 = pos-1, pos2 = pos+1;
    if(isClosed){
        if(pos1 < 0)
            pos1 = genome.size()-1;
        pos2%=genome.size();
    }
    if(pos1 >= 0){
        res += distance(genome[pos1].getPoint(), genome[pos].getPoint(), isClosed, distance_measure);
    }
    if(pos2 < genome.size()){
        res += distance(genome[pos2].getPoint(), genome[pos].getPoint(), isClosed, distance_measure);
    }
    return res;
}
