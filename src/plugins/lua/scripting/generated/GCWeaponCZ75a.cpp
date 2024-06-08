#include "../../../core/scripting/generated/classes/GCWeaponCZ75a.h"
#include "../core.h"

void SetupLuaClassGCWeaponCZ75a(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponCZ75a>("CWeaponCZ75a")

        .endClass();
}