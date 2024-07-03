#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollConstraint::GCRagdollConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollConstraint::GCRagdollConstraint(void *ptr) {
    m_ptr = ptr;
}
float GCRagdollConstraint::GetXmin() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_xmin");
}
void GCRagdollConstraint::SetXmin(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_xmin", false, value);
}
float GCRagdollConstraint::GetXmax() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_xmax");
}
void GCRagdollConstraint::SetXmax(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_xmax", false, value);
}
float GCRagdollConstraint::GetYmin() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_ymin");
}
void GCRagdollConstraint::SetYmin(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_ymin", false, value);
}
float GCRagdollConstraint::GetYmax() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_ymax");
}
void GCRagdollConstraint::SetYmax(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_ymax", false, value);
}
float GCRagdollConstraint::GetZmin() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_zmin");
}
void GCRagdollConstraint::SetZmin(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_zmin", false, value);
}
float GCRagdollConstraint::GetZmax() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_zmax");
}
void GCRagdollConstraint::SetZmax(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_zmax", false, value);
}
float GCRagdollConstraint::GetXfriction() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_xfriction");
}
void GCRagdollConstraint::SetXfriction(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_xfriction", false, value);
}
float GCRagdollConstraint::GetYfriction() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_yfriction");
}
void GCRagdollConstraint::SetYfriction(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_yfriction", false, value);
}
float GCRagdollConstraint::GetZfriction() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollConstraint", "m_zfriction");
}
void GCRagdollConstraint::SetZfriction(float value) {
    SetSchemaValue(m_ptr, "CRagdollConstraint", "m_zfriction", false, value);
}
std::string GCRagdollConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCRagdollConstraint::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCRagdollConstraint::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollConstraint>("CRagdollConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Xmin", &GCRagdollConstraint::GetXmin, &GCRagdollConstraint::SetXmin)
        .addProperty("Xmax", &GCRagdollConstraint::GetXmax, &GCRagdollConstraint::SetXmax)
        .addProperty("Ymin", &GCRagdollConstraint::GetYmin, &GCRagdollConstraint::SetYmin)
        .addProperty("Ymax", &GCRagdollConstraint::GetYmax, &GCRagdollConstraint::SetYmax)
        .addProperty("Zmin", &GCRagdollConstraint::GetZmin, &GCRagdollConstraint::SetZmin)
        .addProperty("Zmax", &GCRagdollConstraint::GetZmax, &GCRagdollConstraint::SetZmax)
        .addProperty("Xfriction", &GCRagdollConstraint::GetXfriction, &GCRagdollConstraint::SetXfriction)
        .addProperty("Yfriction", &GCRagdollConstraint::GetYfriction, &GCRagdollConstraint::SetYfriction)
        .addProperty("Zfriction", &GCRagdollConstraint::GetZfriction, &GCRagdollConstraint::SetZfriction)
        .addProperty("Parent", &GCRagdollConstraint::GetParent, &GCRagdollConstraint::SetParent)
        .addFunction("ToPtr", &GCRagdollConstraint::ToPtr)
        .addFunction("IsValid", &GCRagdollConstraint::IsValid)
        .endClass();
}