#ifndef _utils_utils_h
#define _utils_utils_h

#include <string>
#include <vector>
#include <TextTable.h>
#include <chrono>
#include "../entrypoint.h"

std::string replace(std::string str, const std::string from, const std::string to);
std::vector<std::string> explode(std::string str, std::string delimiter);
std::string implode(std::vector<std::string> elements, std::string delimiter);
std::string ProcessColor(std::string str, int team);
bool ends_with(std::string value, std::string ending);
bool starts_with(std::string value, std::string starting);
void PrintTextTable(std::string category, TextTable table);
uint64_t GetTime();

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        return "";

    size_t size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

#endif