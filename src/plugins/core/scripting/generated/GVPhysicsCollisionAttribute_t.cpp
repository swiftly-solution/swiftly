#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysicsCollisionAttribute_t::GVPhysicsCollisionAttribute_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysicsCollisionAttribute_t::GVPhysicsCollisionAttribute_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GVPhysicsCollisionAttribute_t::GetInteractsAs() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsAs");
}
void GVPhysicsCollisionAttribute_t::SetInteractsAs(uint64_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsAs", true, value);
}
uint64_t GVPhysicsCollisionAttribute_t::GetInteractsWith() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsWith");
}
void GVPhysicsCollisionAttribute_t::SetInteractsWith(uint64_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsWith", true, value);
}
uint64_t GVPhysicsCollisionAttribute_t::GetInteractsExclude() const {
    return GetSchemaValue<uint64_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsExclude");
}
void GVPhysicsCollisionAttribute_t::SetInteractsExclude(uint64_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nInteractsExclude", true, value);
}
uint32_t GVPhysicsCollisionAttribute_t::GetEntityId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nEntityId");
}
void GVPhysicsCollisionAttribute_t::SetEntityId(uint32_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nEntityId", true, value);
}
uint32_t GVPhysicsCollisionAttribute_t::GetOwnerId() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nOwnerId");
}
void GVPhysicsCollisionAttribute_t::SetOwnerId(uint32_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nOwnerId", true, value);
}
uint16_t GVPhysicsCollisionAttribute_t::GetHierarchyId() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nHierarchyId");
}
void GVPhysicsCollisionAttribute_t::SetHierarchyId(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nHierarchyId", true, value);
}
uint8_t GVPhysicsCollisionAttribute_t::GetCollisionGroup() const {
    return GetSchemaValue<uint8_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionGroup");
}
void GVPhysicsCollisionAttribute_t::SetCollisionGroup(uint8_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionGroup", true, value);
}
uint8_t GVPhysicsCollisionAttribute_t::GetCollisionFunctionMask() const {
    return GetSchemaValue<uint8_t>(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionFunctionMask");
}
void GVPhysicsCollisionAttribute_t::SetCollisionFunctionMask(uint8_t value) {
    SetSchemaValue(m_ptr, "VPhysicsCollisionAttribute_t", "m_nCollisionFunctionMask", true, value);
}
std::string GVPhysicsCollisionAttribute_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysicsCollisionAttribute_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysicsCollisionAttribute_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysicsCollisionAttribute_t>("VPhysicsCollisionAttribute_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InteractsAs", &GVPhysicsCollisionAttribute_t::GetInteractsAs, &GVPhysicsCollisionAttribute_t::SetInteractsAs)
        .addProperty("InteractsWith", &GVPhysicsCollisionAttribute_t::GetInteractsWith, &GVPhysicsCollisionAttribute_t::SetInteractsWith)
        .addProperty("InteractsExclude", &GVPhysicsCollisionAttribute_t::GetInteractsExclude, &GVPhysicsCollisionAttribute_t::SetInteractsExclude)
        .addProperty("EntityId", &GVPhysicsCollisionAttribute_t::GetEntityId, &GVPhysicsCollisionAttribute_t::SetEntityId)
        .addProperty("OwnerId", &GVPhysicsCollisionAttribute_t::GetOwnerId, &GVPhysicsCollisionAttribute_t::SetOwnerId)
        .addProperty("HierarchyId", &GVPhysicsCollisionAttribute_t::GetHierarchyId, &GVPhysicsCollisionAttribute_t::SetHierarchyId)
        .addProperty("CollisionGroup", &GVPhysicsCollisionAttribute_t::GetCollisionGroup, &GVPhysicsCollisionAttribute_t::SetCollisionGroup)
        .addProperty("CollisionFunctionMask", &GVPhysicsCollisionAttribute_t::GetCollisionFunctionMask, &GVPhysicsCollisionAttribute_t::SetCollisionFunctionMask)
        .addFunction("ToPtr", &GVPhysicsCollisionAttribute_t::ToPtr)
        .addFunction("IsValid", &GVPhysicsCollisionAttribute_t::IsValid)
        .endClass();
}