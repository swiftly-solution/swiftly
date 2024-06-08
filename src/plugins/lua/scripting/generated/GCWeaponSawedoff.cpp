#include "../../../core/scripting/generated/classes/GCWeaponSawedoff.h"
#include "../core.h"

void SetupLuaClassGCWeaponSawedoff(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSawedoff>("CWeaponSawedoff")

        .endClass();
}