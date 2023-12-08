#include "vars.h"

std::any DeserializeVarsData(const char *jsonData)
{
    rapidjson::Document document;
    document.Parse(jsonData);

    if (document["value"].IsString())
        return (new TypedVarsValue<const char *>(document["value"].GetString()))->getValue();
    else if (document["value"].IsInt())
        return (new TypedVarsValue<int>(document["value"].GetInt()))->getValue();
    else if (document["value"].IsInt64())
        return (new TypedVarsValue<int64_t>(document["value"].GetInt64()))->getValue();
    else if (document["value"].IsUint())
        return (new TypedVarsValue<uint32_t>(document["value"].GetUint()))->getValue();
    else if (document["value"].IsUint64())
        return (new TypedVarsValue<uint64_t>(document["value"].GetUint64()))->getValue();
    else if (document["value"].IsBool())
        return (new TypedVarsValue<bool>(document["value"].GetBool()))->getValue();
    else if (document["value"].IsFloat())
        return (new TypedVarsValue<float>(document["value"].GetFloat()))->getValue();
    else if (document["value"].IsDouble())
        return (new TypedVarsValue<double>(document["value"].GetDouble()))->getValue();
    else
        return nullptr;
}