#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysMotor::GCPhysMotor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysMotor::GCPhysMotor(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysMotor::GetNameAttach() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysMotor", "m_nameAttach").String();
}
void GCPhysMotor::SetNameAttach(std::string value) {
    SetSchemaValue(m_ptr, "CPhysMotor", "m_nameAttach", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCPhysMotor::GetAttachedObject() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysMotor", "m_hAttachedObject"));
    return value;
}
void GCPhysMotor::SetAttachedObject(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedObject' is not possible.\n");
}
float GCPhysMotor::GetSpinUp() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_spinUp");
}
void GCPhysMotor::SetSpinUp(float value) {
    SetSchemaValue(m_ptr, "CPhysMotor", "m_spinUp", false, value);
}
float GCPhysMotor::GetAdditionalAcceleration() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_additionalAcceleration");
}
void GCPhysMotor::SetAdditionalAcceleration(float value) {
    SetSchemaValue(m_ptr, "CPhysMotor", "m_additionalAcceleration", false, value);
}
float GCPhysMotor::GetAngularAcceleration() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_angularAcceleration");
}
void GCPhysMotor::SetAngularAcceleration(float value) {
    SetSchemaValue(m_ptr, "CPhysMotor", "m_angularAcceleration", false, value);
}
float GCPhysMotor::GetLastTime() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMotor", "m_lastTime");
}
void GCPhysMotor::SetLastTime(float value) {
    SetSchemaValue(m_ptr, "CPhysMotor", "m_lastTime", false, value);
}
GCMotorController GCPhysMotor::GetMotor() const {
    GCMotorController value(GetSchemaPtr(m_ptr, "CPhysMotor", "m_motor"));
    return value;
}
void GCPhysMotor::SetMotor(GCMotorController value) {
    SetSchemaValue(m_ptr, "CPhysMotor", "m_motor", false, value);
}
std::string GCPhysMotor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysMotor::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCPhysMotor::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCPhysMotor::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysMotor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysMotor>("CPhysMotor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NameAttach", &GCPhysMotor::GetNameAttach, &GCPhysMotor::SetNameAttach)
        .addProperty("AttachedObject", &GCPhysMotor::GetAttachedObject, &GCPhysMotor::SetAttachedObject)
        .addProperty("SpinUp", &GCPhysMotor::GetSpinUp, &GCPhysMotor::SetSpinUp)
        .addProperty("AdditionalAcceleration", &GCPhysMotor::GetAdditionalAcceleration, &GCPhysMotor::SetAdditionalAcceleration)
        .addProperty("AngularAcceleration", &GCPhysMotor::GetAngularAcceleration, &GCPhysMotor::SetAngularAcceleration)
        .addProperty("LastTime", &GCPhysMotor::GetLastTime, &GCPhysMotor::SetLastTime)
        .addProperty("Motor", &GCPhysMotor::GetMotor, &GCPhysMotor::SetMotor)
        .addProperty("Parent", &GCPhysMotor::GetParent, &GCPhysMotor::SetParent)
        .addFunction("ToPtr", &GCPhysMotor::ToPtr)
        .addFunction("IsValid", &GCPhysMotor::IsValid)
        .endClass();
}