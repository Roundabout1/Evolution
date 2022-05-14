#include <filesystem>
#include <iostream>
#include <fstream>
#include "../header.hpp"
int main(){
    std::ifstream conf("data/input/conf.txt");
    size_t num_cities;
    conf >> num_cities;
    conf.close();

    std::ofstream out("data/input/points.txt");
    for(int i = 0; i < num_cities; i++){
        out << getRandomNumber(0.0, 1000.0) << ' ' << getRandomNumber(0.0, 1000.0) << '\n';
    }
}