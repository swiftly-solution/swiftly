#include "../../../core/scripting/generated/classes/GWeaponPurchaseTracker_t.h"
#include "../core.h"

void SetupLuaClassGWeaponPurchaseTracker_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWeaponPurchaseTracker_t>("WeaponPurchaseTracker_t")
        .addProperty("WeaponPurchases", &GWeaponPurchaseTracker_t::GetWeaponPurchases, &GWeaponPurchaseTracker_t::SetWeaponPurchases)
        .endClass();
}