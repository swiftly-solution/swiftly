#ifndef _files_h
#define _files_h

#include "../common.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>

namespace Files
{
    std::string Read(std::string path);
    void Append(std::string path, std::string content);
    void Delete(std::string path);
    std::string getBase(std::string filePath);
    bool ExistsPath(std::string path);
    bool IsDirectory(std::string path);
    std::vector<std::string> FetchFileNames(std::string path);
};

#endif