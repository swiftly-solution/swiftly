#include "../../../core/scripting/generated/classes/GCWeaponMP5SD.h"
#include "../core.h"

void SetupLuaClassGCWeaponMP5SD(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMP5SD>("CWeaponMP5SD")

        .endClass();
}