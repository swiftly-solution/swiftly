#include "../../../core/scripting/generated/classes/GCWeaponM4A1Silencer.h"
#include "../core.h"

void SetupLuaClassGCWeaponM4A1Silencer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponM4A1Silencer>("CWeaponM4A1Silencer")

        .endClass();
}