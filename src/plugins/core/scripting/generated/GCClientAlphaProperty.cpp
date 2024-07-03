#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCClientAlphaProperty::GCClientAlphaProperty(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCClientAlphaProperty::GCClientAlphaProperty(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCClientAlphaProperty::GetRenderFX() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CClientAlphaProperty", "m_nRenderFX");
}
void GCClientAlphaProperty::SetRenderFX(uint8_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nRenderFX", false, value);
}
uint8_t GCClientAlphaProperty::GetRenderMode() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CClientAlphaProperty", "m_nRenderMode");
}
void GCClientAlphaProperty::SetRenderMode(uint8_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nRenderMode", false, value);
}
uint8_t GCClientAlphaProperty::GetAlpha() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CClientAlphaProperty", "m_nAlpha");
}
void GCClientAlphaProperty::SetAlpha(uint8_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nAlpha", false, value);
}
uint16_t GCClientAlphaProperty::GetDesyncOffset() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nDesyncOffset");
}
void GCClientAlphaProperty::SetDesyncOffset(uint16_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nDesyncOffset", false, value);
}
uint16_t GCClientAlphaProperty::GetReserved2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nReserved2");
}
void GCClientAlphaProperty::SetReserved2(uint16_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nReserved2", false, value);
}
uint16_t GCClientAlphaProperty::GetDistFadeStart() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nDistFadeStart");
}
void GCClientAlphaProperty::SetDistFadeStart(uint16_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nDistFadeStart", false, value);
}
uint16_t GCClientAlphaProperty::GetDistFadeEnd() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CClientAlphaProperty", "m_nDistFadeEnd");
}
void GCClientAlphaProperty::SetDistFadeEnd(uint16_t value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_nDistFadeEnd", false, value);
}
float GCClientAlphaProperty::GetFadeScale() const {
    return GetSchemaValue<float>(m_ptr, "CClientAlphaProperty", "m_flFadeScale");
}
void GCClientAlphaProperty::SetFadeScale(float value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_flFadeScale", false, value);
}
float GCClientAlphaProperty::GetRenderFxStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CClientAlphaProperty", "m_flRenderFxStartTime");
}
void GCClientAlphaProperty::SetRenderFxStartTime(float value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_flRenderFxStartTime", false, value);
}
float GCClientAlphaProperty::GetRenderFxDuration() const {
    return GetSchemaValue<float>(m_ptr, "CClientAlphaProperty", "m_flRenderFxDuration");
}
void GCClientAlphaProperty::SetRenderFxDuration(float value) {
    SetSchemaValue(m_ptr, "CClientAlphaProperty", "m_flRenderFxDuration", false, value);
}
std::string GCClientAlphaProperty::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCClientAlphaProperty::IsValid() {
    return (m_ptr != nullptr);
}
GIClientAlphaProperty GCClientAlphaProperty::GetParent() const {
    GIClientAlphaProperty value(m_ptr);
    return value;
}
void GCClientAlphaProperty::SetParent(GIClientAlphaProperty value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCClientAlphaProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCClientAlphaProperty>("CClientAlphaProperty")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RenderFX", &GCClientAlphaProperty::GetRenderFX, &GCClientAlphaProperty::SetRenderFX)
        .addProperty("RenderMode", &GCClientAlphaProperty::GetRenderMode, &GCClientAlphaProperty::SetRenderMode)
        .addProperty("Alpha", &GCClientAlphaProperty::GetAlpha, &GCClientAlphaProperty::SetAlpha)
        .addProperty("DesyncOffset", &GCClientAlphaProperty::GetDesyncOffset, &GCClientAlphaProperty::SetDesyncOffset)
        .addProperty("Reserved2", &GCClientAlphaProperty::GetReserved2, &GCClientAlphaProperty::SetReserved2)
        .addProperty("DistFadeStart", &GCClientAlphaProperty::GetDistFadeStart, &GCClientAlphaProperty::SetDistFadeStart)
        .addProperty("DistFadeEnd", &GCClientAlphaProperty::GetDistFadeEnd, &GCClientAlphaProperty::SetDistFadeEnd)
        .addProperty("FadeScale", &GCClientAlphaProperty::GetFadeScale, &GCClientAlphaProperty::SetFadeScale)
        .addProperty("RenderFxStartTime", &GCClientAlphaProperty::GetRenderFxStartTime, &GCClientAlphaProperty::SetRenderFxStartTime)
        .addProperty("RenderFxDuration", &GCClientAlphaProperty::GetRenderFxDuration, &GCClientAlphaProperty::SetRenderFxDuration)
        .addProperty("Parent", &GCClientAlphaProperty::GetParent, &GCClientAlphaProperty::SetParent)
        .addFunction("ToPtr", &GCClientAlphaProperty::ToPtr)
        .addFunction("IsValid", &GCClientAlphaProperty::IsValid)
        .endClass();
}