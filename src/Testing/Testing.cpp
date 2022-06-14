//Запуск решений на тестах
#include <iostream>
#include <fstream>
#include <vector>
#include "../Pathes.h"
#include "../Other/FileOperations.h"
#include "../Solutions/Auxiliary/ReadData.h"
#include "../Fitness/Fitness.h"
#include "../Solutions/Auxiliary/Prints.h"
#include "../Solutions/Non-genetic/nearest.h"
#include "../Solutions/Genetic/GeneticSolutions.h"
#include "../Distance_measures.h"

void test(GenomePoint (*solution)(int, int, GenomePoint&, bool, measures), int num_population, int num_iterations, bool isClosed, measures distance_measure,
          GenomePoint &points, std::ofstream &time, std::ofstream &result){
    clock_t start = clock();
    GenomePoint res =  solution(num_population, num_iterations, points, isClosed, distance_measure);
    clock_t end = clock();
    time << end - start << '\n';
    result << fitness(res, isClosed, distance_measure) << '\n';
}
/*void test(GenomePoint (*solution)(GenomePoint&), GenomePoint &points, std::ofstream &time, std::ofstream &result){
    clock_t start = clock();
    GenomePoint res =  solution(points);
    clock_t end = clock();
    time << end - start << '\n';
    result << fitness(res) << '\n';
}*/

int main(){
    int num_tests = 61, num_solutions = 1;
    std::vector<std::string> results(num_solutions);
    std::vector<std::ofstream> ofstreams;
    std::vector<std::ofstream> time;
//    for(int i = 0; i < num_solutions; i++) {
//        ofstreams.push_back(std::ofstream(tests_path + "/results" + std::to_string(i) + ".txt"));
//        time.push_back(std::ofstream(tests_path + "/time" + std::to_string(i) + ".txt"));
//    }
    int num = 2;
    ofstreams.push_back(std::ofstream(tests_path + "/results" + std::to_string(num) + ".txt"));
    time.push_back(std::ofstream(tests_path + "/time" + std::to_string(num) + ".txt"));
    std::ofstream num_points(tests_path+"/num_points.txt");
    bool isClosed = 1;
    measures distance_measure = euclid;
    for(int i = 0; i < num_tests; i++){
        int num_population, num_iterations;
        GenomePoint points;
        std::string cur_path = tests_path + "/" + test_folder_pattern + std::to_string(i+1) + "/points.txt";
        readData(points, cur_path);
        //test(nearest,points, time[0], ofstreams[0]);
        //test(second_evolution, points.size()*5, points.size()*5, points, time[1], ofstreams[1]);
        test(second_evolution, points.size(), points.size()*2, isClosed, distance_measure,points, time[0], ofstreams[0]);
        std::cout << points.size() << std::endl;
        //test(second_evolution, num_population, num_iterations, points, time[2], ofstreams[2]);
        num_points << points.size() << '\n';
    }
    num_points.close();
    for(int i = 0; i < num_solutions; i++){
        ofstreams[i].close();
        time[i].close();
    }
    return 0;
}
/*
int num_tests = 30, min_points = 3;
    std::string cur_solution = second_solution;
    std::string test_results_file = tests_path+"/results.txt";
    std::string test_points_file = tests_path+"/points.txt";
    std::ofstream test_stream(test_results_file);
    std::ofstream test_points(test_points_file);
    for(int i = 0; i < num_tests; i++){
        std::ofstream num_points(num_points_path);
        num_points << i + min_points;
        num_points.close();
        system(generator.c_str());
        system(cur_solution.c_str());
        std::ifstream result(fitness_value_path);
        double res;
        result >> res;
        result.close();
        test_stream << res << '\n';
        test_points << i + min_points << '\n';
    }
    test_stream.close();
    test_points.close();
 */