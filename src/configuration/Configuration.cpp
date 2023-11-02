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

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        throw std::runtime_error("Error during formatting.");

    size_t size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

bool ConfigurationError(std::string configuration_file, std::string error)
{
    if (!g_SMAPI)
        return false;

    PRINTF("Configurations", "Error: %s: %s\n", configuration_file, error.c_str());
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

    return true;
}

bool Configuration::SaveConfiguration()
{
    return true;
}