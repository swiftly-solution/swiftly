#include "../../../core/scripting/generated/classes/GCModelPointEntity.h"
#include "../core.h"

void SetupLuaClassGCModelPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelPointEntity>("CModelPointEntity")

        .endClass();
}