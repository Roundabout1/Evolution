#include <fstream>
#include "../Random/Random.h"
#include "../Pathes.h"
#include "generators.h"
void first_generator(int num_points, std::string destination){
    std::ofstream out(destination);
    for(int i = 0; i < num_points; i++){
        out << getRandomNumber(0.0, 1000.0) << ' ' << getRandomNumber(0.0, 1000.0) << '\n';
    }
    out.close();
}