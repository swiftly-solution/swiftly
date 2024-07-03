#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCConstantForceController::GCConstantForceController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCConstantForceController::GCConstantForceController(void *ptr) {
    m_ptr = ptr;
}
Vector GCConstantForceController::GetLinear() const {
    return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_linear");
}
void GCConstantForceController::SetLinear(Vector value) {
    SetSchemaValue(m_ptr, "CConstantForceController", "m_linear", false, value);
}
Vector GCConstantForceController::GetAngular() const {
    return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_angular");
}
void GCConstantForceController::SetAngular(Vector value) {
    SetSchemaValue(m_ptr, "CConstantForceController", "m_angular", false, value);
}
Vector GCConstantForceController::GetLinearSave() const {
    return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_linearSave");
}
void GCConstantForceController::SetLinearSave(Vector value) {
    SetSchemaValue(m_ptr, "CConstantForceController", "m_linearSave", false, value);
}
Vector GCConstantForceController::GetAngularSave() const {
    return GetSchemaValue<Vector>(m_ptr, "CConstantForceController", "m_angularSave");
}
void GCConstantForceController::SetAngularSave(Vector value) {
    SetSchemaValue(m_ptr, "CConstantForceController", "m_angularSave", false, value);
}
std::string GCConstantForceController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCConstantForceController::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCConstantForceController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstantForceController>("CConstantForceController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Linear", &GCConstantForceController::GetLinear, &GCConstantForceController::SetLinear)
        .addProperty("Angular", &GCConstantForceController::GetAngular, &GCConstantForceController::SetAngular)
        .addProperty("LinearSave", &GCConstantForceController::GetLinearSave, &GCConstantForceController::SetLinearSave)
        .addProperty("AngularSave", &GCConstantForceController::GetAngularSave, &GCConstantForceController::SetAngularSave)
        .addFunction("ToPtr", &GCConstantForceController::ToPtr)
        .addFunction("IsValid", &GCConstantForceController::IsValid)
        .endClass();
}