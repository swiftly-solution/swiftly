#ifndef _swiftly_utils_h
#define _swiftly_utils_h

#include "swiftly_oslink.h"
#include <stdio.h>
#include <sstream>
#include <chrono>
#include <memory>

#ifdef _WIN32
#define WIN_LINUX(win, linux) win
#else
#define WIN_LINUX(win, linux) linux
#endif

size_t UTIL_FormatArgs(char *buffer, size_t maxlength, const char *fmt, va_list params);
uint64_t GetTime();

template <typename T>
T string_to_type(const char *str)
{
    std::stringstream strValue(str);
    T val;
    strValue >> val;
    return val;
}

const char *format(const char *str, ...);

#endif