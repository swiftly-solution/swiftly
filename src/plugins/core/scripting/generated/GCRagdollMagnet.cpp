#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollMagnet::GCRagdollMagnet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollMagnet::GCRagdollMagnet(void *ptr) {
    m_ptr = ptr;
}
bool GCRagdollMagnet::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollMagnet", "m_bDisabled");
}
void GCRagdollMagnet::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CRagdollMagnet", "m_bDisabled", false, value);
}
float GCRagdollMagnet::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollMagnet", "m_radius");
}
void GCRagdollMagnet::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CRagdollMagnet", "m_radius", false, value);
}
float GCRagdollMagnet::GetForce() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollMagnet", "m_force");
}
void GCRagdollMagnet::SetForce(float value) {
    SetSchemaValue(m_ptr, "CRagdollMagnet", "m_force", false, value);
}
Vector GCRagdollMagnet::GetAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CRagdollMagnet", "m_axis");
}
void GCRagdollMagnet::SetAxis(Vector value) {
    SetSchemaValue(m_ptr, "CRagdollMagnet", "m_axis", false, value);
}
std::string GCRagdollMagnet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollMagnet::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCRagdollMagnet::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCRagdollMagnet::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollMagnet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollMagnet>("CRagdollMagnet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCRagdollMagnet::GetDisabled, &GCRagdollMagnet::SetDisabled)
        .addProperty("Radius", &GCRagdollMagnet::GetRadius, &GCRagdollMagnet::SetRadius)
        .addProperty("Force", &GCRagdollMagnet::GetForce, &GCRagdollMagnet::SetForce)
        .addProperty("Axis", &GCRagdollMagnet::GetAxis, &GCRagdollMagnet::SetAxis)
        .addProperty("Parent", &GCRagdollMagnet::GetParent, &GCRagdollMagnet::SetParent)
        .addFunction("ToPtr", &GCRagdollMagnet::ToPtr)
        .addFunction("IsValid", &GCRagdollMagnet::IsValid)
        .endClass();
}