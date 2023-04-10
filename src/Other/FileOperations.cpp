#include <fstream>
#include "FileOperations.h"

void createFolders(std::string folder_path, std::string folder_pattern_name, int num_folders) {
    std::string number = std::to_string(num_folders);
    system((create_bat + " " + folder_path + " " + number + " " + folder_pattern_name).c_str());
}

void copyFileTo(std::string file_path, std::string destination_path) {
    std::ifstream src(file_path);
    std::ofstream dest(destination_path);
    dest << src.rdbuf();
}
