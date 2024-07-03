#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTakeDamageResult::GCTakeDamageResult(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTakeDamageResult::GCTakeDamageResult(void *ptr) {
    m_ptr = ptr;
}
GCTakeDamageInfo GCTakeDamageResult::GetOriginatingInfo() const {
    GCTakeDamageInfo value(*GetSchemaValuePtr<void*>(m_ptr, "CTakeDamageResult", "m_pOriginatingInfo"));
    return value;
}
void GCTakeDamageResult::SetOriginatingInfo(GCTakeDamageInfo* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginatingInfo' is not possible.\n");
}
int32_t GCTakeDamageResult::GetHealthLost() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nHealthLost");
}
void GCTakeDamageResult::SetHealthLost(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nHealthLost", false, value);
}
int32_t GCTakeDamageResult::GetDamageTaken() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nDamageTaken");
}
void GCTakeDamageResult::SetDamageTaken(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nDamageTaken", false, value);
}
int32_t GCTakeDamageResult::GetTotalledHealthLost() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nTotalledHealthLost");
}
void GCTakeDamageResult::SetTotalledHealthLost(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nTotalledHealthLost", false, value);
}
int32_t GCTakeDamageResult::GetTotalledDamageTaken() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTakeDamageResult", "m_nTotalledDamageTaken");
}
void GCTakeDamageResult::SetTotalledDamageTaken(int32_t value) {
    SetSchemaValue(m_ptr, "CTakeDamageResult", "m_nTotalledDamageTaken", false, value);
}
std::string GCTakeDamageResult::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTakeDamageResult::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCTakeDamageResult(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageResult>("CTakeDamageResult")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OriginatingInfo", &GCTakeDamageResult::GetOriginatingInfo, &GCTakeDamageResult::SetOriginatingInfo)
        .addProperty("HealthLost", &GCTakeDamageResult::GetHealthLost, &GCTakeDamageResult::SetHealthLost)
        .addProperty("DamageTaken", &GCTakeDamageResult::GetDamageTaken, &GCTakeDamageResult::SetDamageTaken)
        .addProperty("TotalledHealthLost", &GCTakeDamageResult::GetTotalledHealthLost, &GCTakeDamageResult::SetTotalledHealthLost)
        .addProperty("TotalledDamageTaken", &GCTakeDamageResult::GetTotalledDamageTaken, &GCTakeDamageResult::SetTotalledDamageTaken)
        .addFunction("ToPtr", &GCTakeDamageResult::ToPtr)
        .addFunction("IsValid", &GCTakeDamageResult::IsValid)
        .endClass();
}