#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerProximity::GCTriggerProximity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerProximity::GCTriggerProximity(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCTriggerProximity::GetMeasureTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerProximity", "m_hMeasureTarget"));
    return value;
}
void GCTriggerProximity::SetMeasureTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureTarget' is not possible.\n");
}
std::string GCTriggerProximity::GetMeasureTarget1() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerProximity", "m_iszMeasureTarget").String();
}
void GCTriggerProximity::SetMeasureTarget1(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerProximity", "m_iszMeasureTarget", false, CUtlSymbolLarge(value.c_str()));
}
float GCTriggerProximity::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerProximity", "m_fRadius");
}
void GCTriggerProximity::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CTriggerProximity", "m_fRadius", false, value);
}
int32_t GCTriggerProximity::GetTouchers() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTriggerProximity", "m_nTouchers");
}
void GCTriggerProximity::SetTouchers(int32_t value) {
    SetSchemaValue(m_ptr, "CTriggerProximity", "m_nTouchers", false, value);
}
std::string GCTriggerProximity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerProximity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerProximity::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerProximity::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerProximity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerProximity>("CTriggerProximity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MeasureTarget", &GCTriggerProximity::GetMeasureTarget, &GCTriggerProximity::SetMeasureTarget)
        .addProperty("MeasureTarget1", &GCTriggerProximity::GetMeasureTarget1, &GCTriggerProximity::SetMeasureTarget1)
        .addProperty("Radius", &GCTriggerProximity::GetRadius, &GCTriggerProximity::SetRadius)
        .addProperty("Touchers", &GCTriggerProximity::GetTouchers, &GCTriggerProximity::SetTouchers)
        .addProperty("Parent", &GCTriggerProximity::GetParent, &GCTriggerProximity::SetParent)
        .addFunction("ToPtr", &GCTriggerProximity::ToPtr)
        .addFunction("IsValid", &GCTriggerProximity::IsValid)
        .endClass();
}