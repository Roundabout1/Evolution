//
// Created by mrsiv on 27.05.2022.
//

#ifndef EVOLUTIONALGORITHM_READDATA_H
#define EVOLUTIONALGORITHM_READDATA_H

#include <vector>
#include <fstream>
#include "../../Gene/GenePoint.h"
#include "../../Pathes.h"
void readData(int &num_population, int &num_iterations, std::vector<GenePoint> &points,
              std::string conf_dest=conf_path, std::string points_dest=points_path);
void readData(GenomePoint &points, std::string points_dest=points_path);
#endif //EVOLUTIONALGORITHM_READDATA_H
