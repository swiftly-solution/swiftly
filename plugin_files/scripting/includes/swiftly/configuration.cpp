#include "configuration.h"

std::any DeserializeConfigData(const char *jsonData)
{
    rapidjson::Document document;
    document.Parse(jsonData);

    if (document.HasParseError())
        return GetParseError_En(document.GetParseError());

    if (document["value"].IsString())
        return (new TypedConfigValue<std::string>(document["value"].GetString()))->getValue().c_str();
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