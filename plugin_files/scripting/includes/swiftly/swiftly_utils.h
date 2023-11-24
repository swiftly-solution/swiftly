#ifndef _swiftly_utils_h
#define _swiftly_utils_h

#include "swiftly_oslink.h"
#include <stdio.h>
#include <sstream>
#include <chrono>

#ifdef _WIN32
#define WIN_LINUX(win, linux) win
#else
#define WIN_LINUX(win, linux) linux
#endif

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

template <typename T>
T string_to_type(const char *str)
{
    std::stringstream strValue(str);
    T val;
    strValue >> val;
    return val;
}

uint64_t GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

#endif