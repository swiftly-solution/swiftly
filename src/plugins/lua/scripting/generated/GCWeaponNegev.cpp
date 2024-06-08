#include "../../../core/scripting/generated/classes/GCWeaponNegev.h"
#include "../core.h"

void SetupLuaClassGCWeaponNegev(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponNegev>("CWeaponNegev")

        .endClass();
}