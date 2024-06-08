#include "../../../core/scripting/generated/classes/GCWeaponXM1014.h"
#include "../core.h"

void SetupLuaClassGCWeaponXM1014(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponXM1014>("CWeaponXM1014")

        .endClass();
}