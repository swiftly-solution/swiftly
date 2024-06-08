#include "../../../core/scripting/generated/classes/GCCSGOViewModel.h"
#include "../core.h"

void SetupLuaClassGCCSGOViewModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGOViewModel>("CCSGOViewModel")
        .addProperty("ShouldIgnoreOffsetAndAccuracy", &GCCSGOViewModel::GetShouldIgnoreOffsetAndAccuracy, &GCCSGOViewModel::SetShouldIgnoreOffsetAndAccuracy)
        .addProperty("WeaponParity", &GCCSGOViewModel::GetWeaponParity, &GCCSGOViewModel::SetWeaponParity)
        .addProperty("OldWeaponParity", &GCCSGOViewModel::GetOldWeaponParity, &GCCSGOViewModel::SetOldWeaponParity)
        .endClass();
}