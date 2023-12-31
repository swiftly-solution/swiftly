#include "Configuration.h"
#include "../files/Files.h"

#include "../utils.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#define HAS_MEMBER(FILE, DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT.HasMember(MEMBER_NAME))                    \
    return ConfigurationError(FILE, string_format("The field \"%s\" doesn't exists.", MEMBER_PATH))

#define IS_OBJECT(FILE, DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsObject())                  \
    return ConfigurationError(FILE, string_format("The field \"%s\" is not an object.", MEMBER_PATH))
#define IS_ARRAY(FILE, DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsArray())                  \
    return ConfigurationError(FILE, string_format("The field \"%s\" is not an array.", MEMBER_PATH))
#define IS_STRING(FILE, DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsString())                  \
    return ConfigurationError(FILE, string_format("The field \"%s\" is not a string.", MEMBER_PATH))
#define IS_BOOL(FILE, DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsBool())                  \
    return ConfigurationError(FILE, string_format("The field \"%s\" is not a boolean.", MEMBER_PATH))

bool ConfigurationError(std::string configuration_file, std::string error)
{
    if (!g_SMAPI)
        return false;

    PRINTF("Configurations", "Error: %s: %s\n", configuration_file.c_str(), error.c_str());
    return false;
}

bool Configuration::LoadConfiguration()
{
    rapidjson::Document coreConfigFile;
    coreConfigFile.Parse(Files::Read("addons/swiftly/configs/core.json").c_str());
    if (coreConfigFile.HasParseError())
        return ConfigurationError("core.json", string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)coreConfigFile.GetErrorOffset(), GetParseError_En(coreConfigFile.GetParseError())));

    if (coreConfigFile.IsArray())
        return ConfigurationError("core.json", "Core configuration file cannot be an array.");

    HAS_MEMBER("core.json", coreConfigFile, "logging", "logging");
    IS_OBJECT("core.json", coreConfigFile, "logging", "logging");
    HAS_MEMBER("core.json", coreConfigFile["logging"], "enabled", "logging.enabled");
    IS_BOOL("core.json", coreConfigFile["logging"], "enabled", "logging.enabled");
    HAS_MEMBER("core.json", coreConfigFile["logging"], "mode", "logging.mode");
    IS_STRING("core.json", coreConfigFile["logging"], "mode", "logging.mode");

    std::string loggingMode = std::string(coreConfigFile["logging"]["mode"].GetString());
    if (loggingMode != "daily" && loggingMode != "map")
        return ConfigurationError("core.json", "The field \"logging.mode\" needs to be: \"daily\" or \"map\".");

    HAS_MEMBER("core.json", coreConfigFile, "commandPrefixes", "commandPrefixes");
    IS_ARRAY("core.json", coreConfigFile, "commandPrefixes", "commandPrefixes");
    for (unsigned int i = 0; i < coreConfigFile["commandPrefixes"].Size(); i++)
        IS_STRING("core.json", coreConfigFile["commandPrefixes"], i, string_format("commandPrefixes[%d]", i));

    HAS_MEMBER("core.json", coreConfigFile, "commandSilentPrefixes", "commandSilentPrefixes");
    IS_ARRAY("core.json", coreConfigFile, "commandSilentPrefixes", "commandSilentPrefixes");
    for (unsigned int i = 0; i < coreConfigFile["commandSilentPrefixes"].Size(); i++)
        IS_STRING("core.json", coreConfigFile["commandSilentPrefixes"], i, string_format("commandSilentPrefixes[%d]", i));

    if (coreConfigFile.HasMember("patches_to_perform"))
    {
        IS_ARRAY("core.json", coreConfigFile, "patches_to_perform", "patches_to_perform");
        for (unsigned int i = 0; i < coreConfigFile["patches_to_perform"].Size(); i++)
            IS_STRING("core.json", coreConfigFile["patches_to_perform"], i, string_format("patches_to_perform[%d]", i));

        std::vector<std::string> patchesToPerform;

        for (uint32 i = 0; i < coreConfigFile["patches_to_perform"].Size(); i++)
            patchesToPerform.push_back(std::string(coreConfigFile["patches_to_perform"][i].GetString()));

        this->SetValue("core.patchesToPerform", implode(patchesToPerform, " "));
    }

    HAS_MEMBER("core.json", coreConfigFile, "console_filtering", "console_filtering");
    IS_BOOL("core.json", coreConfigFile, "console_filtering", "console_filtering");

    HAS_MEMBER("core.json", coreConfigFile, "language", "language");
    IS_STRING("core.json", coreConfigFile, "language", "language");

    this->SetValue("core.logging.enabled", coreConfigFile["logging"]["enabled"].GetBool());
    this->SetValue("core.logging.mode", std::string(coreConfigFile["logging"]["mode"].GetString()));

    std::vector<std::string> commandPrefixes;
    std::vector<std::string> silentCommandPrefixes;

    for (uint32 i = 0; i < coreConfigFile["commandPrefixes"].Size(); i++)
        commandPrefixes.push_back(std::string(coreConfigFile["commandPrefixes"][i].GetString()));
    for (uint32 i = 0; i < coreConfigFile["commandSilentPrefixes"].Size(); i++)
        silentCommandPrefixes.push_back(std::string(coreConfigFile["commandSilentPrefixes"][i].GetString()));

    this->SetValue("core.commandPrefixes", implode(commandPrefixes, " "));
    this->SetValue("core.silentCommandPrefixes", implode(silentCommandPrefixes, " "));

    this->SetValue("core.console_filtering", coreConfigFile["console_filtering"].GetBool());
    this->SetValue("core.language", std::string(coreConfigFile["language"].GetString()));

    this->loaded = true;

    return true;
}

void LoadConfigPart(std::string key, rapidjson::Value &document);

void LoadValue(const char *key, const char *keyname, rapidjson::Value &value, std::string separator = ".")
{
    std::string k = key + separator + keyname;
    if (value.IsBool())
        g_Config->SetValue(k, value.GetBool());
    else if (value.IsString())
        g_Config->SetValue(k, std::string(value.GetString()));
    else if (value.IsDouble())
        g_Config->SetValue(k, value.GetDouble());
    else if (value.IsFloat())
        g_Config->SetValue(k, value.GetFloat());
    else if (value.IsInt64())
        g_Config->SetValue(k, value.GetInt64());
    else if (value.IsInt())
        g_Config->SetValue(k, value.GetInt());
    else if (value.IsUint64())
        g_Config->SetValue(k, value.GetUint64());
    else if (value.IsUint())
        g_Config->SetValue(k, value.GetUint());
    else if (value.IsNull())
        g_Config->SetValue(k, nullptr);
    else if (value.IsObject())
        LoadConfigPart(k, value);
    else if (value.IsArray())
    {
        g_Config->SetArraySize(k, value.Size());
        for (size_t i = 0; i < value.Size(); i++)
            LoadValue(k.c_str(), string_format("[%d]", i).c_str(), value[i], "");
    }
};

void LoadConfigPart(std::string key, rapidjson::Value &document)
{
    for (auto it = document.MemberBegin(); it != document.MemberEnd(); ++it)
    {
        std::string keyname = it->name.GetString();
        LoadValue(key.c_str(), keyname.c_str(), it->value);
    }
}

void Configuration::SetArraySize(std::string key, unsigned int size)
{
    this->configArraySizes.insert(std::make_pair(key, size));
}

void Configuration::LoadPluginConfigurations()
{
    std::vector<std::string> configFiles = Files::FetchFileNames("addons/swiftly/configs/plugins");
    for (const std::string configFilePath : configFiles)
    {
        std::string configFileName = explode(configFilePath, string_format("addons/swiftly/configs/plugins%s", WIN_LINUX("\\", "/")))[1];
        if (!ends_with(configFileName, ".json"))
            continue;
        rapidjson::Document configurationFile;
        configurationFile.Parse(Files::Read(configFilePath).c_str());
        if (configurationFile.HasParseError())
        {
            ConfigurationError(configFileName, string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)configurationFile.GetErrorOffset(), GetParseError_En(configurationFile.GetParseError())));
            continue;
        }

        if (!configurationFile.IsObject())
        {
            ConfigurationError(configFileName, "Configuration file needs to be an object.");
            continue;
        }

        rapidjson::Value &root = configurationFile;
        LoadConfigPart(explode(configFileName, ".json")[0], root);
    }
}

template <typename T>
void Configuration::SetValue(std::string key, T value)
{
    if (this->config.find(key) == this->config.end())
        this->config.insert(make_pair(key, value));
    else
        this->config[key] = value;
}