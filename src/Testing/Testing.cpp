//Запуск решений на тестах
#include <iostream>
#include <fstream>
#include <vector>
#include "../Pathes.h"
#include "../Other/FileOperations.h"
#include "../Solutions/Auxiliary/ReadData.h"
#include "../Solutions/Genetic/First/first_evolution.h"
#include "../Solutions/Genetic/Second/second_evolution.h"
#include "../Fitness/Fitness.h"
#include "../Solutions/Auxiliary/Prints.h"
#include "../Solutions/Non-genetic/nearest.h"

void test(Genome (*solution)(int, int, Genome&), int num_population, int num_iterations, Genome &points, std::ofstream &time, std::ofstream &result){
    clock_t start = clock();
    Genome res =  solution(num_population, num_iterations, points);
    clock_t end = clock();
    time << end - start << '\n';
    result << fitness(res) << '\n';
}
void test(Genome (*solution)(Genome&), Genome &points, std::ofstream &time, std::ofstream &result){
    clock_t start = clock();
    Genome res =  solution(points);
    clock_t end = clock();
    time << end - start << '\n';
    result << fitness(res) << '\n';
}

int main(){
    int num_tests = 30, num_solutions = 3;
    std::vector<std::string> results(num_solutions);
    std::vector<std::ofstream> ofstreams;
    std::vector<std::ofstream> time;
    for(int i = 1; i <= num_solutions; i++) {
        ofstreams.push_back(std::ofstream(tests_path + "/results" + std::to_string(i) + ".txt"));
        time.push_back(std::ofstream(tests_path + "/time" + std::to_string(i) + ".txt"));
    }
    std::ofstream num_points(tests_path+"/num_points.txt");
    for(int i = 0; i < num_tests; i++){
        int num_population, num_iterations;
        Genome points;
        std::string cur_path = tests_path + "/" + test_folder_pattern + std::to_string(i+1) + "/points.txt";
        readData(num_population, num_iterations, points, conf_path, cur_path);
        //std::cout << points[0].getPoint().getX() << std::endl;
        test(first_evolution, num_population, num_iterations, points, time[0], ofstreams[0]);
        test(second_evolution, num_population, num_iterations, points, time[1], ofstreams[1]);
        test(nearest,points, time[2], ofstreams[2]);
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