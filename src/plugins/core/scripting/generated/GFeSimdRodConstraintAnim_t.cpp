#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdRodConstraintAnim_t::GFeSimdRodConstraintAnim_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdRodConstraintAnim_t::GFeSimdRodConstraintAnim_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSimdRodConstraintAnim_t::Get4Weight0() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraintAnim_t", "f4Weight0");
}
void GFeSimdRodConstraintAnim_t::Set4Weight0(float value) {
    SetSchemaValue(m_ptr, "FeSimdRodConstraintAnim_t", "f4Weight0", true, value);
}
float GFeSimdRodConstraintAnim_t::Get4RelaxationFactor() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdRodConstraintAnim_t", "f4RelaxationFactor");
}
void GFeSimdRodConstraintAnim_t::Set4RelaxationFactor(float value) {
    SetSchemaValue(m_ptr, "FeSimdRodConstraintAnim_t", "f4RelaxationFactor", true, value);
}
std::string GFeSimdRodConstraintAnim_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdRodConstraintAnim_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdRodConstraintAnim_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdRodConstraintAnim_t>("FeSimdRodConstraintAnim_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("4Weight0", &GFeSimdRodConstraintAnim_t::Get4Weight0, &GFeSimdRodConstraintAnim_t::Set4Weight0)
        .addProperty("4RelaxationFactor", &GFeSimdRodConstraintAnim_t::Get4RelaxationFactor, &GFeSimdRodConstraintAnim_t::Set4RelaxationFactor)
        .addFunction("ToPtr", &GFeSimdRodConstraintAnim_t::ToPtr)
        .addFunction("IsValid", &GFeSimdRodConstraintAnim_t::IsValid)
        .endClass();
}