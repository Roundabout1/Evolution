//
// Created by mrsiv on 06.06.2022.
//

#include <math.h>
#include "DoubleOperations.h"

bool isEqual(double a, double b) {
    double eps = 0.0000000001;
    return std::abs(b - a) < eps;
}
