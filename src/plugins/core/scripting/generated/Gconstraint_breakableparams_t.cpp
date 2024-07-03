#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gconstraint_breakableparams_t::Gconstraint_breakableparams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gconstraint_breakableparams_t::Gconstraint_breakableparams_t(void *ptr) {
    m_ptr = ptr;
}
float Gconstraint_breakableparams_t::GetStrength() const {
    return GetSchemaValue<float>(m_ptr, "constraint_breakableparams_t", "strength");
}
void Gconstraint_breakableparams_t::SetStrength(float value) {
    SetSchemaValue(m_ptr, "constraint_breakableparams_t", "strength", true, value);
}
float Gconstraint_breakableparams_t::GetForceLimit() const {
    return GetSchemaValue<float>(m_ptr, "constraint_breakableparams_t", "forceLimit");
}
void Gconstraint_breakableparams_t::SetForceLimit(float value) {
    SetSchemaValue(m_ptr, "constraint_breakableparams_t", "forceLimit", true, value);
}
float Gconstraint_breakableparams_t::GetTorqueLimit() const {
    return GetSchemaValue<float>(m_ptr, "constraint_breakableparams_t", "torqueLimit");
}
void Gconstraint_breakableparams_t::SetTorqueLimit(float value) {
    SetSchemaValue(m_ptr, "constraint_breakableparams_t", "torqueLimit", true, value);
}
std::vector<float> Gconstraint_breakableparams_t::GetBodyMassScale() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "constraint_breakableparams_t", "bodyMassScale"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void Gconstraint_breakableparams_t::SetBodyMassScale(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "constraint_breakableparams_t", "bodyMassScale"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "constraint_breakableparams_t", "bodyMassScale", true, outValue);
}
bool Gconstraint_breakableparams_t::GetIsActive() const {
    return GetSchemaValue<bool>(m_ptr, "constraint_breakableparams_t", "isActive");
}
void Gconstraint_breakableparams_t::SetIsActive(bool value) {
    SetSchemaValue(m_ptr, "constraint_breakableparams_t", "isActive", true, value);
}
std::string Gconstraint_breakableparams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gconstraint_breakableparams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassconstraint_breakableparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gconstraint_breakableparams_t>("constraint_breakableparams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Strength", &Gconstraint_breakableparams_t::GetStrength, &Gconstraint_breakableparams_t::SetStrength)
        .addProperty("ForceLimit", &Gconstraint_breakableparams_t::GetForceLimit, &Gconstraint_breakableparams_t::SetForceLimit)
        .addProperty("TorqueLimit", &Gconstraint_breakableparams_t::GetTorqueLimit, &Gconstraint_breakableparams_t::SetTorqueLimit)
        .addProperty("BodyMassScale", &Gconstraint_breakableparams_t::GetBodyMassScale, &Gconstraint_breakableparams_t::SetBodyMassScale)
        .addProperty("IsActive", &Gconstraint_breakableparams_t::GetIsActive, &Gconstraint_breakableparams_t::SetIsActive)
        .addFunction("ToPtr", &Gconstraint_breakableparams_t::ToPtr)
        .addFunction("IsValid", &Gconstraint_breakableparams_t::IsValid)
        .endClass();
}