#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSpotlightEnd::GCSpotlightEnd(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSpotlightEnd::GCSpotlightEnd(void *ptr) {
    m_ptr = ptr;
}
float GCSpotlightEnd::GetLightScale() const {
    return GetSchemaValue<float>(m_ptr, "CSpotlightEnd", "m_flLightScale");
}
void GCSpotlightEnd::SetLightScale(float value) {
    SetSchemaValue(m_ptr, "CSpotlightEnd", "m_flLightScale", false, value);
}
float GCSpotlightEnd::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CSpotlightEnd", "m_Radius");
}
void GCSpotlightEnd::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CSpotlightEnd", "m_Radius", false, value);
}
Vector GCSpotlightEnd::GetSpotlightDir() const {
    return GetSchemaValue<Vector>(m_ptr, "CSpotlightEnd", "m_vSpotlightDir");
}
void GCSpotlightEnd::SetSpotlightDir(Vector value) {
    SetSchemaValue(m_ptr, "CSpotlightEnd", "m_vSpotlightDir", false, value);
}
Vector GCSpotlightEnd::GetSpotlightOrg() const {
    return GetSchemaValue<Vector>(m_ptr, "CSpotlightEnd", "m_vSpotlightOrg");
}
void GCSpotlightEnd::SetSpotlightOrg(Vector value) {
    SetSchemaValue(m_ptr, "CSpotlightEnd", "m_vSpotlightOrg", false, value);
}
std::string GCSpotlightEnd::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSpotlightEnd::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCSpotlightEnd::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCSpotlightEnd::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSpotlightEnd(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpotlightEnd>("CSpotlightEnd")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LightScale", &GCSpotlightEnd::GetLightScale, &GCSpotlightEnd::SetLightScale)
        .addProperty("Radius", &GCSpotlightEnd::GetRadius, &GCSpotlightEnd::SetRadius)
        .addProperty("SpotlightDir", &GCSpotlightEnd::GetSpotlightDir, &GCSpotlightEnd::SetSpotlightDir)
        .addProperty("SpotlightOrg", &GCSpotlightEnd::GetSpotlightOrg, &GCSpotlightEnd::SetSpotlightOrg)
        .addProperty("Parent", &GCSpotlightEnd::GetParent, &GCSpotlightEnd::SetParent)
        .addFunction("ToPtr", &GCSpotlightEnd::ToPtr)
        .addFunction("IsValid", &GCSpotlightEnd::IsValid)
        .endClass();
}