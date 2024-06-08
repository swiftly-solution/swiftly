#include "../../../core/scripting/generated/classes/GCWeaponBizon.h"
#include "../core.h"

void SetupLuaClassGCWeaponBizon(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponBizon>("CWeaponBizon")

        .endClass();
}