#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleMassCalculationParameters::GCParticleMassCalculationParameters(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleMassCalculationParameters::GCParticleMassCalculationParameters(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCParticleMassCalculationParameters::GetMassMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleMassCalculationParameters", "m_nMassMode");
}
void GCParticleMassCalculationParameters::SetMassMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_nMassMode", false, value);
}
GCPerParticleFloatInput GCParticleMassCalculationParameters::GetRadius() const {
    GCPerParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleMassCalculationParameters", "m_flRadius"));
    return value;
}
void GCParticleMassCalculationParameters::SetRadius(GCPerParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_flRadius", false, value);
}
GCPerParticleFloatInput GCParticleMassCalculationParameters::GetNominalRadius() const {
    GCPerParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleMassCalculationParameters", "m_flNominalRadius"));
    return value;
}
void GCParticleMassCalculationParameters::SetNominalRadius(GCPerParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_flNominalRadius", false, value);
}
GCPerParticleFloatInput GCParticleMassCalculationParameters::GetScale() const {
    GCPerParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleMassCalculationParameters", "m_flScale"));
    return value;
}
void GCParticleMassCalculationParameters::SetScale(GCPerParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleMassCalculationParameters", "m_flScale", false, value);
}
std::string GCParticleMassCalculationParameters::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleMassCalculationParameters::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleMassCalculationParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleMassCalculationParameters>("CParticleMassCalculationParameters")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MassMode", &GCParticleMassCalculationParameters::GetMassMode, &GCParticleMassCalculationParameters::SetMassMode)
        .addProperty("Radius", &GCParticleMassCalculationParameters::GetRadius, &GCParticleMassCalculationParameters::SetRadius)
        .addProperty("NominalRadius", &GCParticleMassCalculationParameters::GetNominalRadius, &GCParticleMassCalculationParameters::SetNominalRadius)
        .addProperty("Scale", &GCParticleMassCalculationParameters::GetScale, &GCParticleMassCalculationParameters::SetScale)
        .addFunction("ToPtr", &GCParticleMassCalculationParameters::ToPtr)
        .addFunction("IsValid", &GCParticleMassCalculationParameters::IsValid)
        .endClass();
}