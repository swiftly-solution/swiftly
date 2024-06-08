#include "../../../core/scripting/generated/classes/GCWeaponHKP2000.h"
#include "../core.h"

void SetupLuaClassGCWeaponHKP2000(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponHKP2000>("CWeaponHKP2000")

        .endClass();
}