#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDynamicLight::GCDynamicLight(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDynamicLight::GCDynamicLight(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCDynamicLight::GetActualFlags() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CDynamicLight", "m_ActualFlags");
}
void GCDynamicLight::SetActualFlags(uint8_t value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_ActualFlags", false, value);
}
uint8_t GCDynamicLight::GetFlags() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CDynamicLight", "m_Flags");
}
void GCDynamicLight::SetFlags(uint8_t value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_Flags", false, value);
}
uint8_t GCDynamicLight::GetLightStyle() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CDynamicLight", "m_LightStyle");
}
void GCDynamicLight::SetLightStyle(uint8_t value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_LightStyle", false, value);
}
bool GCDynamicLight::GetOn() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicLight", "m_On");
}
void GCDynamicLight::SetOn(bool value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_On", false, value);
}
float GCDynamicLight::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_Radius");
}
void GCDynamicLight::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_Radius", false, value);
}
int32_t GCDynamicLight::GetExponent() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDynamicLight", "m_Exponent");
}
void GCDynamicLight::SetExponent(int32_t value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_Exponent", false, value);
}
float GCDynamicLight::GetInnerAngle() const {
    return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_InnerAngle");
}
void GCDynamicLight::SetInnerAngle(float value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_InnerAngle", false, value);
}
float GCDynamicLight::GetOuterAngle() const {
    return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_OuterAngle");
}
void GCDynamicLight::SetOuterAngle(float value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_OuterAngle", false, value);
}
float GCDynamicLight::GetSpotRadius() const {
    return GetSchemaValue<float>(m_ptr, "CDynamicLight", "m_SpotRadius");
}
void GCDynamicLight::SetSpotRadius(float value) {
    SetSchemaValue(m_ptr, "CDynamicLight", "m_SpotRadius", false, value);
}
std::string GCDynamicLight::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDynamicLight::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCDynamicLight::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCDynamicLight::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDynamicLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicLight>("CDynamicLight")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ActualFlags", &GCDynamicLight::GetActualFlags, &GCDynamicLight::SetActualFlags)
        .addProperty("Flags", &GCDynamicLight::GetFlags, &GCDynamicLight::SetFlags)
        .addProperty("LightStyle", &GCDynamicLight::GetLightStyle, &GCDynamicLight::SetLightStyle)
        .addProperty("On", &GCDynamicLight::GetOn, &GCDynamicLight::SetOn)
        .addProperty("Radius", &GCDynamicLight::GetRadius, &GCDynamicLight::SetRadius)
        .addProperty("Exponent", &GCDynamicLight::GetExponent, &GCDynamicLight::SetExponent)
        .addProperty("InnerAngle", &GCDynamicLight::GetInnerAngle, &GCDynamicLight::SetInnerAngle)
        .addProperty("OuterAngle", &GCDynamicLight::GetOuterAngle, &GCDynamicLight::SetOuterAngle)
        .addProperty("SpotRadius", &GCDynamicLight::GetSpotRadius, &GCDynamicLight::SetSpotRadius)
        .addProperty("Parent", &GCDynamicLight::GetParent, &GCDynamicLight::SetParent)
        .addFunction("ToPtr", &GCDynamicLight::ToPtr)
        .addFunction("IsValid", &GCDynamicLight::IsValid)
        .endClass();
}