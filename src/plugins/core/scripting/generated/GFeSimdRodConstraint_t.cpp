#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdRodConstraint_t::GFeSimdRodConstraint_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdRodConstraint_t::GFeSimdRodConstraint_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSimdRodConstraint_t::Get4MaxDist() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4MaxDist");
}
void GFeSimdRodConstraint_t::Set4MaxDist(float value) {
    SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4MaxDist", true, value);
}
float GFeSimdRodConstraint_t::Get4MinDist() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4MinDist");
}
void GFeSimdRodConstraint_t::Set4MinDist(float value) {
    SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4MinDist", true, value);
}
float GFeSimdRodConstraint_t::Get4Weight0() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4Weight0");
}
void GFeSimdRodConstraint_t::Set4Weight0(float value) {
    SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4Weight0", true, value);
}
float GFeSimdRodConstraint_t::Get4RelaxationFactor() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraint_t", "f4RelaxationFactor");
}
void GFeSimdRodConstraint_t::Set4RelaxationFactor(float value) {
    SetSchemaValue(m_ptr, "FeSimdRodConstraint_t", "f4RelaxationFactor", true, value);
}
std::string GFeSimdRodConstraint_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdRodConstraint_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdRodConstraint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdRodConstraint_t>("FeSimdRodConstraint_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("4MaxDist", &GFeSimdRodConstraint_t::Get4MaxDist, &GFeSimdRodConstraint_t::Set4MaxDist)
        .addProperty("4MinDist", &GFeSimdRodConstraint_t::Get4MinDist, &GFeSimdRodConstraint_t::Set4MinDist)
        .addProperty("4Weight0", &GFeSimdRodConstraint_t::Get4Weight0, &GFeSimdRodConstraint_t::Set4Weight0)
        .addProperty("4RelaxationFactor", &GFeSimdRodConstraint_t::Get4RelaxationFactor, &GFeSimdRodConstraint_t::Set4RelaxationFactor)
        .addFunction("ToPtr", &GFeSimdRodConstraint_t::ToPtr)
        .addFunction("IsValid", &GFeSimdRodConstraint_t::IsValid)
        .endClass();
}