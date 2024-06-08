#include "../../../core/scripting/generated/classes/GCServerOnlyModelEntity.h"
#include "../core.h"

void SetupLuaClassGCServerOnlyModelEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerOnlyModelEntity>("CServerOnlyModelEntity")

        .endClass();
}