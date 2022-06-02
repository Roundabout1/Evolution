#include <fstream>
#include "../Random/Random.h"
#include "../Pathes.h"
#include "second_generator.h"
void second_generator(int num_points, std::string destination){
    int horizontal = num_points*10;
    int vertical = num_points*10;
    int distance = 10;
    std::ofstream out(destination);
    for(int i = 0; i < num_points; i++){
        out << getRandomNumber(1, horizontal)*distance << ' ' << getRandomNumber(1, vertical)*distance << '\n';
    }

}
