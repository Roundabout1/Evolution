#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}

Point::Point() {}

Point::Point(const Point &p) {
    Point::x = p.x;
    Point::y = p.y;
}
