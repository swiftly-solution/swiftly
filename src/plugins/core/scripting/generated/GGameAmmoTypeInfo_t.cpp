#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GGameAmmoTypeInfo_t::GGameAmmoTypeInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GGameAmmoTypeInfo_t::GGameAmmoTypeInfo_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GGameAmmoTypeInfo_t::GetBuySize() const {
    return GetSchemaValue<int32_t>(m_ptr, "GameAmmoTypeInfo_t", "m_nBuySize");
}
void GGameAmmoTypeInfo_t::SetBuySize(int32_t value) {
    SetSchemaValue(m_ptr, "GameAmmoTypeInfo_t", "m_nBuySize", true, value);
}
int32_t GGameAmmoTypeInfo_t::GetCost() const {
    return GetSchemaValue<int32_t>(m_ptr, "GameAmmoTypeInfo_t", "m_nCost");
}
void GGameAmmoTypeInfo_t::SetCost(int32_t value) {
    SetSchemaValue(m_ptr, "GameAmmoTypeInfo_t", "m_nCost", true, value);
}
std::string GGameAmmoTypeInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GGameAmmoTypeInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
GAmmoTypeInfo_t GGameAmmoTypeInfo_t::GetParent() const {
    GAmmoTypeInfo_t value(m_ptr);
    return value;
}
void GGameAmmoTypeInfo_t::SetParent(GAmmoTypeInfo_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassGameAmmoTypeInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GGameAmmoTypeInfo_t>("GameAmmoTypeInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BuySize", &GGameAmmoTypeInfo_t::GetBuySize, &GGameAmmoTypeInfo_t::SetBuySize)
        .addProperty("Cost", &GGameAmmoTypeInfo_t::GetCost, &GGameAmmoTypeInfo_t::SetCost)
        .addProperty("Parent", &GGameAmmoTypeInfo_t::GetParent, &GGameAmmoTypeInfo_t::SetParent)
        .addFunction("ToPtr", &GGameAmmoTypeInfo_t::ToPtr)
        .addFunction("IsValid", &GGameAmmoTypeInfo_t::IsValid)
        .endClass();
}