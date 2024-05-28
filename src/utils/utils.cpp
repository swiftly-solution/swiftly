#include "utils.h"

#include <cstdarg>

size_t UTIL_FormatArgs(char *buffer, size_t maxlength, const char *fmt, va_list params)
{
    size_t len = vsnprintf(buffer, maxlength, fmt, params);

    if (len >= maxlength)
    {
        len = maxlength - 1;
        buffer[len] = '\0';
    }

    return len;
}

std::string replace(std::string str, const std::string from, const std::string to)
{
    if (from.empty())
        return str;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

std::vector<std::string> explode(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

std::string implode(std::vector<std::string> elements, std::string delimiter)
{
    std::string s;
    for (std::vector<std::string>::iterator ii = elements.begin(); ii != elements.end(); ++ii)
    {
        s += (*ii);
        if (ii + 1 != elements.end())
            s += delimiter;
    }
    return s;
}

bool ends_with(std::string value, std::string ending)
{
    if (value.size() < ending.size())
        return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

bool starts_with(std::string value, std::string starting)
{
    if (value.size() < starting.size())
        return false;
    return std::equal(starting.begin(), starting.end(), value.begin());
}

void PLUGIN_PRINT(std::string category, std::string str)
{
    g_SMAPI->ConPrint((PREFIX " [" + category + "] " + str).c_str());
}

void PLUGIN_PRINTF(std::string category, std::string str, ...)
{
    va_list ap;
    char buffer[4096];

    va_start(ap, str);
    UTIL_FormatArgs(buffer, sizeof(buffer), str.c_str(), ap);
    va_end(ap);

    g_SMAPI->ConPrint((PREFIX " [" + category + "] " + std::string(buffer)).c_str());
}

void PrintTextTable(std::string category, TextTable table)
{
    std::stringstream outputTable;
    outputTable << table;
    std::vector<std::string> rows = explode(outputTable.str(), "\n");
    for (int i = 0; i < rows.size() - 1; i++)
        PLUGIN_PRINTF(category, "%s\n", rows[i].c_str());
}

uint64_t GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}