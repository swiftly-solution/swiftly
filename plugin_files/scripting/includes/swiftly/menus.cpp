#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <vector>

std::string SerializeMenuData(std::vector<std::pair<std::string, std::string>> data)
{
    rapidjson::Document document(rapidjson::kArrayType);
    document.SetArray();

    for (const std::pair<std::string, std::string> entry : data)
    {
        std::string option_title = entry.first;
        std::string option_value = entry.second;

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
