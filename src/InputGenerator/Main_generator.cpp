#include <fstream>
#include "../Pathes.h"
#include "generators.h"
int main(){
    std::ifstream conf(num_points_path);
    size_t num_points;
    conf >> num_points;
    conf.close();
    first_generator(num_points, points_path);
    return 0;
}