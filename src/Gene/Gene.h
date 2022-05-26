
#ifndef EVOLUTIONALGORITHM_GENE_H
#define EVOLUTIONALGORITHM_GENE_H


#include <vector>
#include "../Other/Point.h"

class Gene {
private:
    int type;
    Point point;
public:
    Gene(int type, const Point &point);

    Gene();

    Gene(Gene const &gen);

    int getType() const;

    void setType(int type);

    const Point &getPoint() const;

    void setPoint(const Point &point);

};

#define Genome std::vector<Gene>
#define Population std::vector<Genome>

Population concat(std::vector<Population> &populations);
#endif //EVOLUTIONALGORITHM_GENE_H
