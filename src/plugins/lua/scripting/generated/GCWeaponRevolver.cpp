#include "../../../core/scripting/generated/classes/GCWeaponRevolver.h"
#include "../core.h"

void SetupLuaClassGCWeaponRevolver(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponRevolver>("CWeaponRevolver")

        .endClass();
}