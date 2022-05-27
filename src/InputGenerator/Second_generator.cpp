#include <fstream>
#include "../Random/Random.h"

int main(){
    std::ifstream conf("data/input/conf.txt");
    size_t num_cities;
    conf >> num_cities;
    conf.close();

    int horizontal = num_cities*10;
    int vertical = num_cities*10;
    int distance = 10;
    std::ofstream out("data/input/points.txt");
    for(int i = 0; i < num_cities; i++){
        out << getRandomNumber(1, horizontal)*distance << ' ' << getRandomNumber(1, vertical)*distance << '\n';
    }
}
