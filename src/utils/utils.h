#ifndef _utils_utils_h
#define _utils_utils_h

#include <string>
#include <vector>
#include "../entrypoint.h"

std::string replace(std::string str, const std::string from, const std::string to);
std::vector<std::string> explode(std::string str, std::string delimiter);
std::string implode(std::vector<std::string> elements, std::string delimiter);
bool ends_with(std::string value, std::string ending);
bool starts_with(std::string value, std::string starting);

#endif