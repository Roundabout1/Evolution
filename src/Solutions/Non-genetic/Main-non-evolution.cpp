#include <fstream>
#include <iostream>
#include "nearest.h"
#include "../Auxiliary/ReadData.h"
#include "../Auxiliary/Prints.h"
#include "../../Fitness/Fitness.h"

int main(){
    Genome points;
    readData(points);
    Genome answer = nearest(points);
    std::ofstream out(output_path + "/nearest_answer.txt");
    out << print(answer);
    out.close();
    std::ofstream out_fit(output_path+"/nearest_fit.txt");
    out_fit << fitness(answer);
    out_fit.close();
    return 0;
}