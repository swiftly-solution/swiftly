#pragma once

#include "../LuaPlugin.h"
#include "../../core/scripting.h"
#include "../../../entrypoint.h"

#define FetchPluginName(state) luabridge::getGlobal(state, "plugin_name").tostring()
#define FetchPlugin(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

void SetupLuaTypes(LuaPlugin *plugin, lua_State *state);
void SetupLuaTranslations(LuaPlugin *plugin, lua_State *state);
