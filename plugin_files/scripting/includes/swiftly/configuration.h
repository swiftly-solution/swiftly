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

std::any DeserializeConfigData(const char *jsonData)
{
    rapidjson::Document document;
    document.Parse(jsonData);

    if (document.HasParseError())
        return GetParseError_En(document.GetParseError());

    if (document["value"].IsString())
        return (new TypedConfigValue<const char *>(document["value"].GetString()))->getValue();
    else if (document["value"].IsInt())
        return (new TypedConfigValue<int>(document["value"].GetInt()))->getValue();
    else if (document["value"].IsInt64())
        return (new TypedConfigValue<int64_t>(document["value"].GetInt64()))->getValue();
    else if (document["value"].IsUint())
        return (new TypedConfigValue<uint32_t>(document["value"].GetUint()))->getValue();
    else if (document["value"].IsUint64())
        return (new TypedConfigValue<uint64_t>(document["value"].GetUint64()))->getValue();
    else if (document["value"].IsBool())
        return (new TypedConfigValue<bool>(document["value"].GetBool()))->getValue();
    else if (document["value"].IsFloat())
        return (new TypedConfigValue<float>(document["value"].GetFloat()))->getValue();
    else if (document["value"].IsDouble())
        return (new TypedConfigValue<double>(document["value"].GetDouble()))->getValue();
    else
        return nullptr;
}

class Configuration
{
private:
public:
    Configuration() {}

    template <typename T>
    T Fetch(const char *key)
    {
        void *configurationFetch = FetchFunctionPtr(nullptr, "scripting_Configuration_Fetch");
        if (configurationFetch)
        {
            const char *value = reinterpret_cast<Configuration_Fetch>(configurationFetch)(key);

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

    uint32_t FetchArraySize(const char *key)
    {
        void *configurationFetchArraySize = FetchFunctionPtr(nullptr, "scripting_Configuration_FetchArraySize");
        if (configurationFetchArraySize)
            return reinterpret_cast<Configuration_FetchArraySize>(configurationFetchArraySize)(key);
        else
            return 0;
    }
};

extern Configuration *config;

#endif