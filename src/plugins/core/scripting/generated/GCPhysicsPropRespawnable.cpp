#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsPropRespawnable::GCPhysicsPropRespawnable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsPropRespawnable::GCPhysicsPropRespawnable(void *ptr) {
    m_ptr = ptr;
}
Vector GCPhysicsPropRespawnable::GetOriginalSpawnOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnOrigin");
}
void GCPhysicsPropRespawnable::SetOriginalSpawnOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnOrigin", false, value);
}
QAngle GCPhysicsPropRespawnable::GetOriginalSpawnAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnAngles");
}
void GCPhysicsPropRespawnable::SetOriginalSpawnAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalSpawnAngles", false, value);
}
Vector GCPhysicsPropRespawnable::GetOriginalMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMins");
}
void GCPhysicsPropRespawnable::SetOriginalMins(Vector value) {
    SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMins", false, value);
}
Vector GCPhysicsPropRespawnable::GetOriginalMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMaxs");
}
void GCPhysicsPropRespawnable::SetOriginalMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_vOriginalMaxs", false, value);
}
float GCPhysicsPropRespawnable::GetRespawnDuration() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsPropRespawnable", "m_flRespawnDuration");
}
void GCPhysicsPropRespawnable::SetRespawnDuration(float value) {
    SetSchemaValue(m_ptr, "CPhysicsPropRespawnable", "m_flRespawnDuration", false, value);
}
std::string GCPhysicsPropRespawnable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsPropRespawnable::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysicsProp GCPhysicsPropRespawnable::GetParent() const {
    GCPhysicsProp value(m_ptr);
    return value;
}
void GCPhysicsPropRespawnable::SetParent(GCPhysicsProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsPropRespawnable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsPropRespawnable>("CPhysicsPropRespawnable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OriginalSpawnOrigin", &GCPhysicsPropRespawnable::GetOriginalSpawnOrigin, &GCPhysicsPropRespawnable::SetOriginalSpawnOrigin)
        .addProperty("OriginalSpawnAngles", &GCPhysicsPropRespawnable::GetOriginalSpawnAngles, &GCPhysicsPropRespawnable::SetOriginalSpawnAngles)
        .addProperty("OriginalMins", &GCPhysicsPropRespawnable::GetOriginalMins, &GCPhysicsPropRespawnable::SetOriginalMins)
        .addProperty("OriginalMaxs", &GCPhysicsPropRespawnable::GetOriginalMaxs, &GCPhysicsPropRespawnable::SetOriginalMaxs)
        .addProperty("RespawnDuration", &GCPhysicsPropRespawnable::GetRespawnDuration, &GCPhysicsPropRespawnable::SetRespawnDuration)
        .addProperty("Parent", &GCPhysicsPropRespawnable::GetParent, &GCPhysicsPropRespawnable::SetParent)
        .addFunction("ToPtr", &GCPhysicsPropRespawnable::ToPtr)
        .addFunction("IsValid", &GCPhysicsPropRespawnable::IsValid)
        .endClass();
}