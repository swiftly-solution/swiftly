#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysSurfacePropertiesPhysics::GCPhysSurfacePropertiesPhysics(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysSurfacePropertiesPhysics::GCPhysSurfacePropertiesPhysics(void *ptr) {
    m_ptr = ptr;
}
float GCPhysSurfacePropertiesPhysics::GetFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_friction");
}
void GCPhysSurfacePropertiesPhysics::SetFriction(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_friction", false, value);
}
float GCPhysSurfacePropertiesPhysics::GetElasticity() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_elasticity");
}
void GCPhysSurfacePropertiesPhysics::SetElasticity(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_elasticity", false, value);
}
float GCPhysSurfacePropertiesPhysics::GetDensity() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_density");
}
void GCPhysSurfacePropertiesPhysics::SetDensity(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_density", false, value);
}
float GCPhysSurfacePropertiesPhysics::GetThickness() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_thickness");
}
void GCPhysSurfacePropertiesPhysics::SetThickness(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_thickness", false, value);
}
float GCPhysSurfacePropertiesPhysics::GetSoftContactFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactFrequency");
}
void GCPhysSurfacePropertiesPhysics::SetSoftContactFrequency(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactFrequency", false, value);
}
float GCPhysSurfacePropertiesPhysics::GetSoftContactDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactDampingRatio");
}
void GCPhysSurfacePropertiesPhysics::SetSoftContactDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_softContactDampingRatio", false, value);
}
float GCPhysSurfacePropertiesPhysics::GetWheelDrag() const {
    return GetSchemaValue<float>(m_ptr, "CPhysSurfacePropertiesPhysics", "m_wheelDrag");
}
void GCPhysSurfacePropertiesPhysics::SetWheelDrag(float value) {
    SetSchemaValue(m_ptr, "CPhysSurfacePropertiesPhysics", "m_wheelDrag", false, value);
}
std::string GCPhysSurfacePropertiesPhysics::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysSurfacePropertiesPhysics::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCPhysSurfacePropertiesPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfacePropertiesPhysics>("CPhysSurfacePropertiesPhysics")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Friction", &GCPhysSurfacePropertiesPhysics::GetFriction, &GCPhysSurfacePropertiesPhysics::SetFriction)
        .addProperty("Elasticity", &GCPhysSurfacePropertiesPhysics::GetElasticity, &GCPhysSurfacePropertiesPhysics::SetElasticity)
        .addProperty("Density", &GCPhysSurfacePropertiesPhysics::GetDensity, &GCPhysSurfacePropertiesPhysics::SetDensity)
        .addProperty("Thickness", &GCPhysSurfacePropertiesPhysics::GetThickness, &GCPhysSurfacePropertiesPhysics::SetThickness)
        .addProperty("SoftContactFrequency", &GCPhysSurfacePropertiesPhysics::GetSoftContactFrequency, &GCPhysSurfacePropertiesPhysics::SetSoftContactFrequency)
        .addProperty("SoftContactDampingRatio", &GCPhysSurfacePropertiesPhysics::GetSoftContactDampingRatio, &GCPhysSurfacePropertiesPhysics::SetSoftContactDampingRatio)
        .addProperty("WheelDrag", &GCPhysSurfacePropertiesPhysics::GetWheelDrag, &GCPhysSurfacePropertiesPhysics::SetWheelDrag)
        .addFunction("ToPtr", &GCPhysSurfacePropertiesPhysics::ToPtr)
        .addFunction("IsValid", &GCPhysSurfacePropertiesPhysics::IsValid)
        .endClass();
}