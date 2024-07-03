#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gconstraint_axislimit_t::Gconstraint_axislimit_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gconstraint_axislimit_t::Gconstraint_axislimit_t(void *ptr) {
    m_ptr = ptr;
}
float Gconstraint_axislimit_t::GetMinRotation() const {
    return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMinRotation");
}
void Gconstraint_axislimit_t::SetMinRotation(float value) {
    SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMinRotation", true, value);
}
float Gconstraint_axislimit_t::GetMaxRotation() const {
    return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMaxRotation");
}
void Gconstraint_axislimit_t::SetMaxRotation(float value) {
    SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMaxRotation", true, value);
}
float Gconstraint_axislimit_t::GetMotorTargetAngSpeed() const {
    return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMotorTargetAngSpeed");
}
void Gconstraint_axislimit_t::SetMotorTargetAngSpeed(float value) {
    SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMotorTargetAngSpeed", true, value);
}
float Gconstraint_axislimit_t::GetMotorMaxTorque() const {
    return GetSchemaValue<float>(m_ptr, "constraint_axislimit_t", "flMotorMaxTorque");
}
void Gconstraint_axislimit_t::SetMotorMaxTorque(float value) {
    SetSchemaValue(m_ptr, "constraint_axislimit_t", "flMotorMaxTorque", true, value);
}
std::string Gconstraint_axislimit_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gconstraint_axislimit_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassconstraint_axislimit_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gconstraint_axislimit_t>("constraint_axislimit_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinRotation", &Gconstraint_axislimit_t::GetMinRotation, &Gconstraint_axislimit_t::SetMinRotation)
        .addProperty("MaxRotation", &Gconstraint_axislimit_t::GetMaxRotation, &Gconstraint_axislimit_t::SetMaxRotation)
        .addProperty("MotorTargetAngSpeed", &Gconstraint_axislimit_t::GetMotorTargetAngSpeed, &Gconstraint_axislimit_t::SetMotorTargetAngSpeed)
        .addProperty("MotorMaxTorque", &Gconstraint_axislimit_t::GetMotorMaxTorque, &Gconstraint_axislimit_t::SetMotorMaxTorque)
        .addFunction("ToPtr", &Gconstraint_axislimit_t::ToPtr)
        .addFunction("IsValid", &Gconstraint_axislimit_t::IsValid)
        .endClass();
}