#include "colors.h"

std::map<std::string, int> DeserializeColorData(const char *jsonData)
{
    rapidjson::Document document;
    document.Parse(jsonData);

    if (!document["value"].IsObject())
        return {};

    std::map<std::string, int> colors;

    colors.insert(std::make_pair("r", document["value"]["r"].GetInt()));
    colors.insert(std::make_pair("g", document["value"]["g"].GetInt()));
    colors.insert(std::make_pair("b", document["value"]["b"].GetInt()));
    colors.insert(std::make_pair("a", document["value"]["a"].GetInt()));

    return colors;
}