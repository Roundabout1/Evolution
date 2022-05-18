
#include "Gen.h"

int Gen::getType() const {
    return type;
}

void Gen::setType(int type) {
    Gen::type = type;
}

const Point &Gen::getPoint() const {
    return point;
}

void Gen::setPoint(const Point &point) {
    Gen::point = point;
}

Gen::Gen(int type, const Point &point) : type(type), point(point) {}

Gen::Gen() {}

Gen::Gen(const Gen &gen) {
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
