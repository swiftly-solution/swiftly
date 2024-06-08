#include "../../../core/scripting/generated/classes/GCLogicalEntity.h"
#include "../core.h"

void SetupLuaClassGCLogicalEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicalEntity>("CLogicalEntity")

        .endClass();
}