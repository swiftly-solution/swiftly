#ifndef _swiftly_utils_h
#define _swiftly_utils_h

#include "swiftly_oslink.h"
#include <stdio.h>
#include <sstream>
#include <chrono>
#include <memory>
#include <cstdint>
#include <string>

#ifdef _WIN32
#define WIN_LINUX(win, linux) win
#else
#define WIN_LINUX(win, linux) linux
#endif

void print(const char *str, ...);
#define NOT_SUPPORTED(func_name) print("[Swiftly] This version of Swiftly is not supporting %s.\n", func_name)

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
int StringToInt(const char *str);
unsigned int StringToUInt(const char *str);
float StringToFloat(const char *str);
double StringToDouble(const char *str);
long StringToLong(const char *str);
long long StringToLongLong(const char *str);
unsigned long StringToULong(const char *str);
unsigned long long StringToULongLong(const char *str);
short StringToShort(const char *str);
unsigned short StringToUShort(const char *str);

const char *ToUpper(const std::string &str);
const char *ToLower(const std::string &str);

#endif