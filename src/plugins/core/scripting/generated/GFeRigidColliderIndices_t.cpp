#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeRigidColliderIndices_t::GFeRigidColliderIndices_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeRigidColliderIndices_t::GFeRigidColliderIndices_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeRigidColliderIndices_t::GetTaperedCapsuleRigidIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nTaperedCapsuleRigidIndex");
}
void GFeRigidColliderIndices_t::SetTaperedCapsuleRigidIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nTaperedCapsuleRigidIndex", true, value);
}
uint16_t GFeRigidColliderIndices_t::GetSphereRigidIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nSphereRigidIndex");
}
void GFeRigidColliderIndices_t::SetSphereRigidIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nSphereRigidIndex", true, value);
}
uint16_t GFeRigidColliderIndices_t::GetBoxRigidIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nBoxRigidIndex");
}
void GFeRigidColliderIndices_t::SetBoxRigidIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nBoxRigidIndex", true, value);
}
uint16_t GFeRigidColliderIndices_t::GetCollisionPlaneIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeRigidColliderIndices_t", "m_nCollisionPlaneIndex");
}
void GFeRigidColliderIndices_t::SetCollisionPlaneIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeRigidColliderIndices_t", "m_nCollisionPlaneIndex", true, value);
}
std::string GFeRigidColliderIndices_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeRigidColliderIndices_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeRigidColliderIndices_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeRigidColliderIndices_t>("FeRigidColliderIndices_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TaperedCapsuleRigidIndex", &GFeRigidColliderIndices_t::GetTaperedCapsuleRigidIndex, &GFeRigidColliderIndices_t::SetTaperedCapsuleRigidIndex)
        .addProperty("SphereRigidIndex", &GFeRigidColliderIndices_t::GetSphereRigidIndex, &GFeRigidColliderIndices_t::SetSphereRigidIndex)
        .addProperty("BoxRigidIndex", &GFeRigidColliderIndices_t::GetBoxRigidIndex, &GFeRigidColliderIndices_t::SetBoxRigidIndex)
        .addProperty("CollisionPlaneIndex", &GFeRigidColliderIndices_t::GetCollisionPlaneIndex, &GFeRigidColliderIndices_t::SetCollisionPlaneIndex)
        .addFunction("ToPtr", &GFeRigidColliderIndices_t::ToPtr)
        .addFunction("IsValid", &GFeRigidColliderIndices_t::IsValid)
        .endClass();
}