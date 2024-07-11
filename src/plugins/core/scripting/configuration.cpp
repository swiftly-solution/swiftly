#include "../scripting.h"

PluginConfiguration::PluginConfiguration(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

bool PluginConfiguration::Exists(std::string key)
{
    std::map<std::string, std::any> config = g_Config->FetchConfiguration();

    return (config.find(key) != config.end());
}

void PluginConfiguration::Reload(std::string key)
{
    g_Config->LoadPluginConfig(key);
}

uint64_t PluginConfiguration::FetchArraySize(std::string key)
{
    std::map<std::string, unsigned int> arraySizes = g_Config->FetchConfigArraySizes();

    if (arraySizes.find(key) == arraySizes.end())
        return 0;

    return arraySizes.at(key);
}

std::any PluginConfiguration::Fetch(std::string key)
{
    std::map<std::string, std::any> config = g_Config->FetchConfiguration();

    if (config.find(key) == config.end())
        return nullptr;

    return config.at(key);
}

luabridge::LuaRef PluginConfiguration::FetchLua(std::string key, lua_State *L)
{
    std::any value = Fetch(key);

    return LuaSerializeData(value, L);
}