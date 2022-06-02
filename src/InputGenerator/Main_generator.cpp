#include <fstream>
#include "../Pathes.h"
#include "second_generator.h"
int main(){
    std::ifstream conf(num_points_path);
    size_t num_points;
    conf >> num_points;
    conf.close();
    second_generator(num_points, points_path);
    return 0;
}