#include "../../../core/scripting/generated/classes/GCWeaponUSPSilencer.h"
#include "../core.h"

void SetupLuaClassGCWeaponUSPSilencer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponUSPSilencer>("CWeaponUSPSilencer")

        .endClass();
}