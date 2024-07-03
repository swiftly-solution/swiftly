#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysForce::GCPhysForce(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysForce::GCPhysForce(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysForce::GetNameAttach() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysForce", "m_nameAttach").String();
}
void GCPhysForce::SetNameAttach(std::string value) {
    SetSchemaValue(m_ptr, "CPhysForce", "m_nameAttach", false, CUtlSymbolLarge(value.c_str()));
}
float GCPhysForce::GetForce() const {
    return GetSchemaValue<float>(m_ptr, "CPhysForce", "m_force");
}
void GCPhysForce::SetForce(float value) {
    SetSchemaValue(m_ptr, "CPhysForce", "m_force", false, value);
}
float GCPhysForce::GetForceTime() const {
    return GetSchemaValue<float>(m_ptr, "CPhysForce", "m_forceTime");
}
void GCPhysForce::SetForceTime(float value) {
    SetSchemaValue(m_ptr, "CPhysForce", "m_forceTime", false, value);
}
GCBaseEntity GCPhysForce::GetAttachedObject() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysForce", "m_attachedObject"));
    return value;
}
void GCPhysForce::SetAttachedObject(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedObject' is not possible.\n");
}
bool GCPhysForce::GetWasRestored() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysForce", "m_wasRestored");
}
void GCPhysForce::SetWasRestored(bool value) {
    SetSchemaValue(m_ptr, "CPhysForce", "m_wasRestored", false, value);
}
GCConstantForceController GCPhysForce::GetIntegrator() const {
    GCConstantForceController value(GetSchemaPtr(m_ptr, "CPhysForce", "m_integrator"));
    return value;
}
void GCPhysForce::SetIntegrator(GCConstantForceController value) {
    SetSchemaValue(m_ptr, "CPhysForce", "m_integrator", false, value);
}
std::string GCPhysForce::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysForce::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPhysForce::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPhysForce::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysForce>("CPhysForce")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NameAttach", &GCPhysForce::GetNameAttach, &GCPhysForce::SetNameAttach)
        .addProperty("Force", &GCPhysForce::GetForce, &GCPhysForce::SetForce)
        .addProperty("ForceTime", &GCPhysForce::GetForceTime, &GCPhysForce::SetForceTime)
        .addProperty("AttachedObject", &GCPhysForce::GetAttachedObject, &GCPhysForce::SetAttachedObject)
        .addProperty("WasRestored", &GCPhysForce::GetWasRestored, &GCPhysForce::SetWasRestored)
        .addProperty("Integrator", &GCPhysForce::GetIntegrator, &GCPhysForce::SetIntegrator)
        .addProperty("Parent", &GCPhysForce::GetParent, &GCPhysForce::SetParent)
        .addFunction("ToPtr", &GCPhysForce::ToPtr)
        .addFunction("IsValid", &GCPhysForce::IsValid)
        .endClass();
}