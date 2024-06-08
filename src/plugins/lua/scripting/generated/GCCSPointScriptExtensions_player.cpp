#include "../../../core/scripting/generated/classes/GCCSPointScriptExtensions_player.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptExtensions_player(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_player>("CCSPointScriptExtensions_player")

        .endClass();
}