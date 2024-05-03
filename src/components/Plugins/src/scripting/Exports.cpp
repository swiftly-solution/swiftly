#include "../../../../common.h"
#include "../../../../utils/memstr.h"
#include "../../inc/Plugin.h"

#include <vector>
#include <any>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>

std::string SerializeData(std::any data);

std::vector<std::any> DeserializeExportData(const char *jsonData)
{
    rapidjson::Document document(rapidjson::kArrayType);
    document.Parse(jsonData);
    if (document.HasParseError())
    {
        PRINTF("DeserializeExportData", "%s\n", GetParseError_En(document.GetParseError()));
        return {};
    }

    std::vector<std::any> data;

    for (size_t i = 0; i < document.Size(); i++)
    {
        if (document[i].IsString())
            data.push_back(document[i].GetString());
        else if (document[i].IsInt())
            data.push_back(document[i].GetInt());
        else if (document[i].IsInt64())
            data.push_back(document[i].GetInt64());
        else if (document[i].IsUint())
            data.push_back(document[i].GetUint());
        else if (document[i].IsUint64())
            data.push_back(document[i].GetUint64());
        else if (document[i].IsBool())
            data.push_back(document[i].GetBool());
        else if (document[i].IsFloat())
            data.push_back(document[i].GetFloat());
        else if (document[i].IsDouble())
            data.push_back(document[i].GetDouble());
        else
            data.push_back(nullptr);
    }

    return data;
}

std::string SerializeExportData(std::vector<std::any> data)
{
    rapidjson::Document document(rapidjson::kArrayType);

    for (std::any value : data)
    {
        if (value.type() == typeid(const char *))
            document.PushBack(rapidjson::Value().SetString(std::any_cast<const char *>(value), document.GetAllocator()), document.GetAllocator());
        else if (value.type() == typeid(std::string))
            document.PushBack(rapidjson::Value().SetString(std::any_cast<std::string>(value).c_str(), document.GetAllocator()), document.GetAllocator());
        else if (value.type() == typeid(uint64_t))
            document.PushBack(rapidjson::Value().SetUint64(std::any_cast<uint64_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(uint32_t))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<uint32_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(unsigned long))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<unsigned long>(value)), document.GetAllocator());
        else if (value.type() == typeid(uint16_t))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<uint16_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(uint8_t))
            document.PushBack(rapidjson::Value().SetUint(std::any_cast<uint8_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(int64_t))
            document.PushBack(rapidjson::Value().SetInt64(std::any_cast<int64_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(int32_t))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<int32_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(long))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<long>(value)), document.GetAllocator());
        else if (value.type() == typeid(int16_t))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<int16_t>(value)), document.GetAllocator());
        else if (value.type() == typeid(char))
            document.PushBack(rapidjson::Value().SetInt(std::any_cast<char>(value)), document.GetAllocator());
        else if (value.type() == typeid(bool))
            document.PushBack(rapidjson::Value().SetBool(std::any_cast<bool>(value)), document.GetAllocator());
        else if (value.type() == typeid(float))
            document.PushBack(rapidjson::Value().SetFloat(std::any_cast<float>(value)), document.GetAllocator());
        else if (value.type() == typeid(long long))
            document.PushBack(rapidjson::Value().SetInt64(std::any_cast<long long>(value)), document.GetAllocator());
        else if (value.type() == typeid(unsigned long long))
            document.PushBack(rapidjson::Value().SetUint64(std::any_cast<unsigned long long>(value)), document.GetAllocator());
        else if (value.type() == typeid(double))
            document.PushBack(rapidjson::Value().SetDouble(std::any_cast<double>(value)), document.GetAllocator());
        else
        {
            PRINTF("SerializeExportData", "Invalid type: %s\n", value.type().name());
            document.PushBack(rapidjson::Value().SetNull(), document.GetAllocator());
        }
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return std::string(buffer.GetString());
}

std::any DeserializeExpData(const char *jsonData)
{
    rapidjson::Document document;
    document.Parse(jsonData);

    if (document.HasParseError())
        return GetParseError_En(document.GetParseError());

    if (document["value"].IsString())
        return document["value"].GetString();
    else if (document["value"].IsInt())
        return document["value"].GetInt();
    else if (document["value"].IsInt64())
        return document["value"].GetInt64();
    else if (document["value"].IsUint())
        return document["value"].GetUint();
    else if (document["value"].IsUint64())
        return document["value"].GetUint64();
    else if (document["value"].IsBool())
        return document["value"].GetBool();
    else if (document["value"].IsFloat())
        return document["value"].GetFloat();
    else if (document["value"].IsDouble())
        return document["value"].GetDouble();
    else
        return nullptr;
}

SMM_API const char *scripting_Exports_Call(const char *plugin_name, const char *export_name, const char *jsonData)
{
    if (plugin_name == nullptr || export_name == nullptr || jsonData == nullptr)
        return "{\"value\":null}";

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    if (!plugin)
        return "{\"value\":null}";
    if (!plugin->IsPluginLoaded() || plugin->GetPluginType() == PluginType_t::PLUGIN_CPP)
        return "{\"value\":null}";

    std::vector<std::any> data = DeserializeExportData(jsonData);

    std::any retval = plugin->ExecuteExport(export_name, data);
    std::string jsonRetData = SerializeData(retval);

    MemStr str(jsonRetData);
    return str.Get();
}

SMM_API void scripting_Exports_Register(const char *plugin_name, const char *export_name, void *functionPtr)
{
    if (plugin_name == nullptr || export_name == nullptr || functionPtr == nullptr)
        return;

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    plugin->RegisterExport(export_name, functionPtr);
}

SMM_API void scripting_Exports_Unregister(const char *plugin_name, const char *export_name)
{
    if (plugin_name == nullptr || export_name == nullptr)
        return;

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    plugin->UnregisterExport(export_name);
}