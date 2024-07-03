#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gconstraint_hingeparams_t::Gconstraint_hingeparams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gconstraint_hingeparams_t::Gconstraint_hingeparams_t(void *ptr) {
    m_ptr = ptr;
}
Vector Gconstraint_hingeparams_t::GetWorldPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "constraint_hingeparams_t", "worldPosition");
}
void Gconstraint_hingeparams_t::SetWorldPosition(Vector value) {
    SetSchemaValue(m_ptr, "constraint_hingeparams_t", "worldPosition", true, value);
}
Vector Gconstraint_hingeparams_t::GetWorldAxisDirection() const {
    return GetSchemaValue<Vector>(m_ptr, "constraint_hingeparams_t", "worldAxisDirection");
}
void Gconstraint_hingeparams_t::SetWorldAxisDirection(Vector value) {
    SetSchemaValue(m_ptr, "constraint_hingeparams_t", "worldAxisDirection", true, value);
}
Gconstraint_axislimit_t Gconstraint_hingeparams_t::GetHingeAxis() const {
    Gconstraint_axislimit_t value(GetSchemaPtr(m_ptr, "constraint_hingeparams_t", "hingeAxis"));
    return value;
}
void Gconstraint_hingeparams_t::SetHingeAxis(Gconstraint_axislimit_t value) {
    SetSchemaValue(m_ptr, "constraint_hingeparams_t", "hingeAxis", true, value);
}
Gconstraint_breakableparams_t Gconstraint_hingeparams_t::GetConstraint() const {
    Gconstraint_breakableparams_t value(GetSchemaPtr(m_ptr, "constraint_hingeparams_t", "constraint"));
    return value;
}
void Gconstraint_hingeparams_t::SetConstraint(Gconstraint_breakableparams_t value) {
    SetSchemaValue(m_ptr, "constraint_hingeparams_t", "constraint", true, value);
}
std::string Gconstraint_hingeparams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gconstraint_hingeparams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassconstraint_hingeparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gconstraint_hingeparams_t>("constraint_hingeparams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WorldPosition", &Gconstraint_hingeparams_t::GetWorldPosition, &Gconstraint_hingeparams_t::SetWorldPosition)
        .addProperty("WorldAxisDirection", &Gconstraint_hingeparams_t::GetWorldAxisDirection, &Gconstraint_hingeparams_t::SetWorldAxisDirection)
        .addProperty("HingeAxis", &Gconstraint_hingeparams_t::GetHingeAxis, &Gconstraint_hingeparams_t::SetHingeAxis)
        .addProperty("Constraint", &Gconstraint_hingeparams_t::GetConstraint, &Gconstraint_hingeparams_t::SetConstraint)
        .addFunction("ToPtr", &Gconstraint_hingeparams_t::ToPtr)
        .addFunction("IsValid", &Gconstraint_hingeparams_t::IsValid)
        .endClass();
}