#include "../../../core/scripting/generated/classes/GCWeaponMAC10.h"
#include "../core.h"

void SetupLuaClassGCWeaponMAC10(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMAC10>("CWeaponMAC10")

        .endClass();
}