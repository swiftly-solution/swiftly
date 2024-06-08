#include "../../../core/scripting/generated/classes/GCServerOnlyEntity.h"
#include "../core.h"

void SetupLuaClassGCServerOnlyEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerOnlyEntity>("CServerOnlyEntity")

        .endClass();
}