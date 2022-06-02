#include <iostream>
#include <processthreadsapi.h>
#include "Gene/Gene.h"
#include "Initialization/Init.h"
#include "Crossover/Crossover.h"
#include "Other/FileOperations.h"
int main(){
    //STARTUPINFO info={sizeof(info)};
    //PROCESS_INFORMATION processInfo;
    //CreateProcess(NULL, "first_solution", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
    copyFileTo(solution_path, tests_path+"/solution_copy.txt");
    //std::cout << ("copy " + solution_path + " " + tests_path).c_str();
    //system(("copy " + solution_path + " " + tests_path).c_str());
    return 0;
}