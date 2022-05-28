#include "Prints.h"
std::string print(Genome &genome){
    std::string output = "";
    for(int i = 0; i < genome.size(); i++){
        output += std::to_string(genome[i].getType()) + " ";
    }
    return output;
}

std::string print(Population &population){
    std::string output = "";
    for(int i = 0; i < population.size(); i++){
        output += print(population[i]) + "\n";
    }
    return output;
}

std::string print(std::vector<double> v){
    std::string output = "";
    for(int i = 0; i < v.size(); i++){
        output += std::to_string(v[i]) + "\n";
    }
    return output;
}