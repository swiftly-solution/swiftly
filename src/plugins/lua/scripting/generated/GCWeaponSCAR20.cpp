#include "../../../core/scripting/generated/classes/GCWeaponSCAR20.h"
#include "../core.h"

void SetupLuaClassGCWeaponSCAR20(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSCAR20>("CWeaponSCAR20")

        .endClass();
}