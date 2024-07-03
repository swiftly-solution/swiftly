#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInterpolatedValue::GCInterpolatedValue(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInterpolatedValue::GCInterpolatedValue(void *ptr) {
    m_ptr = ptr;
}
float GCInterpolatedValue::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flStartTime");
}
void GCInterpolatedValue::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flStartTime", false, value);
}
float GCInterpolatedValue::GetEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flEndTime");
}
void GCInterpolatedValue::SetEndTime(float value) {
    SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flEndTime", false, value);
}
float GCInterpolatedValue::GetStartValue() const {
    return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flStartValue");
}
void GCInterpolatedValue::SetStartValue(float value) {
    SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flStartValue", false, value);
}
float GCInterpolatedValue::GetEndValue() const {
    return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flEndValue");
}
void GCInterpolatedValue::SetEndValue(float value) {
    SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flEndValue", false, value);
}
int32_t GCInterpolatedValue::GetInterpType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInterpolatedValue", "m_nInterpType");
}
void GCInterpolatedValue::SetInterpType(int32_t value) {
    SetSchemaValue(m_ptr, "CInterpolatedValue", "m_nInterpType", false, value);
}
std::string GCInterpolatedValue::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInterpolatedValue::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCInterpolatedValue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInterpolatedValue>("CInterpolatedValue")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GCInterpolatedValue::GetStartTime, &GCInterpolatedValue::SetStartTime)
        .addProperty("EndTime", &GCInterpolatedValue::GetEndTime, &GCInterpolatedValue::SetEndTime)
        .addProperty("StartValue", &GCInterpolatedValue::GetStartValue, &GCInterpolatedValue::SetStartValue)
        .addProperty("EndValue", &GCInterpolatedValue::GetEndValue, &GCInterpolatedValue::SetEndValue)
        .addProperty("InterpType", &GCInterpolatedValue::GetInterpType, &GCInterpolatedValue::SetInterpType)
        .addFunction("ToPtr", &GCInterpolatedValue::ToPtr)
        .addFunction("IsValid", &GCInterpolatedValue::IsValid)
        .endClass();
}