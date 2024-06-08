#include "../../../core/scripting/generated/classes/GCWeaponZoneRepulsor.h"
#include "../core.h"

void SetupLuaClassGCWeaponZoneRepulsor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponZoneRepulsor>("CWeaponZoneRepulsor")

        .endClass();
}