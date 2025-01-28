#include "utils.h"

#include <cstdarg>
#include <random>
#include <sstream>
#include <chrono>
#include <public/tier1/characterset.h>

#include "../sdk/schema/schema.h"
#include "../server/configuration/Configuration.h"
#include "../filesystem/logs/Logger.h"

const char* wws = " \t\n\r\f\v";

std::map<std::string, std::string> terminalColors = {
    {"{DEFAULT}", WIN_LINUX("\033[38;2;255;255;255m", "\e[39m")},
    {"{WHITE}", WIN_LINUX("\033[38;2;255;255;255m", "\e[39m")},
    {"{DARKRED}", WIN_LINUX("\x1B[31m", "\e[31m")},
    {"{LIGHTPURPLE}", WIN_LINUX("\x1B[95m", "\e[95m")},
    {"{GREEN}", WIN_LINUX("\x1B[32m", "\e[32m")},
    {"{OLIVE}", WIN_LINUX("\x1B[33m", "\e[33m")},
    {"{LIME}", WIN_LINUX("\x1B[92m", "\e[92m")},
    {"{RED}", WIN_LINUX("\x1B[31m", "\e[31m")},
    {"{GRAY}", WIN_LINUX("\x1B[37m", "\e[37m")},
    {"{GREY}", WIN_LINUX("\x1B[37m", "\e[37m")},
    {"{LIGHTYELLOW}", WIN_LINUX("\x1B[93m", "\e[93m")},
    {"{YELLOW}", WIN_LINUX("\x1B[93m", "\e[93m")},
    {"{SILVER}", WIN_LINUX("\x1B[37m", "\e[37m")},
    {"{BLUEGREY}", WIN_LINUX("\x1B[94m", "\e[94m")},
    {"{LIGHTBLUE}", WIN_LINUX("\x1B[94m", "\e[94m")},
    {"{BLUE}", WIN_LINUX("\x1B[34m", "\e[34m")},
    {"{DARKBLUE}", WIN_LINUX("\x1B[34m", "\e[34m")},
    {"{PURPLE}", WIN_LINUX("\x1B[35m", "\e[35m")},
    {"{MAGENTA}", WIN_LINUX("\x1B[35m", "\e[35m")},
    {"{LIGHTRED}", WIN_LINUX("\x1B[91m", "\e[91m")},
    {"{GOLD}", WIN_LINUX("\x1B[93m", "\e[93m")},
    {"{ORANGE}", WIN_LINUX("\x1B[33m", "\e[33m")},

    {"{BGDEFAULT}", WIN_LINUX("\x1B[40m", "\e[40m")},
    {"{BGDARKRED}", WIN_LINUX("\x1B[41m", "\e[41m")},
    {"{BGLIGHTPURPLE}", WIN_LINUX("\x1B[105m", "\e[105m")},
    {"{BGGREEN}", WIN_LINUX("\x1B[42m", "\e[42m")},
    {"{BGOLIVE}", WIN_LINUX("\x1B[43m", "\e[43m")},
    {"{BGLIME}", WIN_LINUX("\x1B[102m", "\e[102m")},
    {"{BGRED}", WIN_LINUX("\x1B[41m", "\e[41m")},
    {"{BGGRAY}", WIN_LINUX("\x1B[47m", "\e[47m")},
    {"{BGGREY}", WIN_LINUX("\x1B[47m", "\e[47m")},
    {"{BGLIGHTYELLOW}", WIN_LINUX("\x1B[103m", "\e[103m")},
    {"{BGYELLOW}", WIN_LINUX("\x1B[103m", "\e[103m")},
    {"{BGSILVER}", WIN_LINUX("\x1B[47m", "\e[47m")},
    {"{BGBLUEGREY}", WIN_LINUX("\x1B[104m", "\e[104m")},
    {"{BGLIGHTBLUE}", WIN_LINUX("\x1B[104m", "\e[104m")},
    {"{BGBLUE}", WIN_LINUX("\x1B[44m", "\e[44m")},
    {"{BGDARKBLUE}", WIN_LINUX("\x1B[44m", "\e[44m")},
    {"{BGPURPLE}", WIN_LINUX("\x1B[45m", "\e[45m")},
    {"{BGMAGENTA}", WIN_LINUX("\x1B[45m", "\e[45m")},
    {"{BGLIGHTRED}", WIN_LINUX("\x1B[101m", "\e[101m")},
    {"{BGGOLD}", WIN_LINUX("\x1B[103m", "\e[103m")},
    {"{BGORANGE}", WIN_LINUX("\x1B[43m", "\e[43m")},
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
    return terminalColors[terminalPrefixColors[steps]];
}

size_t UTIL_FormatArgs(char* buffer, size_t maxlength, const char* fmt, va_list params)
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
    if(s.size() == 0) return {};
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

std::set<std::string> explodeToSet(std::string str, std::string delimiter)
{
    if(str.size() == 0) return {};
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::set<std::string> res;

    while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
    {
        token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.insert(token);
    }

    res.insert(str.substr(pos_start));
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
    std::string final_string = string_format("%s %s[%s]%s %s", PREFIX, GetTerminalStringColor(category).c_str(), category.c_str(), terminalColors.at("{DEFAULT}").c_str(), str.c_str());
    META_CONPRINT(final_string.c_str());

    if (g_Config && g_Config->FetchValue<bool>("core.logging.save_core_messages")) {
        if (g_Logger && g_Logger->FetchLogger("core")) {
            str.pop_back();
            g_Logger->FetchLogger("core")->WriteLog(LogType_t::Common, "[" + category + "] " + str);
        }
    }
}

void PLUGIN_PRINTF(std::string category, std::string str, ...)
{
    va_list ap;
    char buffer[8192];

    va_start(ap, str);
    UTIL_FormatArgs(buffer, sizeof(buffer), str.c_str(), ap);
    va_end(ap);

    std::string final_string = string_format("%s %s[%s]%s %s", PREFIX, GetTerminalStringColor(category).c_str(), category.c_str(), terminalColors.at("{DEFAULT}").c_str(), buffer);
    META_CONPRINT(final_string.c_str());

    if (g_Config && g_Config->FetchValue<bool>("core.logging.save_core_messages")) {
        if (g_Logger && g_Logger->FetchLogger("core")) {
            std::string buf = buffer;
            buf.pop_back();
            g_Logger->FetchLogger("core")->WriteLog(LogType_t::Common, "[" + category + "] " + buf);
        }
    }
}

void PrintTextTable(std::string category, TextTable table)
{
    std::stringstream outputTable;
    outputTable << table;
    std::vector<std::string> rows = explode(outputTable.str(), "\n");
    for (size_t i = 0; i < rows.size() - 1; i++)
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

int32_t genrand()
{
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    return std::uniform_int_distribution<int>(0, INT_MAX)(rng);
}

std::string get_uuid()
{
    return string_format(
        "%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
        (genrand() & 0xFFFF), (genrand() & 0xFFFF),
        (genrand() & 0xFFFF),
        ((genrand() & 0x0fff) | 0x4000),
        (genrand() % 0x3fff + 0x8000),
        (genrand() & 0xFFFF), (genrand() & 0xFFFF), (genrand() & 0xFFFF));
}

characterset_t cset{""};

std::vector<std::string> TokenizeCommand(std::string cmd)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(cmd.c_str(), &cset);

    std::vector<std::string> cmdString;
    for (int i = 0; i < tokenizedArgs.ArgC(); i++)
        cmdString.push_back(tokenizedArgs[i]);

    return cmdString;
}