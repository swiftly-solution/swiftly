#include "common.h"
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