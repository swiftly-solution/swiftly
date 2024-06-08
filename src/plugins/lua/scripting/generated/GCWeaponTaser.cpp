#include "../../../core/scripting/generated/classes/GCWeaponTaser.h"
#include "../core.h"

void SetupLuaClassGCWeaponTaser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponTaser>("CWeaponTaser")
        .addProperty("LastAttackTick", &GCWeaponTaser::GetLastAttackTick, &GCWeaponTaser::SetLastAttackTick)
        .endClass();
}