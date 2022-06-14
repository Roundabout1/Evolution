//генератор тестов
#include "../Other/FileOperations.h"
#include "../Pathes.h"
#include "../InputGenerator/generators.h"
int main(){
    int num_test = 61;
    int min_points = 20;
    createFolders(tests_path, test_folder_pattern, num_test);
    for(int i = 0; i < num_test; i++){
        std::string cur_path = tests_path + "/" + test_folder_pattern + std::to_string(i+1) + "/points.txt";
        first_generator(min_points + i, cur_path);
    }
    return 0;
}