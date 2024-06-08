#include "../../../core/scripting/generated/classes/GCBreachChargeProjectile.h"
#include "../core.h"

void SetupLuaClassGCBreachChargeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreachChargeProjectile>("CBreachChargeProjectile")

        .endClass();
}