#pragma once

#include "../LuaPlugin.h"
#include "../../core/scripting.h"
#include "../../../entrypoint.h"
#include "../../../types/EventResult.h"

#define FetchPluginName(state) luabridge::getGlobal(state, "plugin_name").tostring()
#define FetchPlugin(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

void SetupLuaLogs(LuaPlugin *plugin, lua_State *state);
void SetupLuaTypes(LuaPlugin *plugin, lua_State *state);
void SetupLuaTranslations(LuaPlugin *plugin, lua_State *state);
void SetupLuaConfiguration(LuaPlugin *plugin, lua_State *state);
void SetupLuaFiles(LuaPlugin *plugin, lua_State *state);
void SetupLuaPrecacher(LuaPlugin *plugin, lua_State *state);
void SetupLuaCommands(LuaPlugin *plugin, lua_State *state);
void SetupLuaPlayerManager(LuaPlugin *plugin, lua_State *state);
void SetupLuaEvents(LuaPlugin *plugin, lua_State *state);