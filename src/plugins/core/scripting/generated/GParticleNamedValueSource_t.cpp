#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleNamedValueSource_t::GParticleNamedValueSource_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleNamedValueSource_t::GParticleNamedValueSource_t(void *ptr) {
    m_ptr = ptr;
}
std::string GParticleNamedValueSource_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueSource_t", "m_Name").Get();
}
void GParticleNamedValueSource_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_Name", true, CUtlString(value.c_str()));
}
bool GParticleNamedValueSource_t::GetIsPublic() const {
    return GetSchemaValue<bool>(m_ptr, "ParticleNamedValueSource_t", "m_IsPublic");
}
void GParticleNamedValueSource_t::SetIsPublic(bool value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_IsPublic", true, value);
}
uint64_t GParticleNamedValueSource_t::GetValueType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ParticleNamedValueSource_t", "m_ValueType");
}
void GParticleNamedValueSource_t::SetValueType(uint64_t value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_ValueType", true, value);
}
GParticleNamedValueConfiguration_t GParticleNamedValueSource_t::GetDefaultConfig() const {
    GParticleNamedValueConfiguration_t value(GetSchemaPtr(m_ptr, "ParticleNamedValueSource_t", "m_DefaultConfig"));
    return value;
}
void GParticleNamedValueSource_t::SetDefaultConfig(GParticleNamedValueConfiguration_t value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueSource_t", "m_DefaultConfig", true, value);
}
std::vector<GParticleNamedValueConfiguration_t> GParticleNamedValueSource_t::GetNamedConfigs() const {
    CUtlVector<GParticleNamedValueConfiguration_t>* vec = GetSchemaValue<CUtlVector<GParticleNamedValueConfiguration_t>*>(m_ptr, "ParticleNamedValueSource_t", "m_NamedConfigs"); std::vector<GParticleNamedValueConfiguration_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GParticleNamedValueSource_t::SetNamedConfigs(std::vector<GParticleNamedValueConfiguration_t> value) {
    SetSchemaValueCUtlVector<GParticleNamedValueConfiguration_t>(m_ptr, "ParticleNamedValueSource_t", "m_NamedConfigs", true, value);
}
std::string GParticleNamedValueSource_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleNamedValueSource_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleNamedValueSource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleNamedValueSource_t>("ParticleNamedValueSource_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GParticleNamedValueSource_t::GetName, &GParticleNamedValueSource_t::SetName)
        .addProperty("IsPublic", &GParticleNamedValueSource_t::GetIsPublic, &GParticleNamedValueSource_t::SetIsPublic)
        .addProperty("ValueType", &GParticleNamedValueSource_t::GetValueType, &GParticleNamedValueSource_t::SetValueType)
        .addProperty("DefaultConfig", &GParticleNamedValueSource_t::GetDefaultConfig, &GParticleNamedValueSource_t::SetDefaultConfig)
        .addProperty("NamedConfigs", &GParticleNamedValueSource_t::GetNamedConfigs, &GParticleNamedValueSource_t::SetNamedConfigs)
        .addFunction("ToPtr", &GParticleNamedValueSource_t::ToPtr)
        .addFunction("IsValid", &GParticleNamedValueSource_t::IsValid)
        .endClass();
}