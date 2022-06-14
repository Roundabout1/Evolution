#ifndef EVOLUTIONALGORITHM_PATHES_H
#define EVOLUTIONALGORITHM_PATHES_H
#include <string>
std::string const input_path = "data/input";
std::string const output_path = "data/output";
std::string const python_scripts = "../PythonScripts";
std::string const py_exe = "../venv2/Scripts/python.exe";
std::string const file_best_solution = "best_solution.txt";
std::string const file_fitness = "fitness.txt";
std::string const file_fitness_stats = "fitness_stats.txt";
std::string const file_genomes = "genomes.txt";
std::string const conf_path = input_path + "/conf.txt";
std::string const points_path = input_path + "/points.txt";
std::string const num_points_path = input_path + "/num_points.txt";
std::string const generation_name= "generation";
std::string const file_convergence = "convergence.txt";
std::string const solution_path = output_path + "/solution.txt";
std::string const fitness_value_path = output_path + "/fitness_value.txt";
std::string const tests_path = "data/tests";
std::string const create_bat = "createFolders.bat";
//std::string const first_solution = "first_solution.exe";
//std::string const second_solution = "second_solution.exe";
//std::string const generator = "Second_generator.exe";
std::string const test_folder_pattern = "test ";
std::string const k_means_labels = input_path+"/k-meansPy.txt";
std::string const k_means_script = python_scripts+"/k-means.py";
std::string const k_medoids_labels = input_path+"/k-medoidsPy.txt";
std::string const k_medoids_script = python_scripts+"/k-medoids.py";
std::string const k_medoids_centers = input_path+"/k-centersPy.txt";
std::string const k_centers = input_path+"/k-centersPy.txt";
std::string const k_labels = input_path+"/k-labelsPy.txt";
#endif //EVOLUTIONALGORITHM_PATHES_H
