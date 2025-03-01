#include "json.h"

std::string encoders::json::SerializeArrayToString(std::vector<std::any> v)
{
    rapidjson::Document document(rapidjson::kArrayType);

    for (const auto& val : v)
    {
        const std::any& value = val;

        if (value.type() == typeid(const char*))
            document.PushBack(rapidjson::Value().SetString(std::any_cast<const char*>(value), document.GetAllocator()), document.GetAllocator());
        else if (value.type() == typeid(std::string))
            document.PushBack(rapidjson::Value().SetString(std::any_cast<std::string>(value).c_str(), document.GetAllocator()), document.GetAllocator());
        else if (value.type() == typeid(uint64_t))
            document.PushBack(rapidjson::Value().SetUint64(std::any_cast<uint64_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(uint32_t))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<uint32_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(uint16_t))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<uint16_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(uint8_t))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<uint8_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(int64_t))
            document.PushBack(rapidjson::Value().SetInt64(std::any_cast<int64_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(int32_t))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<int32_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(int16_t))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<int16_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(int8_t))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<int8_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(bool))
            document.PushBack(rapidjson::Value().SetBool(std::any_cast<bool>(value)), document.GetAllocator());
        else if (value.type() == typeid(float))
            document.PushBack(rapidjson::Value().SetFloat(std::any_cast<float>(value)), document.GetAllocator());
        else if (value.type() == typeid(double))
            document.PushBack(rapidjson::Value().SetDouble(std::any_cast<double>(value)), document.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return std::string(buffer.GetString());
}