#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsEntitySolver::GCPhysicsEntitySolver(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsEntitySolver::GCPhysicsEntitySolver(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCPhysicsEntitySolver::GetMovingEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysicsEntitySolver", "m_hMovingEntity"));
    return value;
}
void GCPhysicsEntitySolver::SetMovingEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'MovingEntity' is not possible.\n");
}
GCBaseEntity GCPhysicsEntitySolver::GetPhysicsBlocker() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysicsEntitySolver", "m_hPhysicsBlocker"));
    return value;
}
void GCPhysicsEntitySolver::SetPhysicsBlocker(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsBlocker' is not possible.\n");
}
float GCPhysicsEntitySolver::GetSeparationDuration() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsEntitySolver", "m_separationDuration");
}
void GCPhysicsEntitySolver::SetSeparationDuration(float value) {
    SetSchemaValue(m_ptr, "CPhysicsEntitySolver", "m_separationDuration", false, value);
}
float GCPhysicsEntitySolver::GetCancelTime() const {
    return GetSchemaValue<float>(m_ptr, "CPhysicsEntitySolver", "m_cancelTime");
}
void GCPhysicsEntitySolver::SetCancelTime(float value) {
    SetSchemaValue(m_ptr, "CPhysicsEntitySolver", "m_cancelTime", false, value);
}
std::string GCPhysicsEntitySolver::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsEntitySolver::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCPhysicsEntitySolver::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCPhysicsEntitySolver::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsEntitySolver(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsEntitySolver>("CPhysicsEntitySolver")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MovingEntity", &GCPhysicsEntitySolver::GetMovingEntity, &GCPhysicsEntitySolver::SetMovingEntity)
        .addProperty("PhysicsBlocker", &GCPhysicsEntitySolver::GetPhysicsBlocker, &GCPhysicsEntitySolver::SetPhysicsBlocker)
        .addProperty("SeparationDuration", &GCPhysicsEntitySolver::GetSeparationDuration, &GCPhysicsEntitySolver::SetSeparationDuration)
        .addProperty("CancelTime", &GCPhysicsEntitySolver::GetCancelTime, &GCPhysicsEntitySolver::SetCancelTime)
        .addProperty("Parent", &GCPhysicsEntitySolver::GetParent, &GCPhysicsEntitySolver::SetParent)
        .addFunction("ToPtr", &GCPhysicsEntitySolver::ToPtr)
        .addFunction("IsValid", &GCPhysicsEntitySolver::IsValid)
        .endClass();
}