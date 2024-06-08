#include "../../../core/scripting/generated/classes/GCWeaponAWP.h"
#include "../core.h"

void SetupLuaClassGCWeaponAWP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponAWP>("CWeaponAWP")

        .endClass();
}