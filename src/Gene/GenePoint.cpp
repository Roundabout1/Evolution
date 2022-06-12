#include "GenePoint.h"

Gene::Gene(int type) {
    Gene::type = type;
}

Gene::Gene() {
    int type = 0;
}

Gene::Gene(const Gene &gen) {
    Gene::type = gen.type;
}

int Gene::getType() const {
    return type;
}

void Gene::setType(int type) {
    Gene::type = type;
}

const Point &GenePoint::getPoint() const {
    return point;
}

void GenePoint::setPoint(const Point &point) {
    GenePoint::point = point;
}

GenePoint::GenePoint(int type, const Point &point) : Gene(type), point(point) {}

GenePoint::GenePoint() {}

GenePoint::GenePoint(const GenePoint &gen) {
    GenePoint::point = gen.point;
    setType(gen.getType());
}

PopulationPoint concat(std::vector<PopulationPoint> &populations) {
    PopulationPoint united;
    for(auto i : populations){
        for(auto j : i)
            united.push_back(j);
    }
    return united;
}

void GeneCluster::setCenter(const Point &center) {
    GeneCluster::center = center;
}

GeneCluster::GeneCluster() {

}

GeneCluster::GeneCluster(int type, Point point) : Gene(type), center(center){
    reversed = false;
}

GeneCluster::GeneCluster(int type, const std::vector<GenePoint> &cluster, const Point &center) : Gene(type), cluster(cluster), center(center) {
    reversed = false;
}

GeneCluster::GeneCluster(int type, const std::vector<GenePoint> &cluster) : Gene(type), cluster(cluster){
    reversed = false;
}

bool GeneCluster::isReversed() const {
    return reversed;
}

void GeneCluster::setIsReversed(bool isReversed) {
    GeneCluster::reversed = isReversed;
}

const Point &GeneCluster::getCenter() const {
    return center;
}

const int &GeneCluster::clusterSize() const {
    return cluster.size();
}

void GeneCluster::push_back(const GenePoint &point) {
    cluster.push_back(point);
}

std::vector<GenePoint> &GeneCluster::getCluster() {
    return cluster;
}

void GeneCluster::setCluster(const std::vector<GenePoint> &cluster) {
    GeneCluster::cluster = cluster;
}

GenePoint GeneCluster::getGenePoint(int index) {
    if(reversed) {
        int lastIndex = GeneCluster::cluster.size()-1;
        return GeneCluster::cluster[lastIndex - index];
    }
    return GeneCluster::cluster[index];
}

GenePoint GeneCluster::getLastGenePoint() {
    int lastIndex = GeneCluster::cluster.size()-1;
    return getGenePoint(lastIndex);
}

void GeneCluster::reverse() {
    reversed = !reversed;
}