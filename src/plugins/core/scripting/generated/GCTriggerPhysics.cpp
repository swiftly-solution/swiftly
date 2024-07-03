#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerPhysics::GCTriggerPhysics(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerPhysics::GCTriggerPhysics(void *ptr) {
    m_ptr = ptr;
}
float GCTriggerPhysics::GetGravityScale() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_gravityScale");
}
void GCTriggerPhysics::SetGravityScale(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_gravityScale", false, value);
}
float GCTriggerPhysics::GetLinearLimit() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_linearLimit");
}
void GCTriggerPhysics::SetLinearLimit(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_linearLimit", false, value);
}
float GCTriggerPhysics::GetLinearDamping() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_linearDamping");
}
void GCTriggerPhysics::SetLinearDamping(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_linearDamping", false, value);
}
float GCTriggerPhysics::GetAngularLimit() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_angularLimit");
}
void GCTriggerPhysics::SetAngularLimit(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_angularLimit", false, value);
}
float GCTriggerPhysics::GetAngularDamping() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_angularDamping");
}
void GCTriggerPhysics::SetAngularDamping(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_angularDamping", false, value);
}
float GCTriggerPhysics::GetLinearForce() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_linearForce");
}
void GCTriggerPhysics::SetLinearForce(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_linearForce", false, value);
}
float GCTriggerPhysics::GetFrequency() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_flFrequency");
}
void GCTriggerPhysics::SetFrequency(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_flFrequency", false, value);
}
float GCTriggerPhysics::GetDampingRatio() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerPhysics", "m_flDampingRatio");
}
void GCTriggerPhysics::SetDampingRatio(float value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_flDampingRatio", false, value);
}
Vector GCTriggerPhysics::GetLinearForcePointAt() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAt");
}
void GCTriggerPhysics::SetLinearForcePointAt(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAt", false, value);
}
bool GCTriggerPhysics::GetCollapseToForcePoint() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerPhysics", "m_bCollapseToForcePoint");
}
void GCTriggerPhysics::SetCollapseToForcePoint(bool value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_bCollapseToForcePoint", false, value);
}
Vector GCTriggerPhysics::GetLinearForcePointAtWorld() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAtWorld");
}
void GCTriggerPhysics::SetLinearForcePointAtWorld(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_vecLinearForcePointAtWorld", false, value);
}
Vector GCTriggerPhysics::GetLinearForceDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerPhysics", "m_vecLinearForceDirection");
}
void GCTriggerPhysics::SetLinearForceDirection(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_vecLinearForceDirection", false, value);
}
bool GCTriggerPhysics::GetConvertToDebrisWhenPossible() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerPhysics", "m_bConvertToDebrisWhenPossible");
}
void GCTriggerPhysics::SetConvertToDebrisWhenPossible(bool value) {
    SetSchemaValue(m_ptr, "CTriggerPhysics", "m_bConvertToDebrisWhenPossible", false, value);
}
std::string GCTriggerPhysics::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerPhysics::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerPhysics::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerPhysics::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerPhysics>("CTriggerPhysics")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GravityScale", &GCTriggerPhysics::GetGravityScale, &GCTriggerPhysics::SetGravityScale)
        .addProperty("LinearLimit", &GCTriggerPhysics::GetLinearLimit, &GCTriggerPhysics::SetLinearLimit)
        .addProperty("LinearDamping", &GCTriggerPhysics::GetLinearDamping, &GCTriggerPhysics::SetLinearDamping)
        .addProperty("AngularLimit", &GCTriggerPhysics::GetAngularLimit, &GCTriggerPhysics::SetAngularLimit)
        .addProperty("AngularDamping", &GCTriggerPhysics::GetAngularDamping, &GCTriggerPhysics::SetAngularDamping)
        .addProperty("LinearForce", &GCTriggerPhysics::GetLinearForce, &GCTriggerPhysics::SetLinearForce)
        .addProperty("Frequency", &GCTriggerPhysics::GetFrequency, &GCTriggerPhysics::SetFrequency)
        .addProperty("DampingRatio", &GCTriggerPhysics::GetDampingRatio, &GCTriggerPhysics::SetDampingRatio)
        .addProperty("LinearForcePointAt", &GCTriggerPhysics::GetLinearForcePointAt, &GCTriggerPhysics::SetLinearForcePointAt)
        .addProperty("CollapseToForcePoint", &GCTriggerPhysics::GetCollapseToForcePoint, &GCTriggerPhysics::SetCollapseToForcePoint)
        .addProperty("LinearForcePointAtWorld", &GCTriggerPhysics::GetLinearForcePointAtWorld, &GCTriggerPhysics::SetLinearForcePointAtWorld)
        .addProperty("LinearForceDirection", &GCTriggerPhysics::GetLinearForceDirection, &GCTriggerPhysics::SetLinearForceDirection)
        .addProperty("ConvertToDebrisWhenPossible", &GCTriggerPhysics::GetConvertToDebrisWhenPossible, &GCTriggerPhysics::SetConvertToDebrisWhenPossible)
        .addProperty("Parent", &GCTriggerPhysics::GetParent, &GCTriggerPhysics::SetParent)
        .addFunction("ToPtr", &GCTriggerPhysics::ToPtr)
        .addFunction("IsValid", &GCTriggerPhysics::IsValid)
        .endClass();
}