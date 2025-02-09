#include "../../scripting.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

PluginConfiguration::PluginConfiguration(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

bool PluginConfiguration::Exists(std::string key)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConfiguration::Exists(key=\"%s\")", key.c_str()));

    std::map<std::string, std::any> config = g_Config->FetchPluginConfiguration();
    return (config.find(key) != config.end());
}

void PluginConfiguration::Reload(std::string key)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConfiguration::Reload(key=\"%s\")", key.c_str()));

    g_Config->LoadPluginConfig(key);
}

uint64_t PluginConfiguration::FetchArraySize(std::string key)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConfiguration::FetchArraySize(key=\"%s\")", key.c_str()));

    std::map<std::string, unsigned int> arraySizes = g_Config->FetchConfigArraySizes();

    if (arraySizes.find(key) == arraySizes.end())
        return 0;

    return arraySizes[key];
}

std::any PluginConfiguration::Fetch(std::string key)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConfiguration::Fetch(key=\"%s\")", key.c_str()));

    std::map<std::string, std::any> config = g_Config->FetchPluginConfiguration();

    return config[key];
}

void ParseAndFillConfiguration(rapidjson::Value& initDoc, rapidjson::Value& config, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>& allocator, bool& wasEdited)
{
    for (auto it = initDoc.MemberBegin(); it != initDoc.MemberEnd(); ++it)
    {
        const char* key = it->name.GetString();
        if (!config.HasMember(key))
        {
            config.AddMember(it->name, initDoc[key], allocator);
            wasEdited = true;
        }
        else if (config[key].IsObject() && initDoc[key].IsObject())
        {
            ParseAndFillConfiguration(initDoc[key], config[key], allocator, wasEdited);
        }
    }
}

void PluginConfiguration::Create(std::string configurationKey, EValue table, EContext* L)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConfiguration::Create(configurationKey=\"%s\")", configurationKey.c_str()));
    rapidjson::Document doc(rapidjson::kObjectType);
    if (!table.isTable())
        throw std::runtime_error("2nd argument needs to be a table.");

    std::string jsonResult = "";

    if(L->GetKind() == ContextKinds::Lua) {
        EValue rapidJsonTable = EValue::getGlobal(L, "json");
        if (!rapidJsonTable["encode"].isFunction())
            return;

        EValue encodedResult(L);
        try
        {
            encodedResult = rapidJsonTable["encode"](table);
        }
        catch (EException& e)
        {
            PLUGIN_PRINTF("Configuration - Create", "An error has occured: %s\n", e.what());
            return;
        }

        if (encodedResult.isNull())
            return;

        jsonResult = encodedResult.cast<std::string>();
    } else if(L->GetKind() == ContextKinds::JavaScript) {
        jsonResult = EValue(L, JS_JSONStringify((JSContext*)L->GetState(), table.pushJS(), JS_NULL, JS_NULL)).cast<std::string>();
    }

    doc.Parse(jsonResult.c_str());
    if (Files::ExistsPath("addons/swiftly/configs/plugins/" + configurationKey + ".json"))
    {
        std::string key = replace(configurationKey, "/", ".");
        key = replace(configurationKey, "\\", ".");

        if (g_Config->HasKey(key))
        {
            rapidjson::Document configFile;
            configFile.Parse(Files::Read("addons/swiftly/configs/plugins/" + configurationKey + ".json").c_str());
            if (configFile.HasParseError())
            {
                throw std::runtime_error(string_format("An error has occured while parsing \"addons/swiftly/configs/plugins/%s.json\".\nError: Error (offset %u): %s\n", configurationKey.c_str(), (unsigned)configFile.GetErrorOffset(), GetParseError_En(configFile.GetParseError())));
            }

            bool wasEdited = false;

            ParseAndFillConfiguration(doc, configFile, configFile.GetAllocator(), wasEdited);

            if (wasEdited)
            {
                WritePluginFile("addons/swiftly/configs/plugins/" + configurationKey + ".json", configFile);
                g_Config->LoadPluginConfig(configurationKey);
            }
        }
        else
            g_Config->LoadPluginConfig(configurationKey);
    }
    else
    {
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);

        doc.Accept(writer);
        std::string content = buffer.GetString();

        Files::Write("addons/swiftly/configs/plugins/" + configurationKey + ".json", content, false);
        g_Config->LoadPluginConfig(configurationKey);
    }
}