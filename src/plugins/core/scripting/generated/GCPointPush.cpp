#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointPush::GCPointPush(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointPush::GCPointPush(void *ptr) {
    m_ptr = ptr;
}
bool GCPointPush::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointPush", "m_bEnabled");
}
void GCPointPush::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CPointPush", "m_bEnabled", false, value);
}
float GCPointPush::GetMagnitude() const {
    return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flMagnitude");
}
void GCPointPush::SetMagnitude(float value) {
    SetSchemaValue(m_ptr, "CPointPush", "m_flMagnitude", false, value);
}
float GCPointPush::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flRadius");
}
void GCPointPush::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPointPush", "m_flRadius", false, value);
}
float GCPointPush::GetInnerRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flInnerRadius");
}
void GCPointPush::SetInnerRadius(float value) {
    SetSchemaValue(m_ptr, "CPointPush", "m_flInnerRadius", false, value);
}
float GCPointPush::GetConeOfInfluence() const {
    return GetSchemaValue<float>(m_ptr, "CPointPush", "m_flConeOfInfluence");
}
void GCPointPush::SetConeOfInfluence(float value) {
    SetSchemaValue(m_ptr, "CPointPush", "m_flConeOfInfluence", false, value);
}
std::string GCPointPush::GetFilterName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointPush", "m_iszFilterName").String();
}
void GCPointPush::SetFilterName(std::string value) {
    SetSchemaValue(m_ptr, "CPointPush", "m_iszFilterName", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseFilter GCPointPush::GetFilter() const {
    GCBaseFilter value(*GetSchemaValuePtr<void*>(m_ptr, "CPointPush", "m_hFilter"));
    return value;
}
void GCPointPush::SetFilter(GCBaseFilter* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Filter' is not possible.\n");
}
std::string GCPointPush::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointPush::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointPush::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointPush::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointPush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointPush>("CPointPush")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Enabled", &GCPointPush::GetEnabled, &GCPointPush::SetEnabled)
        .addProperty("Magnitude", &GCPointPush::GetMagnitude, &GCPointPush::SetMagnitude)
        .addProperty("Radius", &GCPointPush::GetRadius, &GCPointPush::SetRadius)
        .addProperty("InnerRadius", &GCPointPush::GetInnerRadius, &GCPointPush::SetInnerRadius)
        .addProperty("ConeOfInfluence", &GCPointPush::GetConeOfInfluence, &GCPointPush::SetConeOfInfluence)
        .addProperty("FilterName", &GCPointPush::GetFilterName, &GCPointPush::SetFilterName)
        .addProperty("Filter", &GCPointPush::GetFilter, &GCPointPush::SetFilter)
        .addProperty("Parent", &GCPointPush::GetParent, &GCPointPush::SetParent)
        .addFunction("ToPtr", &GCPointPush::ToPtr)
        .addFunction("IsValid", &GCPointPush::IsValid)
        .endClass();
}