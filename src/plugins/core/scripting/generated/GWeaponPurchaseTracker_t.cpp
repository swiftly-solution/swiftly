#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWeaponPurchaseTracker_t::GWeaponPurchaseTracker_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWeaponPurchaseTracker_t::GWeaponPurchaseTracker_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GWeaponPurchaseCount_t> GWeaponPurchaseTracker_t::GetWeaponPurchases() const {
    CUtlVector<GWeaponPurchaseCount_t>* vec = GetSchemaValue<CUtlVector<GWeaponPurchaseCount_t>*>(m_ptr, "WeaponPurchaseTracker_t", "m_weaponPurchases"); std::vector<GWeaponPurchaseCount_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWeaponPurchaseTracker_t::SetWeaponPurchases(std::vector<GWeaponPurchaseCount_t> value) {
    SetSchemaValueCUtlVector<GWeaponPurchaseCount_t>(m_ptr, "WeaponPurchaseTracker_t", "m_weaponPurchases", true, value);
}
std::string GWeaponPurchaseTracker_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWeaponPurchaseTracker_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWeaponPurchaseTracker_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWeaponPurchaseTracker_t>("WeaponPurchaseTracker_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeaponPurchases", &GWeaponPurchaseTracker_t::GetWeaponPurchases, &GWeaponPurchaseTracker_t::SetWeaponPurchases)
        .addFunction("ToPtr", &GWeaponPurchaseTracker_t::ToPtr)
        .addFunction("IsValid", &GWeaponPurchaseTracker_t::IsValid)
        .endClass();
}