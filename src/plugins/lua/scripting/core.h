#pragma once

#include "../LuaPlugin.h"
#include "../../core/scripting.h"
#include "../../../entrypoint.h"
#include "../../../types/EventResult.h"

std::string FetchPluginName(lua_State* state);
#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))
#define LoadLuaScriptingComponent(component_name, component_func) LuaLoader lua_##component_name(component_func);

class LuaLoader;
extern std::vector<LuaLoader*> luaLoaderClasses;

class LuaLoader
{
private:
    std::function<void(LuaPlugin*, lua_State*)> m_loadFunction;
public:
    LuaLoader(std::function<void(LuaPlugin*, lua_State*)> loadFunction): m_loadFunction(loadFunction) {
        luaLoaderClasses.push_back(this);
    }

    void ExecuteLoad(LuaPlugin* plugin, lua_State* state)
    {
        m_loadFunction(plugin, state);
    }
};