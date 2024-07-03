#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotorController::GCMotorController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotorController::GCMotorController(void *ptr) {
    m_ptr = ptr;
}
float GCMotorController::GetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CMotorController", "m_speed");
}
void GCMotorController::SetSpeed(float value) {
    SetSchemaValue(m_ptr, "CMotorController", "m_speed", false, value);
}
float GCMotorController::GetMaxTorque() const {
    return GetSchemaValue<float>(m_ptr, "CMotorController", "m_maxTorque");
}
void GCMotorController::SetMaxTorque(float value) {
    SetSchemaValue(m_ptr, "CMotorController", "m_maxTorque", false, value);
}
Vector GCMotorController::GetAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CMotorController", "m_axis");
}
void GCMotorController::SetAxis(Vector value) {
    SetSchemaValue(m_ptr, "CMotorController", "m_axis", false, value);
}
float GCMotorController::GetInertiaFactor() const {
    return GetSchemaValue<float>(m_ptr, "CMotorController", "m_inertiaFactor");
}
void GCMotorController::SetInertiaFactor(float value) {
    SetSchemaValue(m_ptr, "CMotorController", "m_inertiaFactor", false, value);
}
std::string GCMotorController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotorController::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotorController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotorController>("CMotorController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Speed", &GCMotorController::GetSpeed, &GCMotorController::SetSpeed)
        .addProperty("MaxTorque", &GCMotorController::GetMaxTorque, &GCMotorController::SetMaxTorque)
        .addProperty("Axis", &GCMotorController::GetAxis, &GCMotorController::SetAxis)
        .addProperty("InertiaFactor", &GCMotorController::GetInertiaFactor, &GCMotorController::SetInertiaFactor)
        .addFunction("ToPtr", &GCMotorController::ToPtr)
        .addFunction("IsValid", &GCMotorController::IsValid)
        .endClass();
}