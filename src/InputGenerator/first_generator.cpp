#include <fstream>
#include "../Random/Random.h"
#include "../Pathes.h"
int main(){
    std::ifstream conf(num_points_path);
    size_t num_cities;
    conf >> num_cities;
    conf.close();

    std::ofstream out("data/input/points.txt");
    for(int i = 0; i < num_cities; i++){
        out << getRandomNumber(0.0, 1000.0) << ' ' << getRandomNumber(0.0, 1000.0) << '\n';
    }
}