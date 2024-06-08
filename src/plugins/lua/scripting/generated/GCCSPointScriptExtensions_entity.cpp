#include "../../../core/scripting/generated/classes/GCCSPointScriptExtensions_entity.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptExtensions_entity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_entity>("CCSPointScriptExtensions_entity")

        .endClass();
}