

#ifndef EVOLUTIONALGORITHM_POINT_H
#define EVOLUTIONALGORITHM_POINT_H


#include <cmath>

class Point {
private:
    double x, y;
public:
    Point(double x, double y);

    Point();

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    /*double distance(const Point& b) const {
        return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }*/
};


#endif //EVOLUTIONALGORITHM_POINT_H
