#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGlowProperty::GCGlowProperty(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGlowProperty::GCGlowProperty(void *ptr) {
    m_ptr = ptr;
}
Vector GCGlowProperty::GetGlowColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CGlowProperty", "m_fGlowColor");
}
void GCGlowProperty::SetGlowColor(Vector value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_fGlowColor", false, value);
}
int32_t GCGlowProperty::GetGlowType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_iGlowType");
}
void GCGlowProperty::SetGlowType(int32_t value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_iGlowType", false, value);
}
int32_t GCGlowProperty::GetGlowTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_iGlowTeam");
}
void GCGlowProperty::SetGlowTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_iGlowTeam", false, value);
}
int32_t GCGlowProperty::GetGlowRange() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_nGlowRange");
}
void GCGlowProperty::SetGlowRange(int32_t value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_nGlowRange", false, value);
}
int32_t GCGlowProperty::GetGlowRangeMin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_nGlowRangeMin");
}
void GCGlowProperty::SetGlowRangeMin(int32_t value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_nGlowRangeMin", false, value);
}
Color GCGlowProperty::GetGlowColorOverride() const {
    return GetSchemaValue<Color>(m_ptr, "CGlowProperty", "m_glowColorOverride");
}
void GCGlowProperty::SetGlowColorOverride(Color value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_glowColorOverride", false, value);
}
bool GCGlowProperty::GetFlashing() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowProperty", "m_bFlashing");
}
void GCGlowProperty::SetFlashing(bool value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_bFlashing", false, value);
}
float GCGlowProperty::GetGlowTime() const {
    return GetSchemaValue<float>(m_ptr, "CGlowProperty", "m_flGlowTime");
}
void GCGlowProperty::SetGlowTime(float value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_flGlowTime", false, value);
}
float GCGlowProperty::GetGlowStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CGlowProperty", "m_flGlowStartTime");
}
void GCGlowProperty::SetGlowStartTime(float value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_flGlowStartTime", false, value);
}
bool GCGlowProperty::GetEligibleForScreenHighlight() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowProperty", "m_bEligibleForScreenHighlight");
}
void GCGlowProperty::SetEligibleForScreenHighlight(bool value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_bEligibleForScreenHighlight", false, value);
}
bool GCGlowProperty::GetGlowing() const {
    return GetSchemaValue<bool>(m_ptr, "CGlowProperty", "m_bGlowing");
}
void GCGlowProperty::SetGlowing(bool value) {
    SetSchemaValue(m_ptr, "CGlowProperty", "m_bGlowing", false, value);
}
std::string GCGlowProperty::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGlowProperty::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGlowProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlowProperty>("CGlowProperty")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GlowColor", &GCGlowProperty::GetGlowColor, &GCGlowProperty::SetGlowColor)
        .addProperty("GlowType", &GCGlowProperty::GetGlowType, &GCGlowProperty::SetGlowType)
        .addProperty("GlowTeam", &GCGlowProperty::GetGlowTeam, &GCGlowProperty::SetGlowTeam)
        .addProperty("GlowRange", &GCGlowProperty::GetGlowRange, &GCGlowProperty::SetGlowRange)
        .addProperty("GlowRangeMin", &GCGlowProperty::GetGlowRangeMin, &GCGlowProperty::SetGlowRangeMin)
        .addProperty("GlowColorOverride", &GCGlowProperty::GetGlowColorOverride, &GCGlowProperty::SetGlowColorOverride)
        .addProperty("Flashing", &GCGlowProperty::GetFlashing, &GCGlowProperty::SetFlashing)
        .addProperty("GlowTime", &GCGlowProperty::GetGlowTime, &GCGlowProperty::SetGlowTime)
        .addProperty("GlowStartTime", &GCGlowProperty::GetGlowStartTime, &GCGlowProperty::SetGlowStartTime)
        .addProperty("EligibleForScreenHighlight", &GCGlowProperty::GetEligibleForScreenHighlight, &GCGlowProperty::SetEligibleForScreenHighlight)
        .addProperty("Glowing", &GCGlowProperty::GetGlowing, &GCGlowProperty::SetGlowing)
        .addFunction("ToPtr", &GCGlowProperty::ToPtr)
        .addFunction("IsValid", &GCGlowProperty::IsValid)
        .endClass();
}