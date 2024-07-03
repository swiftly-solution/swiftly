#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdSpringIntegrator_t::GFeSimdSpringIntegrator_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdSpringIntegrator_t::GFeSimdSpringIntegrator_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSimdSpringIntegrator_t::GetSpringRestLength() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flSpringRestLength");
}
void GFeSimdSpringIntegrator_t::SetSpringRestLength(float value) {
    SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flSpringRestLength", true, value);
}
float GFeSimdSpringIntegrator_t::GetSpringConstant() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flSpringConstant");
}
void GFeSimdSpringIntegrator_t::SetSpringConstant(float value) {
    SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flSpringConstant", true, value);
}
float GFeSimdSpringIntegrator_t::GetSpringDamping() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flSpringDamping");
}
void GFeSimdSpringIntegrator_t::SetSpringDamping(float value) {
    SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flSpringDamping", true, value);
}
float GFeSimdSpringIntegrator_t::GetNodeWeight0() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdSpringIntegrator_t", "flNodeWeight0");
}
void GFeSimdSpringIntegrator_t::SetNodeWeight0(float value) {
    SetSchemaValue(m_ptr, "FeSimdSpringIntegrator_t", "flNodeWeight0", true, value);
}
std::string GFeSimdSpringIntegrator_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdSpringIntegrator_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdSpringIntegrator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdSpringIntegrator_t>("FeSimdSpringIntegrator_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SpringRestLength", &GFeSimdSpringIntegrator_t::GetSpringRestLength, &GFeSimdSpringIntegrator_t::SetSpringRestLength)
        .addProperty("SpringConstant", &GFeSimdSpringIntegrator_t::GetSpringConstant, &GFeSimdSpringIntegrator_t::SetSpringConstant)
        .addProperty("SpringDamping", &GFeSimdSpringIntegrator_t::GetSpringDamping, &GFeSimdSpringIntegrator_t::SetSpringDamping)
        .addProperty("NodeWeight0", &GFeSimdSpringIntegrator_t::GetNodeWeight0, &GFeSimdSpringIntegrator_t::SetNodeWeight0)
        .addFunction("ToPtr", &GFeSimdSpringIntegrator_t::ToPtr)
        .addFunction("IsValid", &GFeSimdSpringIntegrator_t::IsValid)
        .endClass();
}