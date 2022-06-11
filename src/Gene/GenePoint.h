
#ifndef EVOLUTIONALGORITHM_GENEPOINT_H
#define EVOLUTIONALGORITHM_GENEPOINT_H


#include <vector>
#include "../Other/Point.h"
class Gene{
private:
    int type;
public:
    Gene(int type);

    Gene();

    Gene(Gene const &gen);

    int getType() const;

    void setType(int type);

};
#define Genome std::vector<Gene>
#define Population std::vector<Genome>
class GenePoint : public Gene{
private:
    Point point;
public:
    GenePoint(int type, const Point &point);

    GenePoint();

    GenePoint(GenePoint const &gen);

    const Point &getPoint() const;

    void setPoint(const Point &point);

};
#define GenomePoint std::vector<GenePoint>
#define PopulationPoint std::vector<GenomePoint>
class GeneCluster : public Gene{
private:
    GenomePoint cluster;
    Point center;
    bool reversed=0;
public:
    GeneCluster(int type, const GenomePoint &cluster, const Point &center);

    GeneCluster(int type, const GenomePoint &cluster);

    void setCenter(const Point &center);

    GeneCluster();

    GeneCluster(int i, Point point);

    const Point &getCenter() const;

    const int &clusterSize() const;

    std::vector<GenePoint> &getCluster();

    void setCluster(const std::vector<GenePoint> &cluster);

    void push_back(const GenePoint &point);

    bool isReversed() const;

    void setIsReversed(bool isReversed);

    GenePoint getGenePoint(int index);

    GenePoint getLastGenePoint();

    void reverse();
};
#define GenomeCluster std::vector<GeneCluster>
#define PopulationCluster std::vector<GenomeCluster>
PopulationPoint concat(std::vector<PopulationPoint> &populations);
#endif //EVOLUTIONALGORITHM_GENEPOINT_H
