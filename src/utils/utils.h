#ifndef _utils_utils_h
#define _utils_utils_h

#include <string>
#include <vector>
#include <set>
#include <map>
#include <texttable/TextTable.h>

constexpr uint32_t val_32_const = 0x811c9dc5;
constexpr uint32_t prime_32_const = 0x1000193;
constexpr uint64_t val_64_const = 0xcbf29ce484222325;
constexpr uint64_t prime_64_const = 0x100000001b3;

inline constexpr uint32_t hash_32_fnv1a_const(const char* const str, const uint32_t value = val_32_const) noexcept
{
    return (str[0] == '\0') ? value : hash_32_fnv1a_const(&str[1], (value ^ uint32_t(str[0])) * prime_32_const);
}

inline constexpr uint64_t hash_64_fnv1a_const(const char* const str, const uint64_t value = val_64_const) noexcept
{
    return (str[0] == '\0') ? value : hash_64_fnv1a_const(&str[1], (value ^ uint64_t(str[0])) * prime_64_const);
}

std::string replace(std::string str, const std::string from, const std::string to);
std::vector<std::string> explode(std::string str, std::string delimiter);
std::set<std::string> explodeToSet(std::string str, std::string delimiter);
std::string implode(std::vector<std::string> elements, std::string delimiter);
std::string ProcessColor(std::string str, int team);
bool ends_with(std::string value, std::string ending);
bool starts_with(std::string value, std::string starting);
uint64_t GetTime();
std::string str_tolower(std::string s);
std::string str_toupper(std::string s);
std::string get_uuid();
std::string TerminalProcessColor(std::string str);
std::string GetTerminalStringColor(std::string plugin_name);
std::vector<std::string> TokenizeCommand(std::string cmd);
void PrintTextTable(std::string category, TextTable table);

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

void* StringToPtr(std::string str);
std::string PtrToString(void* ptr);

#endif