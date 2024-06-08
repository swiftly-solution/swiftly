#include "../../../core/scripting/generated/classes/GCCSPointScriptEntity.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptEntity>("CCSPointScriptEntity")

        .endClass();
}