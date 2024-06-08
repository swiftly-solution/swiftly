#include "../../../core/scripting/generated/classes/GCServerOnlyPointEntity.h"
#include "../core.h"

void SetupLuaClassGCServerOnlyPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerOnlyPointEntity>("CServerOnlyPointEntity")

        .endClass();
}