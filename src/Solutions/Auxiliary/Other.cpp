#include "Other.h"
int getBest(PopulationPoint &population, std::vector<double> &fit_vec){
    int best = 0;
    for(int i = 1; i < population.size(); i++){
        if(fit_vec[i] < fit_vec[best])
            best = i;
    }
    return best;
}

int getBest(std::vector<double> &fit_vec) {
    int best = 0;
    for(int i = 1; i < fit_vec.size(); i++){
        if(fit_vec[i] < fit_vec[best])
            best = i;
    }
    return best;
}

GenomePoint convert(std::vector<GeneCluster> &cluster, std::vector<std::vector<int>> &originalID) {
    GenomePoint result;
    for(int i = 0; i < cluster.size(); i++){
        for(int j = 0; j < cluster[i].getCluster().size(); j++){
            GenePoint point = cluster[i].getGenePoint(j);
            int clusterID = cluster[i].getType();
            point.setType(originalID[clusterID][point.getType()]);
            result.push_back(point);
        }
    }
    return result;
}



