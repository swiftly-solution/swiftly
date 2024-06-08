#include "../../../core/scripting/generated/classes/GCWeaponUMP45.h"
#include "../core.h"

void SetupLuaClassGCWeaponUMP45(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponUMP45>("CWeaponUMP45")

        .endClass();
}