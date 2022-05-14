#include <cmath>
struct Point {
    //координаты точки
    double x, y;
    //евклидово расстояние
    double distance(const Point& b) const {
        return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};