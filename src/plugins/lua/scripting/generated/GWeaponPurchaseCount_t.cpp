#include "../../../core/scripting/generated/classes/GWeaponPurchaseCount_t.h"
#include "../core.h"

void SetupLuaClassGWeaponPurchaseCount_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWeaponPurchaseCount_t>("WeaponPurchaseCount_t")
        .addProperty("ItemDefIndex", &GWeaponPurchaseCount_t::GetItemDefIndex, &GWeaponPurchaseCount_t::SetItemDefIndex)
        .addProperty("Count", &GWeaponPurchaseCount_t::GetCount, &GWeaponPurchaseCount_t::SetCount)
        .endClass();
}