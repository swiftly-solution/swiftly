#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFloatAnimParameter::GCFloatAnimParameter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFloatAnimParameter::GCFloatAnimParameter(void *ptr) {
    m_ptr = ptr;
}
float GCFloatAnimParameter::GetDefaultValue() const {
    return GetSchemaValue<float>(m_ptr, "CFloatAnimParameter", "m_fDefaultValue");
}
void GCFloatAnimParameter::SetDefaultValue(float value) {
    SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_fDefaultValue", false, value);
}
float GCFloatAnimParameter::GetMinValue() const {
    return GetSchemaValue<float>(m_ptr, "CFloatAnimParameter", "m_fMinValue");
}
void GCFloatAnimParameter::SetMinValue(float value) {
    SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_fMinValue", false, value);
}
float GCFloatAnimParameter::GetMaxValue() const {
    return GetSchemaValue<float>(m_ptr, "CFloatAnimParameter", "m_fMaxValue");
}
void GCFloatAnimParameter::SetMaxValue(float value) {
    SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_fMaxValue", false, value);
}
bool GCFloatAnimParameter::GetInterpolate() const {
    return GetSchemaValue<bool>(m_ptr, "CFloatAnimParameter", "m_bInterpolate");
}
void GCFloatAnimParameter::SetInterpolate(bool value) {
    SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_bInterpolate", false, value);
}
std::string GCFloatAnimParameter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFloatAnimParameter::IsValid() {
    return (m_ptr != nullptr);
}
GCConcreteAnimParameter GCFloatAnimParameter::GetParent() const {
    GCConcreteAnimParameter value(m_ptr);
    return value;
}
void GCFloatAnimParameter::SetParent(GCConcreteAnimParameter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFloatAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFloatAnimParameter>("CFloatAnimParameter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DefaultValue", &GCFloatAnimParameter::GetDefaultValue, &GCFloatAnimParameter::SetDefaultValue)
        .addProperty("MinValue", &GCFloatAnimParameter::GetMinValue, &GCFloatAnimParameter::SetMinValue)
        .addProperty("MaxValue", &GCFloatAnimParameter::GetMaxValue, &GCFloatAnimParameter::SetMaxValue)
        .addProperty("Interpolate", &GCFloatAnimParameter::GetInterpolate, &GCFloatAnimParameter::SetInterpolate)
        .addProperty("Parent", &GCFloatAnimParameter::GetParent, &GCFloatAnimParameter::SetParent)
        .addFunction("ToPtr", &GCFloatAnimParameter::ToPtr)
        .addFunction("IsValid", &GCFloatAnimParameter::IsValid)
        .endClass();
}