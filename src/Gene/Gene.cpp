
#include "Gene.h"

int Gene::getType() const {
    return type;
}

void Gene::setType(int type) {
    Gene::type = type;
}

const Point &Gene::getPoint() const {
    return point;
}

void Gene::setPoint(const Point &point) {
    Gene::point = point;
}

Gene::Gene(int type, const Point &point) : type(type), point(point) {}

Gene::Gene() {}

Gene::Gene(const Gene &gen) {
    this->point = gen.point;
    this->type = gen.type;
}

Population concat(std::vector<Population> &populations) {
    Population united;
    for(auto i : populations){
        for(auto j : i)
            united.push_back(j);
    }
    return united;
}
