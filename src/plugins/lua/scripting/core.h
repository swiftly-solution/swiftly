#pragma once

#include "../LuaPlugin.h"
#include "../../core/scripting.h"
#include "../../../entrypoint.h"

#define FetchPluginName(state) luabridge::getGlobal(state, "plugin_name").tostring()

void SetupLuaTypes(LuaPlugin *plugin, lua_State *state);
void SetupLuaTranslations(LuaPlugin *plugin, lua_State *state);
