#include "../../../core/scripting/generated/classes/GCWeaponP90.h"
#include "../core.h"

void SetupLuaClassGCWeaponP90(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponP90>("CWeaponP90")

        .endClass();
}