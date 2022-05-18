
#ifndef EVOLUTIONALGORITHM_GEN_H
#define EVOLUTIONALGORITHM_GEN_H


#include <vector>
#include "Point.h"

class Gen {
private:
    int type;
    Point point;
public:
    Gen(int type, const Point &point);

    Gen();

    Gen(Gen const &gen);

    int getType() const;

    void setType(int type);

    const Point &getPoint() const;

    void setPoint(const Point &point);

};

#define Genome std::vector<Gen>
#define Population std::vector<Genome>

Population concat(std::vector<Population> &populations);
#endif //EVOLUTIONALGORITHM_GEN_H
