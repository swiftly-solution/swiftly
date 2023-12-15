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

int StringToInt(const char *str)
{
    int retval;
    try
    {
        retval = std::stoi(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

unsigned int StringToUInt(const char *str)
{
    unsigned int retval;
    try
    {
        retval = (unsigned int)std::strtoul(str, nullptr, 10);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

float StringToFloat(const char *str)
{
    float retval;
    try
    {
        retval = std::stof(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1.0f;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1.0f;
    }
    return retval;
}

double StringToDouble(const char *str)
{
    double retval;
    try
    {
        retval = std::stod(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1.0f;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1.0f;
    }
    return retval;
}

long StringToLong(const char *str)
{
    long retval;
    try
    {
        retval = std::stol(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

long long StringToLongLong(const char *str)
{
    long long retval;
    try
    {
        retval = std::stoll(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

unsigned long StringToULong(const char *str)
{
    unsigned long retval;
    try
    {
        retval = std::stoul(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

unsigned long long StringToULongLong(const char *str)
{
    unsigned long long retval;
    try
    {
        retval = std::stoull(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

short StringToShort(const char *str)
{
    short retval;
    try
    {
        retval = (short)std::stol(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

unsigned short StringToUShort(const char *str)
{
    unsigned short retval;
    try
    {
        retval = (unsigned short)std::stoul(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}
