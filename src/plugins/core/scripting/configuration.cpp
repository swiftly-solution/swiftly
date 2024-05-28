#include "../scripting.h"

luabridge::LuaRef ConfigSerializeData(std::any data, lua_State *state)
{
    std::any value = data;

    try
    {
        if (value.type() == typeid(const char *))
            return luabridge::LuaRef(state, std::any_cast<const char *>(value));
        else if (value.type() == typeid(std::string))
            return luabridge::LuaRef(state, std::any_cast<std::string>(value));
        else if (value.type() == typeid(uint64))
            return luabridge::LuaRef(state, std::any_cast<uint64>(value));
        else if (value.type() == typeid(uint32))
            return luabridge::LuaRef(state, std::any_cast<uint32>(value));
        else if (value.type() == typeid(unsigned long))
            return luabridge::LuaRef(state, std::any_cast<unsigned long>(value));
        else if (value.type() == typeid(uint16))
            return luabridge::LuaRef(state, std::any_cast<uint16>(value));
        else if (value.type() == typeid(uint8))
            return luabridge::LuaRef(state, std::any_cast<uint8>(value));
        else if (value.type() == typeid(int64))
            return luabridge::LuaRef(state, std::any_cast<int64>(value));
        else if (value.type() == typeid(int32))
            return luabridge::LuaRef(state, std::any_cast<int32>(value));
        else if (value.type() == typeid(long))
            return luabridge::LuaRef(state, std::any_cast<long>(value));
        else if (value.type() == typeid(int16))
            return luabridge::LuaRef(state, std::any_cast<int16>(value));
        else if (value.type() == typeid(int8))
            return luabridge::LuaRef(state, std::any_cast<int8>(value));
        else if (value.type() == typeid(bool))
            return luabridge::LuaRef(state, std::any_cast<bool>(value));
        else if (value.type() == typeid(float))
            return luabridge::LuaRef(state, std::any_cast<float>(value));
        else if (value.type() == typeid(double))
            return luabridge::LuaRef(state, std::any_cast<double>(value));
        else if (value.type() == typeid(std::nullptr_t))
            return luabridge::LuaRef(state);
        else
        {
            PRINTF("Unknown Data Type: %s\n", value.type().name());
            return luabridge::LuaRef(state);
        }
    }
    catch (std::bad_any_cast &err)
    {
        PRINTF("Invalid casting: %s\n", err.what());
        return luabridge::LuaRef(state);
    }
}

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

    return ConfigSerializeData(value, L);
}