#include "../../../core/scripting/generated/classes/GCWeaponAug.h"
#include "../core.h"

void SetupLuaClassGCWeaponAug(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponAug>("CWeaponAug")

        .endClass();
}