#include "../../../core/scripting/generated/classes/GCBodyComponentBaseModelEntity.h"
#include "../core.h"

void SetupLuaClassGCBodyComponentBaseModelEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentBaseModelEntity>("CBodyComponentBaseModelEntity")

        .endClass();
}