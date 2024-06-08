#include "../../../core/scripting/generated/classes/GCNullEntity.h"
#include "../core.h"

void SetupLuaClassGCNullEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNullEntity>("CNullEntity")

        .endClass();
}