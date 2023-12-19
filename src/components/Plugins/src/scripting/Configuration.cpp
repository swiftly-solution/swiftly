#include "../../../../common.h"
#include "../../../../configuration/Configuration.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

std::string SerializeData(std::any data)
{
    rapidjson::Document document(rapidjson::kObjectType);

    const char *key = "value";
    const std::any &value = data;
    rapidjson::Value &keyVal = rapidjson::Value().SetString(key, document.GetAllocator());

    if (value.type() == typeid(const char *))
        document.AddMember(keyVal, rapidjson::Value().SetString(std::any_cast<const char *>(value), document.GetAllocator()), document.GetAllocator());
    else if (value.type() == typeid(std::string))
        document.AddMember(keyVal, rapidjson::Value().SetString(std::any_cast<std::string>(value).c_str(), document.GetAllocator()), document.GetAllocator());
    else if (value.type() == typeid(uint64))
        document.AddMember(keyVal, rapidjson::Value().SetUint64(std::any_cast<uint64>(value)), document.GetAllocator());
    else if (value.type() == typeid(uint32))
        document.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<uint32>(value)), document.GetAllocator());
    else if (value.type() == typeid(unsigned long))
        document.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<unsigned long>(value)), document.GetAllocator());
    else if (value.type() == typeid(uint16))
        document.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<uint16>(value)), document.GetAllocator());
    else if (value.type() == typeid(uint8))
        document.AddMember(keyVal, rapidjson::Value().SetUint(std::any_cast<uint8>(value)), document.GetAllocator());
    else if (value.type() == typeid(int64))
        document.AddMember(keyVal, rapidjson::Value().SetInt64(std::any_cast<int64>(value)), document.GetAllocator());
    else if (value.type() == typeid(int32))
        document.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<int32>(value)), document.GetAllocator());
    else if (value.type() == typeid(long))
        document.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<long>(value)), document.GetAllocator());
    else if (value.type() == typeid(int16))
        document.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<int16>(value)), document.GetAllocator());
    else if (value.type() == typeid(int8))
        document.AddMember(keyVal, rapidjson::Value().SetInt(std::any_cast<int8>(value)), document.GetAllocator());
    else if (value.type() == typeid(bool))
        document.AddMember(keyVal, rapidjson::Value().SetBool(std::any_cast<bool>(value)), document.GetAllocator());
    else if (value.type() == typeid(float))
        document.AddMember(keyVal, rapidjson::Value().SetFloat(std::any_cast<float>(value)), document.GetAllocator());
    else if (value.type() == typeid(double))
        document.AddMember(keyVal, rapidjson::Value().SetDouble(std::any_cast<double>(value)), document.GetAllocator());
    else if (value.type() == typeid(Vector))
    {
        rapidjson::Value coords(rapidjson::kObjectType);
        Vector crd = std::any_cast<Vector>(value);

        coords.AddMember("x", rapidjson::Value().SetFloat(crd.x), document.GetAllocator());
        coords.AddMember("y", rapidjson::Value().SetFloat(crd.y), document.GetAllocator());
        coords.AddMember("z", rapidjson::Value().SetFloat(crd.z), document.GetAllocator());

        document.AddMember(keyVal, coords, document.GetAllocator());
    }
    else if (value.type() == typeid(QAngle))
    {
        rapidjson::Value coords(rapidjson::kObjectType);
        QAngle crd = std::any_cast<QAngle>(value);

        coords.AddMember("x", rapidjson::Value().SetFloat(crd.x), document.GetAllocator());
        coords.AddMember("y", rapidjson::Value().SetFloat(crd.y), document.GetAllocator());
        coords.AddMember("z", rapidjson::Value().SetFloat(crd.z), document.GetAllocator());

        document.AddMember(keyVal, coords, document.GetAllocator());
    }
    else if (value.type() == typeid(Color))
    {
        rapidjson::Value colors(rapidjson::kObjectType);
        Color color = std::any_cast<Color>(value);

        colors.AddMember("r", rapidjson::Value().SetInt(color.r()), document.GetAllocator());
        colors.AddMember("g", rapidjson::Value().SetInt(color.g()), document.GetAllocator());
        colors.AddMember("b", rapidjson::Value().SetInt(color.b()), document.GetAllocator());
        colors.AddMember("a", rapidjson::Value().SetInt(color.a()), document.GetAllocator());

        document.AddMember(keyVal, colors, document.GetAllocator());
    }
    else
        PRINTF("SerializeData", "Unknown Data Type: %s\n", value.type().name());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return std::string(buffer.GetString());
}

SMM_API const char *scripting_Configuration_Fetch(const char *key)
{
    if (key == nullptr)
        return "";

    std::map<std::string, std::any> config = g_Config->FetchConfiguration();

    if (config.find(key) == config.end())
    {
        std::string data = SerializeData(key);
        char *result = new char[data.size() + 1];
        strcpy(result, data.c_str());
        return result;
    }

    std::any value = config.at(key);
    std::string data = SerializeData(value);

    char *result = new char[data.size() + 1];
    strcpy(result, data.c_str());
    return result;
}

SMM_API uint32 scripting_Configuration_FetchArraySize(const char *key)
{
    if (key == nullptr)
        return 0;

    std::map<std::string, unsigned int> arraySizes = g_Config->FetchConfigArraySizes();

    if (arraySizes.find(key) == arraySizes.end())
        return 0;

    return arraySizes.at(key);
}

SMM_API bool scripting_Configuration_Exists(const char *key)
{
    if (key == nullptr)
        return false;

    std::map<std::string, std::any> config = g_Config->FetchConfiguration();
    return (config.find(key) != config.end());
}