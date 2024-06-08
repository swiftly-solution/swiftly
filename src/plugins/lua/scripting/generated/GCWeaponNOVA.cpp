#include "../../../core/scripting/generated/classes/GCWeaponNOVA.h"
#include "../core.h"

void SetupLuaClassGCWeaponNOVA(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponNOVA>("CWeaponNOVA")

        .endClass();
}