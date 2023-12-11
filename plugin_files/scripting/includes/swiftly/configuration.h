#ifndef _swiftly_configuration_h
#define _swiftly_configuration_h

#include <string>
#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>
#include <any>
#include <cstdarg>

class BaseConfigValue
{
public:
    virtual ~BaseConfigValue() {}
    virtual std::string getType() const = 0;
};

template <typename T>
class TypedConfigValue : public BaseConfigValue
{
public:
    TypedConfigValue(const T &value) : data(value) {}

    T getValue() const
    {
        return data;
    }

    std::string getType() const override
    {
        return typeid(T).name();
    }

private:
    T data;
};

std::any DeserializeConfigData(const char *jsonData);

class Configuration
{
private:
public:
    Configuration() {}

    template <typename T>
    T Fetch(const char *key, ...)
    {
        void *configurationFetch = FetchFunctionPtr(nullptr, "scripting_Configuration_Fetch");
        if (configurationFetch)
        {
            va_list ap;
            char buffer[2048];

            va_start(ap, key);
            UTIL_FormatArgs(buffer, sizeof(buffer), key, ap);
            va_end(ap);

            const char *value = reinterpret_cast<Configuration_Fetch>(configurationFetch)(buffer);

            try
            {
                return std::any_cast<T>(DeserializeConfigData(value));
            }
            catch (std::bad_any_cast err)
            {
                return 0;
            }
        }
        else
            return 0;
    }

    bool Exists(const char *key, ...)
    {
        void *configurationExists = FetchFunctionPtr(nullptr, "scripting_Configuration_Exists");
        if (configurationExists)
        {
            va_list ap;
            char buffer[2048];

            va_start(ap, key);
            UTIL_FormatArgs(buffer, sizeof(buffer), key, ap);
            va_end(ap);
            return reinterpret_cast<Configuration_Exists>(configurationExists)(buffer);
        }
        else
            return false;
    }

    uint32_t FetchArraySize(const char *key, ...)
    {
        void *configurationFetchArraySize = FetchFunctionPtr(nullptr, "scripting_Configuration_FetchArraySize");
        if (configurationFetchArraySize)
        {
            va_list ap;
            char buffer[2048];

            va_start(ap, key);
            UTIL_FormatArgs(buffer, sizeof(buffer), key, ap);
            va_end(ap);
            return reinterpret_cast<Configuration_FetchArraySize>(configurationFetchArraySize)(buffer);
        }
        else
            return 0;
    }
};

extern Configuration *config;

#endif