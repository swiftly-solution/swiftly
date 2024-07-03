#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMathCounter::GCMathCounter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMathCounter::GCMathCounter(void *ptr) {
    m_ptr = ptr;
}
float GCMathCounter::GetMin() const {
    return GetSchemaValue<float>(m_ptr, "CMathCounter", "m_flMin");
}
void GCMathCounter::SetMin(float value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_flMin", false, value);
}
float GCMathCounter::GetMax() const {
    return GetSchemaValue<float>(m_ptr, "CMathCounter", "m_flMax");
}
void GCMathCounter::SetMax(float value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_flMax", false, value);
}
bool GCMathCounter::GetHitMin() const {
    return GetSchemaValue<bool>(m_ptr, "CMathCounter", "m_bHitMin");
}
void GCMathCounter::SetHitMin(bool value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_bHitMin", false, value);
}
bool GCMathCounter::GetHitMax() const {
    return GetSchemaValue<bool>(m_ptr, "CMathCounter", "m_bHitMax");
}
void GCMathCounter::SetHitMax(bool value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_bHitMax", false, value);
}
bool GCMathCounter::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CMathCounter", "m_bDisabled");
}
void GCMathCounter::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_bDisabled", false, value);
}
GCEntityIOOutput GCMathCounter::GetOnHitMin() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathCounter", "m_OnHitMin"));
    return value;
}
void GCMathCounter::SetOnHitMin(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_OnHitMin", false, value);
}
GCEntityIOOutput GCMathCounter::GetOnHitMax() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathCounter", "m_OnHitMax"));
    return value;
}
void GCMathCounter::SetOnHitMax(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_OnHitMax", false, value);
}
GCEntityIOOutput GCMathCounter::GetOnChangedFromMin() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathCounter", "m_OnChangedFromMin"));
    return value;
}
void GCMathCounter::SetOnChangedFromMin(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_OnChangedFromMin", false, value);
}
GCEntityIOOutput GCMathCounter::GetOnChangedFromMax() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CMathCounter", "m_OnChangedFromMax"));
    return value;
}
void GCMathCounter::SetOnChangedFromMax(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CMathCounter", "m_OnChangedFromMax", false, value);
}
std::string GCMathCounter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMathCounter::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCMathCounter::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCMathCounter::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMathCounter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMathCounter>("CMathCounter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Min", &GCMathCounter::GetMin, &GCMathCounter::SetMin)
        .addProperty("Max", &GCMathCounter::GetMax, &GCMathCounter::SetMax)
        .addProperty("HitMin", &GCMathCounter::GetHitMin, &GCMathCounter::SetHitMin)
        .addProperty("HitMax", &GCMathCounter::GetHitMax, &GCMathCounter::SetHitMax)
        .addProperty("Disabled", &GCMathCounter::GetDisabled, &GCMathCounter::SetDisabled)
        .addProperty("OnHitMin", &GCMathCounter::GetOnHitMin, &GCMathCounter::SetOnHitMin)
        .addProperty("OnHitMax", &GCMathCounter::GetOnHitMax, &GCMathCounter::SetOnHitMax)
        .addProperty("OnChangedFromMin", &GCMathCounter::GetOnChangedFromMin, &GCMathCounter::SetOnChangedFromMin)
        .addProperty("OnChangedFromMax", &GCMathCounter::GetOnChangedFromMax, &GCMathCounter::SetOnChangedFromMax)
        .addProperty("Parent", &GCMathCounter::GetParent, &GCMathCounter::SetParent)
        .addFunction("ToPtr", &GCMathCounter::ToPtr)
        .addFunction("IsValid", &GCMathCounter::IsValid)
        .endClass();
}