#include "Fitness.h"
double distance(const Point &a, const Point &b) {
    return std::abs(a.getX() - b.getX()) + std::abs(a.getY() - b.getY());
}
