#include "../../../core/scripting/generated/classes/GServerAuthoritativeWeaponSlot_t.h"
#include "../core.h"

void SetupLuaClassGServerAuthoritativeWeaponSlot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GServerAuthoritativeWeaponSlot_t>("ServerAuthoritativeWeaponSlot_t")
        .addProperty("Class", &GServerAuthoritativeWeaponSlot_t::GetClass, &GServerAuthoritativeWeaponSlot_t::SetClass)
        .addProperty("Slot", &GServerAuthoritativeWeaponSlot_t::GetSlot, &GServerAuthoritativeWeaponSlot_t::SetSlot)
        .addProperty("ItemDefIdx", &GServerAuthoritativeWeaponSlot_t::GetItemDefIdx, &GServerAuthoritativeWeaponSlot_t::SetItemDefIdx)
        .endClass();
}