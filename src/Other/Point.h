#ifndef EVOLUTIONALGORITHM_POINT_H
#define EVOLUTIONALGORITHM_POINT_H


#include <cmath>

class Point {
private:
    double x, y;
public:
    Point(double x, double y);

    Point();

    Point(Point const &p);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);
};


#endif //EVOLUTIONALGORITHM_POINT_H
