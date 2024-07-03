#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGOViewModel::GCCSGOViewModel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGOViewModel::GCCSGOViewModel(void *ptr) {
    m_ptr = ptr;
}
bool GCCSGOViewModel::GetShouldIgnoreOffsetAndAccuracy() const {
    return GetSchemaValue<bool>(m_ptr, "CCSGOViewModel", "m_bShouldIgnoreOffsetAndAccuracy");
}
void GCCSGOViewModel::SetShouldIgnoreOffsetAndAccuracy(bool value) {
    SetSchemaValue(m_ptr, "CCSGOViewModel", "m_bShouldIgnoreOffsetAndAccuracy", false, value);
}
uint32_t GCCSGOViewModel::GetWeaponParity() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGOViewModel", "m_nWeaponParity");
}
void GCCSGOViewModel::SetWeaponParity(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGOViewModel", "m_nWeaponParity", false, value);
}
uint32_t GCCSGOViewModel::GetOldWeaponParity() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSGOViewModel", "m_nOldWeaponParity");
}
void GCCSGOViewModel::SetOldWeaponParity(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSGOViewModel", "m_nOldWeaponParity", false, value);
}
std::string GCCSGOViewModel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGOViewModel::IsValid() {
    return (m_ptr != nullptr);
}
GCPredictedViewModel GCCSGOViewModel::GetParent() const {
    GCPredictedViewModel value(m_ptr);
    return value;
}
void GCCSGOViewModel::SetParent(GCPredictedViewModel value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGOViewModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGOViewModel>("CCSGOViewModel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ShouldIgnoreOffsetAndAccuracy", &GCCSGOViewModel::GetShouldIgnoreOffsetAndAccuracy, &GCCSGOViewModel::SetShouldIgnoreOffsetAndAccuracy)
        .addProperty("WeaponParity", &GCCSGOViewModel::GetWeaponParity, &GCCSGOViewModel::SetWeaponParity)
        .addProperty("OldWeaponParity", &GCCSGOViewModel::GetOldWeaponParity, &GCCSGOViewModel::SetOldWeaponParity)
        .addProperty("Parent", &GCCSGOViewModel::GetParent, &GCCSGOViewModel::SetParent)
        .addFunction("ToPtr", &GCCSGOViewModel::ToPtr)
        .addFunction("IsValid", &GCCSGOViewModel::IsValid)
        .endClass();
}