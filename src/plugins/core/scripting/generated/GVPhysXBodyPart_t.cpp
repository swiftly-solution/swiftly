#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXBodyPart_t::GVPhysXBodyPart_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXBodyPart_t::GVPhysXBodyPart_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GVPhysXBodyPart_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VPhysXBodyPart_t", "m_nFlags");
}
void GVPhysXBodyPart_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_nFlags", true, value);
}
float GVPhysXBodyPart_t::GetMass() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flMass");
}
void GVPhysXBodyPart_t::SetMass(float value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flMass", true, value);
}
GVPhysics2ShapeDef_t GVPhysXBodyPart_t::GetRnShape() const {
    GVPhysics2ShapeDef_t value(GetSchemaPtr(m_ptr, "VPhysXBodyPart_t", "m_rnShape"));
    return value;
}
void GVPhysXBodyPart_t::SetRnShape(GVPhysics2ShapeDef_t value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_rnShape", true, value);
}
uint16_t GVPhysXBodyPart_t::GetCollisionAttributeIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXBodyPart_t", "m_nCollisionAttributeIndex");
}
void GVPhysXBodyPart_t::SetCollisionAttributeIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_nCollisionAttributeIndex", true, value);
}
uint16_t GVPhysXBodyPart_t::GetReserved() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXBodyPart_t", "m_nReserved");
}
void GVPhysXBodyPart_t::SetReserved(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_nReserved", true, value);
}
float GVPhysXBodyPart_t::GetInertiaScale() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flInertiaScale");
}
void GVPhysXBodyPart_t::SetInertiaScale(float value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flInertiaScale", true, value);
}
float GVPhysXBodyPart_t::GetLinearDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flLinearDamping");
}
void GVPhysXBodyPart_t::SetLinearDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flLinearDamping", true, value);
}
float GVPhysXBodyPart_t::GetAngularDamping() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXBodyPart_t", "m_flAngularDamping");
}
void GVPhysXBodyPart_t::SetAngularDamping(float value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_flAngularDamping", true, value);
}
bool GVPhysXBodyPart_t::GetOverrideMassCenter() const {
    return GetSchemaValue<bool>(m_ptr, "VPhysXBodyPart_t", "m_bOverrideMassCenter");
}
void GVPhysXBodyPart_t::SetOverrideMassCenter(bool value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_bOverrideMassCenter", true, value);
}
Vector GVPhysXBodyPart_t::GetMassCenterOverride() const {
    return GetSchemaValue<Vector>(m_ptr, "VPhysXBodyPart_t", "m_vMassCenterOverride");
}
void GVPhysXBodyPart_t::SetMassCenterOverride(Vector value) {
    SetSchemaValue(m_ptr, "VPhysXBodyPart_t", "m_vMassCenterOverride", true, value);
}
std::string GVPhysXBodyPart_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXBodyPart_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXBodyPart_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXBodyPart_t>("VPhysXBodyPart_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GVPhysXBodyPart_t::GetFlags, &GVPhysXBodyPart_t::SetFlags)
        .addProperty("Mass", &GVPhysXBodyPart_t::GetMass, &GVPhysXBodyPart_t::SetMass)
        .addProperty("RnShape", &GVPhysXBodyPart_t::GetRnShape, &GVPhysXBodyPart_t::SetRnShape)
        .addProperty("CollisionAttributeIndex", &GVPhysXBodyPart_t::GetCollisionAttributeIndex, &GVPhysXBodyPart_t::SetCollisionAttributeIndex)
        .addProperty("Reserved", &GVPhysXBodyPart_t::GetReserved, &GVPhysXBodyPart_t::SetReserved)
        .addProperty("InertiaScale", &GVPhysXBodyPart_t::GetInertiaScale, &GVPhysXBodyPart_t::SetInertiaScale)
        .addProperty("LinearDamping", &GVPhysXBodyPart_t::GetLinearDamping, &GVPhysXBodyPart_t::SetLinearDamping)
        .addProperty("AngularDamping", &GVPhysXBodyPart_t::GetAngularDamping, &GVPhysXBodyPart_t::SetAngularDamping)
        .addProperty("OverrideMassCenter", &GVPhysXBodyPart_t::GetOverrideMassCenter, &GVPhysXBodyPart_t::SetOverrideMassCenter)
        .addProperty("MassCenterOverride", &GVPhysXBodyPart_t::GetMassCenterOverride, &GVPhysXBodyPart_t::SetMassCenterOverride)
        .addFunction("ToPtr", &GVPhysXBodyPart_t::ToPtr)
        .addFunction("IsValid", &GVPhysXBodyPart_t::IsValid)
        .endClass();
}