#include "swiftly_utils.h"
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

uint64_t GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

const char *format(const char *str, ...)
{
    va_list ap;
    char buffer[2048];

    va_start(ap, str);
    UTIL_FormatArgs(buffer, sizeof(buffer), str, ap);
    va_end(ap);

    std::string return_str = buffer;

    return return_str.c_str();
}