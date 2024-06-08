#include "../../../core/scripting/generated/classes/GCWeaponGlock.h"
#include "../core.h"

void SetupLuaClassGCWeaponGlock(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponGlock>("CWeaponGlock")

        .endClass();
}