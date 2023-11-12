#include "../../../../common.h"
#include "../../../../configuration/Configuration.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

const char *SerializeData(std::any data)
{
    rapidjson::Document document(rapidjson::kObjectType);

    const char *key = "value";
    const std::any &value = data;

    if (value.type() == typeid(const char *))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetString(std::any_cast<const char *>(value), document.GetAllocator()), document.GetAllocator());
    else if (value.type() == typeid(std::string))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetString(std::any_cast<std::string>(value).c_str(), document.GetAllocator()), document.GetAllocator());
    else if (value.type() == typeid(uint64))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint64(std::any_cast<uint64>(value)), document.GetAllocator());
    else if (value.type() == typeid(uint32))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint(std::any_cast<uint32>(value)), document.GetAllocator());
    else if (value.type() == typeid(uint16))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint(std::any_cast<uint16>(value)), document.GetAllocator());
    else if (value.type() == typeid(uint8))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetUint(std::any_cast<uint8>(value)), document.GetAllocator());
    else if (value.type() == typeid(int64))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt64(std::any_cast<int64>(value)), document.GetAllocator());
    else if (value.type() == typeid(int32))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt(std::any_cast<int32>(value)), document.GetAllocator());
    else if (value.type() == typeid(int16))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt(std::any_cast<int16>(value)), document.GetAllocator());
    else if (value.type() == typeid(int8))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetInt(std::any_cast<int8>(value)), document.GetAllocator());
    else if (value.type() == typeid(bool))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetBool(std::any_cast<bool>(value)), document.GetAllocator());
    else if (value.type() == typeid(float))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetFloat(std::any_cast<float>(value)), document.GetAllocator());
    else if (value.type() == typeid(double))
        document.AddMember(rapidjson::Value().SetString(key, document.GetAllocator()), rapidjson::Value().SetDouble(std::any_cast<double>(value)), document.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return buffer.GetString();
}

SMM_API const char *scripting_Configuration_Fetch(const char *key)
{
    if (key == nullptr)
        return "";

    std::map<std::string, std::any> config = g_Config->FetchConfiguration();

    if (config.find(key) == config.end())
        return key;

    std::any value = config.at(key);

    return SerializeData(value);
}