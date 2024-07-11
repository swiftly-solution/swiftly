#include "utils.h"

#include <cstdarg>
#include <random>
#include <sstream>

#include "../sdk/schema.h"

std::map<std::string, std::string> terminalColors = {
    {"{DEFAULT}", "\e[39m"},
    {"{WHITE}", "\e[39m"},
    {"{DARKRED}", "\e[31m"},
    {"{LIGHTPURPLE}", "\e[95m"},
    {"{GREEN}", "\e[32m"},
    {"{OLIVE}", "\e[33m"},
    {"{LIME}", "\e[92m"},
    {"{RED}", "\e[31m"},
    {"{GRAY}", "\e[37m"},
    {"{GREY}", "\e[37m"},
    {"{LIGHTYELLOW}", "\e[93m"},
    {"{YELLOW}", "\e[93m"},
    {"{SILVER}", "\e[37m"},
    {"{BLUEGREY}", "\e[94m"},
    {"{LIGHTBLUE}", "\e[94m"},
    {"{BLUE}", "\e[34m"},
    {"{DARKBLUE}", "\e[34m"},
    {"{PURPLE}", "\e[35m"},
    {"{MAGENTA}", "\e[35m"},
    {"{LIGHTRED}", "\e[91m"},
    {"{GOLD}", "\e[93m"},
    {"{ORANGE}", "\e[33m"},

    {"{BGDEFAULT}", "\e[49m"},
    {"{BGWHITE}", "\e[49m"},
    {"{BGDARKRED}", "\e[41m"},
    {"{BGLIGHTPURPLE}", "\e[105m"},
    {"{BGGREEN}", "\e[42m"},
    {"{BGOLIVE}", "\e[43m"},
    {"{BGLIME}", "\e[102m"},
    {"{BGRED}", "\e[41m"},
    {"{BGGRAY}", "\e[47m"},
    {"{BGGREY}", "\e[47m"},
    {"{BGLIGHTYELLOW}", "\e[103m"},
    {"{BGYELLOW}", "\e[103m"},
    {"{BGSILVER}", "\e[47m"},
    {"{BGBLUEGREY}", "\e[104m"},
    {"{BGLIGHTBLUE}", "\e[104m"},
    {"{BGBLUE}", "\e[44m"},
    {"{BGDARKBLUE}", "\e[44m"},
    {"{BGPURPLE}", "\e[45m"},
    {"{BGMAGENTA}", "\e[45m"},
    {"{BGLIGHTRED}", "\e[101m"},
    {"{BGGOLD}", "\e[103m"},
    {"{BGORANGE}", "\e[43m"},
};

std::vector<std::string> terminalPrefixColors = {
    "{DEFAULT}",
    "{WHITE}",
    "{DARKRED}",
    "{LIGHTPURPLE}",
    "{GREEN}",
    "{OLIVE}",
    "{LIME}",
    "{RED}",
    "{LIGHTYELLOW}",
    "{YELLOW}",
    "{BLUEGREY}",
    "{LIGHTBLUE}",
    "{BLUE}",
    "{DARKBLUE}",
    "{PURPLE}",
    "{MAGENTA}",
    "{LIGHTRED}",
    "{GOLD}",
    "{ORANGE}",
};

std::string TerminalProcessColor(std::string str)
{
    for (auto it = terminalColors.begin(); it != terminalColors.end(); ++it)
    {
        str = replace(str, it->first, it->second);
        str = replace(str, str_tolower(it->first), it->second);
    }
    return str;
}

std::string GetTerminalStringColor(std::string plugin_name)
{
    auto hash = hash_64_fnv1a_const(plugin_name.c_str());
    uint64_t steps = (hash % terminalPrefixColors.size());
    return terminalColors.at(terminalPrefixColors[steps]);
}

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
    g_SMAPI->ConPrint((PREFIX " " + GetTerminalStringColor(category) + "[" + category + "]\e[39m " + str).c_str());
}

void PLUGIN_PRINTF(std::string category, std::string str, ...)
{
    va_list ap;
    char buffer[4096];

    va_start(ap, str);
    UTIL_FormatArgs(buffer, sizeof(buffer), str.c_str(), ap);
    va_end(ap);

    g_SMAPI->ConPrint((PREFIX " " + GetTerminalStringColor(category) + "[" + category + "]\e[39m " + std::string(buffer)).c_str());
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

std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    return s;
}

std::string str_toupper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                   { return std::toupper(c); });
    return s;
}

std::string get_uuid()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const char *v = "0123456789abcdef";
    const bool dash[] = {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0};

    std::string res;
    for (int i = 0; i < 16; i++)
    {
        if (dash[i])
            res += "-";
        res += v[dist(rng)];
        res += v[dist(rng)];
    }
    return res;
}