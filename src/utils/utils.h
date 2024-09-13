#ifndef _utils_utils_h
#define _utils_utils_h

#include <string>
#include <vector>
#include <map>
#include <set>
#include <TextTable.h>
#include <chrono>
#include "../entrypoint.h"

std::string replace(std::string str, const std::string from, const std::string to);
std::vector<std::string> explode(std::string str, std::string delimiter);
std::set<std::string> explodeToSet(std::string str, std::string delimiter);
std::string implode(std::vector<std::string> elements, std::string delimiter);
std::string ProcessColor(std::string str, int team);
bool ends_with(std::string value, std::string ending);
bool starts_with(std::string value, std::string starting);
void PrintTextTable(std::string category, TextTable table);
uint64_t GetTime();
std::string str_tolower(std::string s);
std::string str_toupper(std::string s);
std::string get_uuid();
std::string TerminalProcessColor(std::string str);
std::string GetTerminalStringColor(std::string plugin_name);

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        return "";

    size_t size = static_cast<size_t>(size_s);
    char* buf = new char[size];
    snprintf(buf, size, format.c_str(), args...);
    std::string out = std::string(buf, buf + size - 1); // We don't want the '\0' inside
    delete buf;
    return out;
}

extern std::map<std::string, std::string> terminalColors;
extern std::vector<std::string> terminalPrefixColors;

#endif