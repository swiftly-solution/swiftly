#include "../../../core/scripting/generated/classes/GCCSServerPointScriptEntity.h"
#include "../core.h"

void SetupLuaClassGCCSServerPointScriptEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSServerPointScriptEntity>("CCSServerPointScriptEntity")

        .endClass();
}