#include "../../../core/scripting/generated/classes/GCBumpMineProjectile.h"
#include "../core.h"

void SetupLuaClassGCBumpMineProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBumpMineProjectile>("CBumpMineProjectile")

        .endClass();
}