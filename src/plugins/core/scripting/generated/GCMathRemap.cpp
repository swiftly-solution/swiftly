#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMathRemap::GCMathRemap(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMathRemap::GCMathRemap(void *ptr) {
    m_ptr = ptr;
}
float GCMathRemap::GetInMin() const {
    return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flInMin");
}
void GCMathRemap::SetInMin(float value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_flInMin", false, value);
}
float GCMathRemap::GetInMax() const {
    return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flInMax");
}
void GCMathRemap::SetInMax(float value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_flInMax", false, value);
}
float GCMathRemap::GetOut1() const {
    return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flOut1");
}
void GCMathRemap::SetOut1(float value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_flOut1", false, value);
}
float GCMathRemap::GetOut2() const {
    return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flOut2");
}
void GCMathRemap::SetOut2(float value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_flOut2", false, value);
}
float GCMathRemap::GetOldInValue() const {
    return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flOldInValue");
}
void GCMathRemap::SetOldInValue(float value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_flOldInValue", false, value);
}
bool GCMathRemap::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CMathRemap", "m_bEnabled");
}
void GCMathRemap::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_bEnabled", false, value);
}
GCEntityIOOutput GCMathRemap::GetOnRoseAboveMin() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathRemap", "m_OnRoseAboveMin"));
    return value;
}
void GCMathRemap::SetOnRoseAboveMin(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_OnRoseAboveMin", false, value);
}
GCEntityIOOutput GCMathRemap::GetOnRoseAboveMax() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathRemap", "m_OnRoseAboveMax"));
    return value;
}
void GCMathRemap::SetOnRoseAboveMax(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_OnRoseAboveMax", false, value);
}
GCEntityIOOutput GCMathRemap::GetOnFellBelowMin() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathRemap", "m_OnFellBelowMin"));
    return value;
}
void GCMathRemap::SetOnFellBelowMin(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_OnFellBelowMin", false, value);
}
GCEntityIOOutput GCMathRemap::GetOnFellBelowMax() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathRemap", "m_OnFellBelowMax"));
    return value;
}
void GCMathRemap::SetOnFellBelowMax(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathRemap", "m_OnFellBelowMax", false, value);
}
std::string GCMathRemap::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMathRemap::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCMathRemap::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCMathRemap::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMathRemap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMathRemap>("CMathRemap")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InMin", &GCMathRemap::GetInMin, &GCMathRemap::SetInMin)
        .addProperty("InMax", &GCMathRemap::GetInMax, &GCMathRemap::SetInMax)
        .addProperty("Out1", &GCMathRemap::GetOut1, &GCMathRemap::SetOut1)
        .addProperty("Out2", &GCMathRemap::GetOut2, &GCMathRemap::SetOut2)
        .addProperty("OldInValue", &GCMathRemap::GetOldInValue, &GCMathRemap::SetOldInValue)
        .addProperty("Enabled", &GCMathRemap::GetEnabled, &GCMathRemap::SetEnabled)
        .addProperty("OnRoseAboveMin", &GCMathRemap::GetOnRoseAboveMin, &GCMathRemap::SetOnRoseAboveMin)
        .addProperty("OnRoseAboveMax", &GCMathRemap::GetOnRoseAboveMax, &GCMathRemap::SetOnRoseAboveMax)
        .addProperty("OnFellBelowMin", &GCMathRemap::GetOnFellBelowMin, &GCMathRemap::SetOnFellBelowMin)
        .addProperty("OnFellBelowMax", &GCMathRemap::GetOnFellBelowMax, &GCMathRemap::SetOnFellBelowMax)
        .addProperty("Parent", &GCMathRemap::GetParent, &GCMathRemap::SetParent)
        .addFunction("ToPtr", &GCMathRemap::ToPtr)
        .addFunction("IsValid", &GCMathRemap::IsValid)
        .endClass();
}