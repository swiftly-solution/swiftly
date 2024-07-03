#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCollisionProperty::GCCollisionProperty(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCollisionProperty::GCCollisionProperty(void *ptr) {
    m_ptr = ptr;
}
GVPhysicsCollisionAttribute_t GCCollisionProperty::GetCollisionAttribute() const {
    GVPhysicsCollisionAttribute_t value(GetSchemaPtr(m_ptr, "CCollisionProperty", "m_collisionAttribute"));
    return value;
}
void GCCollisionProperty::SetCollisionAttribute(GVPhysicsCollisionAttribute_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_collisionAttribute", false, value);
}
Vector GCCollisionProperty::GetMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecMins");
}
void GCCollisionProperty::SetMins(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecMins", false, value);
}
Vector GCCollisionProperty::GetMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecMaxs");
}
void GCCollisionProperty::SetMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecMaxs", false, value);
}
uint8_t GCCollisionProperty::GetSolidFlags() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_usSolidFlags");
}
void GCCollisionProperty::SetSolidFlags(uint8_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_usSolidFlags", false, value);
}
uint64_t GCCollisionProperty::GetSolidType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCollisionProperty", "m_nSolidType");
}
void GCCollisionProperty::SetSolidType(uint64_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_nSolidType", false, value);
}
uint8_t GCCollisionProperty::GetTriggerBloat() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_triggerBloat");
}
void GCCollisionProperty::SetTriggerBloat(uint8_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_triggerBloat", false, value);
}
uint64_t GCCollisionProperty::GetSurroundType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCollisionProperty", "m_nSurroundType");
}
void GCCollisionProperty::SetSurroundType(uint64_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_nSurroundType", false, value);
}
uint8_t GCCollisionProperty::GetCollisionGroup() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_CollisionGroup");
}
void GCCollisionProperty::SetCollisionGroup(uint8_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_CollisionGroup", false, value);
}
uint8_t GCCollisionProperty::GetEnablePhysics() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CCollisionProperty", "m_nEnablePhysics");
}
void GCCollisionProperty::SetEnablePhysics(uint8_t value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_nEnablePhysics", false, value);
}
float GCCollisionProperty::GetBoundingRadius() const {
    return GetSchemaValue<float>(m_ptr, "CCollisionProperty", "m_flBoundingRadius");
}
void GCCollisionProperty::SetBoundingRadius(float value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_flBoundingRadius", false, value);
}
Vector GCCollisionProperty::GetSpecifiedSurroundingMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMins");
}
void GCCollisionProperty::SetSpecifiedSurroundingMins(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMins", false, value);
}
Vector GCCollisionProperty::GetSpecifiedSurroundingMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMaxs");
}
void GCCollisionProperty::SetSpecifiedSurroundingMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSpecifiedSurroundingMaxs", false, value);
}
Vector GCCollisionProperty::GetSurroundingMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSurroundingMaxs");
}
void GCCollisionProperty::SetSurroundingMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSurroundingMaxs", false, value);
}
Vector GCCollisionProperty::GetSurroundingMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vecSurroundingMins");
}
void GCCollisionProperty::SetSurroundingMins(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vecSurroundingMins", false, value);
}
Vector GCCollisionProperty::GetCapsuleCenter1() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vCapsuleCenter1");
}
void GCCollisionProperty::SetCapsuleCenter1(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vCapsuleCenter1", false, value);
}
Vector GCCollisionProperty::GetCapsuleCenter2() const {
    return GetSchemaValue<Vector>(m_ptr, "CCollisionProperty", "m_vCapsuleCenter2");
}
void GCCollisionProperty::SetCapsuleCenter2(Vector value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_vCapsuleCenter2", false, value);
}
float GCCollisionProperty::GetCapsuleRadius() const {
    return GetSchemaValue<float>(m_ptr, "CCollisionProperty", "m_flCapsuleRadius");
}
void GCCollisionProperty::SetCapsuleRadius(float value) {
    SetSchemaValue(m_ptr, "CCollisionProperty", "m_flCapsuleRadius", false, value);
}
std::string GCCollisionProperty::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCollisionProperty::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCollisionProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCollisionProperty>("CCollisionProperty")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CollisionAttribute", &GCCollisionProperty::GetCollisionAttribute, &GCCollisionProperty::SetCollisionAttribute)
        .addProperty("Mins", &GCCollisionProperty::GetMins, &GCCollisionProperty::SetMins)
        .addProperty("Maxs", &GCCollisionProperty::GetMaxs, &GCCollisionProperty::SetMaxs)
        .addProperty("SolidFlags", &GCCollisionProperty::GetSolidFlags, &GCCollisionProperty::SetSolidFlags)
        .addProperty("SolidType", &GCCollisionProperty::GetSolidType, &GCCollisionProperty::SetSolidType)
        .addProperty("TriggerBloat", &GCCollisionProperty::GetTriggerBloat, &GCCollisionProperty::SetTriggerBloat)
        .addProperty("SurroundType", &GCCollisionProperty::GetSurroundType, &GCCollisionProperty::SetSurroundType)
        .addProperty("CollisionGroup", &GCCollisionProperty::GetCollisionGroup, &GCCollisionProperty::SetCollisionGroup)
        .addProperty("EnablePhysics", &GCCollisionProperty::GetEnablePhysics, &GCCollisionProperty::SetEnablePhysics)
        .addProperty("BoundingRadius", &GCCollisionProperty::GetBoundingRadius, &GCCollisionProperty::SetBoundingRadius)
        .addProperty("SpecifiedSurroundingMins", &GCCollisionProperty::GetSpecifiedSurroundingMins, &GCCollisionProperty::SetSpecifiedSurroundingMins)
        .addProperty("SpecifiedSurroundingMaxs", &GCCollisionProperty::GetSpecifiedSurroundingMaxs, &GCCollisionProperty::SetSpecifiedSurroundingMaxs)
        .addProperty("SurroundingMaxs", &GCCollisionProperty::GetSurroundingMaxs, &GCCollisionProperty::SetSurroundingMaxs)
        .addProperty("SurroundingMins", &GCCollisionProperty::GetSurroundingMins, &GCCollisionProperty::SetSurroundingMins)
        .addProperty("CapsuleCenter1", &GCCollisionProperty::GetCapsuleCenter1, &GCCollisionProperty::SetCapsuleCenter1)
        .addProperty("CapsuleCenter2", &GCCollisionProperty::GetCapsuleCenter2, &GCCollisionProperty::SetCapsuleCenter2)
        .addProperty("CapsuleRadius", &GCCollisionProperty::GetCapsuleRadius, &GCCollisionProperty::SetCapsuleRadius)
        .addFunction("ToPtr", &GCCollisionProperty::ToPtr)
        .addFunction("IsValid", &GCCollisionProperty::IsValid)
        .endClass();
}