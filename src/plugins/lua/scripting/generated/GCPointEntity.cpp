#include "../../../core/scripting/generated/classes/GCPointEntity.h"
#include "../core.h"

void SetupLuaClassGCPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointEntity>("CPointEntity")

        .endClass();
}