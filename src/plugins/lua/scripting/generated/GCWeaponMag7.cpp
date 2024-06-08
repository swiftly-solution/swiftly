#include "../../../core/scripting/generated/classes/GCWeaponMag7.h"
#include "../core.h"

void SetupLuaClassGCWeaponMag7(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMag7>("CWeaponMag7")

        .endClass();
}