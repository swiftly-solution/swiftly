#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdAnimStrayRadius_t::GFeSimdAnimStrayRadius_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdAnimStrayRadius_t::GFeSimdAnimStrayRadius_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSimdAnimStrayRadius_t::GetMaxDist() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdAnimStrayRadius_t", "flMaxDist");
}
void GFeSimdAnimStrayRadius_t::SetMaxDist(float value) {
    SetSchemaValue(m_ptr, "FeSimdAnimStrayRadius_t", "flMaxDist", true, value);
}
float GFeSimdAnimStrayRadius_t::GetRelaxationFactor() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdAnimStrayRadius_t", "flRelaxationFactor");
}
void GFeSimdAnimStrayRadius_t::SetRelaxationFactor(float value) {
    SetSchemaValue(m_ptr, "FeSimdAnimStrayRadius_t", "flRelaxationFactor", true, value);
}
std::string GFeSimdAnimStrayRadius_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdAnimStrayRadius_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdAnimStrayRadius_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdAnimStrayRadius_t>("FeSimdAnimStrayRadius_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxDist", &GFeSimdAnimStrayRadius_t::GetMaxDist, &GFeSimdAnimStrayRadius_t::SetMaxDist)
        .addProperty("RelaxationFactor", &GFeSimdAnimStrayRadius_t::GetRelaxationFactor, &GFeSimdAnimStrayRadius_t::SetRelaxationFactor)
        .addFunction("ToPtr", &GFeSimdAnimStrayRadius_t::ToPtr)
        .addFunction("IsValid", &GFeSimdAnimStrayRadius_t::IsValid)
        .endClass();
}