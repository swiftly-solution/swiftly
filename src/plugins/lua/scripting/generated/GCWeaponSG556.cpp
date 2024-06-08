#include "../../../core/scripting/generated/classes/GCWeaponSG556.h"
#include "../core.h"

void SetupLuaClassGCWeaponSG556(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSG556>("CWeaponSG556")

        .endClass();
}