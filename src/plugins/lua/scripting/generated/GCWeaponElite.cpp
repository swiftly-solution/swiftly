#include "../../../core/scripting/generated/classes/GCWeaponElite.h"
#include "../core.h"

void SetupLuaClassGCWeaponElite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponElite>("CWeaponElite")

        .endClass();
}