#ifndef EVOLUTIONALGORITHM_FILEOPERATIONS_H
#define EVOLUTIONALGORITHM_FILEOPERATIONS_H
#include <string>
#include "../Pathes.h"
void createFolders(std::string folder_path, std::string folder_pattern_name, int num_folders);
void copyFileTo(std::string file_path, std::string destination_path);
#endif //EVOLUTIONALGORITHM_FILEOPERATIONS_H
