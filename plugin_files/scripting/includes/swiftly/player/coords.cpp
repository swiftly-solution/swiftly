#include "coords.h"

std::map<std::string, float> DeserializeCoordsData(const char *jsonData)
{
    rapidjson::Document document;
    document.Parse(jsonData);

    if (!document["value"].IsObject())
        return {};

    std::map<std::string, float> coords;

    coords.insert(std::make_pair("x", document["value"]["x"].GetFloat()));
    coords.insert(std::make_pair("y", document["value"]["y"].GetFloat()));
    coords.insert(std::make_pair("z", document["value"]["z"].GetFloat()));

    return coords;
}