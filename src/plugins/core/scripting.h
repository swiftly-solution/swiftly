#pragma once

#include "../../common.h"
#include "../../entrypoint.h"
#include "../Plugin.h"
#include "../PluginManager.h"
#include "../../types/LogType.h"
#include "../../logs/Logger.h"

#include <any>

//////////////////////////////////////////////////////////////
/////////////////            Logger            //////////////
////////////////////////////////////////////////////////////

class PluginLogger
{
private:
    std::string plugin_name;

public:
    PluginLogger(std::string m_plugin_name);

    void Write(int level, std::string message);
};

//////////////////////////////////////////////////////////////
/////////////////         Configuration        //////////////
////////////////////////////////////////////////////////////

class PluginConfiguration
{
private:
    std::string plugin_name;

public:
    PluginConfiguration(std::string m_plugin_name);

    bool Exists(std::string key);
    void Reload(std::string key);
    uint64_t FetchArraySize(std::string key);
    std::any Fetch(std::string key);

    luabridge::LuaRef FetchLua(std::string key, lua_State *L);
};

//////////////////////////////////////////////////////////////
/////////////////         Translations         //////////////
////////////////////////////////////////////////////////////

std::string scripting_FetchTranslation(Plugin *plugin, std::string key);