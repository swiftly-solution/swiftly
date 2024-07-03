#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSellbackPurchaseEntry_t::GSellbackPurchaseEntry_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSellbackPurchaseEntry_t::GSellbackPurchaseEntry_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GSellbackPurchaseEntry_t::GetDefIdx() const {
    return GetSchemaValue<uint16_t>(m_ptr, "SellbackPurchaseEntry_t", "m_unDefIdx");
}
void GSellbackPurchaseEntry_t::SetDefIdx(uint16_t value) {
    SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_unDefIdx", true, value);
}
int32_t GSellbackPurchaseEntry_t::GetCost() const {
    return GetSchemaValue<int32_t>(m_ptr, "SellbackPurchaseEntry_t", "m_nCost");
}
void GSellbackPurchaseEntry_t::SetCost(int32_t value) {
    SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_nCost", true, value);
}
int32_t GSellbackPurchaseEntry_t::GetPrevArmor() const {
    return GetSchemaValue<int32_t>(m_ptr, "SellbackPurchaseEntry_t", "m_nPrevArmor");
}
void GSellbackPurchaseEntry_t::SetPrevArmor(int32_t value) {
    SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_nPrevArmor", true, value);
}
bool GSellbackPurchaseEntry_t::GetPrevHelmet() const {
    return GetSchemaValue<bool>(m_ptr, "SellbackPurchaseEntry_t", "m_bPrevHelmet");
}
void GSellbackPurchaseEntry_t::SetPrevHelmet(bool value) {
    SetSchemaValue(m_ptr, "SellbackPurchaseEntry_t", "m_bPrevHelmet", true, value);
}
GCEntityInstance GSellbackPurchaseEntry_t::GetItem() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "SellbackPurchaseEntry_t", "m_hItem"));
    return value;
}
void GSellbackPurchaseEntry_t::SetItem(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Item' is not possible.\n");
}
std::string GSellbackPurchaseEntry_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSellbackPurchaseEntry_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSellbackPurchaseEntry_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSellbackPurchaseEntry_t>("SellbackPurchaseEntry_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefIdx", &GSellbackPurchaseEntry_t::GetDefIdx, &GSellbackPurchaseEntry_t::SetDefIdx)
        .addProperty("Cost", &GSellbackPurchaseEntry_t::GetCost, &GSellbackPurchaseEntry_t::SetCost)
        .addProperty("PrevArmor", &GSellbackPurchaseEntry_t::GetPrevArmor, &GSellbackPurchaseEntry_t::SetPrevArmor)
        .addProperty("PrevHelmet", &GSellbackPurchaseEntry_t::GetPrevHelmet, &GSellbackPurchaseEntry_t::SetPrevHelmet)
        .addProperty("Item", &GSellbackPurchaseEntry_t::GetItem, &GSellbackPurchaseEntry_t::SetItem)
        .addFunction("ToPtr", &GSellbackPurchaseEntry_t::ToPtr)
        .addFunction("IsValid", &GSellbackPurchaseEntry_t::IsValid)
        .endClass();
}