#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeNodeIntegrator_t::GFeNodeIntegrator_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeNodeIntegrator_t::GFeNodeIntegrator_t(void *ptr) {
    m_ptr = ptr;
}
float GFeNodeIntegrator_t::GetPointDamping() const {
    return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flPointDamping");
}
void GFeNodeIntegrator_t::SetPointDamping(float value) {
    SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flPointDamping", true, value);
}
float GFeNodeIntegrator_t::GetAnimationForceAttraction() const {
    return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flAnimationForceAttraction");
}
void GFeNodeIntegrator_t::SetAnimationForceAttraction(float value) {
    SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flAnimationForceAttraction", true, value);
}
float GFeNodeIntegrator_t::GetAnimationVertexAttraction() const {
    return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flAnimationVertexAttraction");
}
void GFeNodeIntegrator_t::SetAnimationVertexAttraction(float value) {
    SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flAnimationVertexAttraction", true, value);
}
float GFeNodeIntegrator_t::GetGravity() const {
    return GetSchemaValue<float>(m_ptr, "FeNodeIntegrator_t", "flGravity");
}
void GFeNodeIntegrator_t::SetGravity(float value) {
    SetSchemaValue(m_ptr, "FeNodeIntegrator_t", "flGravity", true, value);
}
std::string GFeNodeIntegrator_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeNodeIntegrator_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeNodeIntegrator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeIntegrator_t>("FeNodeIntegrator_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PointDamping", &GFeNodeIntegrator_t::GetPointDamping, &GFeNodeIntegrator_t::SetPointDamping)
        .addProperty("AnimationForceAttraction", &GFeNodeIntegrator_t::GetAnimationForceAttraction, &GFeNodeIntegrator_t::SetAnimationForceAttraction)
        .addProperty("AnimationVertexAttraction", &GFeNodeIntegrator_t::GetAnimationVertexAttraction, &GFeNodeIntegrator_t::SetAnimationVertexAttraction)
        .addProperty("Gravity", &GFeNodeIntegrator_t::GetGravity, &GFeNodeIntegrator_t::SetGravity)
        .addFunction("ToPtr", &GFeNodeIntegrator_t::ToPtr)
        .addFunction("IsValid", &GFeNodeIntegrator_t::IsValid)
        .endClass();
}