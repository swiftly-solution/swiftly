#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <string>
#include <cstdint>
#include <unordered_map>

std::string SerializeMenuData(std::unordered_map<std::string, std::string> data)
{
    rapidjson::Document document(rapidjson::kArrayType);
    document.SetArray();

    for (std::unordered_map<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it)
    {
        std::string option_title = it->first;
        std::string option_value = it->second;

        rapidjson::Document tempdoc(rapidjson::kArrayType);
        tempdoc.PushBack(rapidjson::Value().SetString(option_title.c_str(), document.GetAllocator()), document.GetAllocator());
        tempdoc.PushBack(rapidjson::Value().SetString(option_value.c_str(), document.GetAllocator()), document.GetAllocator());

        document.PushBack(tempdoc, document.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return std::string(buffer.GetString());
}