#pragma once

#include "../LuaPlugin.h"
#include "../../core/scripting.h"
#include "../../../entrypoint.h"
#include "../../../types/EventResult.h"

#define FetchPluginName(state) luabridge::getGlobal(state, "plugin_name").tostring()
#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

void SetupLuaLogs(LuaPlugin *plugin, lua_State *state);
void SetupLuaTypes(LuaPlugin *plugin, lua_State *state);
void SetupLuaTranslations(LuaPlugin *plugin, lua_State *state);
void SetupLuaConfiguration(LuaPlugin *plugin, lua_State *state);
void SetupLuaFiles(LuaPlugin *plugin, lua_State *state);
void SetupLuaPrecacher(LuaPlugin *plugin, lua_State *state);
void SetupLuaCommands(LuaPlugin *plugin, lua_State *state);
void SetupLuaPlayerManager(LuaPlugin *plugin, lua_State *state);
void SetupLuaEvents(LuaPlugin *plugin, lua_State *state);
void SetupLuaHTTP(LuaPlugin *plugin, lua_State *state);
void SetupLuaDatabase(LuaPlugin *plugin, lua_State *state);
void SetupLuaMenus(LuaPlugin *plugin, lua_State *state);
void SetupLuaUtils(LuaPlugin *plugin, lua_State *state);
void SetupLuaConvars(LuaPlugin *plugin, lua_State *state);
void SetupLuaClasses(LuaPlugin *plugin, lua_State *state);
void SetupLuaGeneratedTypes(LuaPlugin *plugin, lua_State *state);
void SetupLuaCoreClasses(LuaPlugin *plugin, lua_State *state);
void SetupLuaServer(LuaPlugin *plugin, lua_State *state);
void SetupLuaPlayer(LuaPlugin *plugin, lua_State *state);
void SetupLuaEntities(LuaPlugin *plugin, lua_State *state);
void SetupLuaMemory(LuaPlugin *plugin, lua_State *state);
void SetupLuaHooks(LuaPlugin *plugin, lua_State *state);
void SetupLuaUserMessages(LuaPlugin *plugin, lua_State *state);
void SetupLuaWeapons(LuaPlugin *plugin, lua_State *state);