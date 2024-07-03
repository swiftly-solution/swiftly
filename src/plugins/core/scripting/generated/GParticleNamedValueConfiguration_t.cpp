#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleNamedValueConfiguration_t::GParticleNamedValueConfiguration_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleNamedValueConfiguration_t::GParticleNamedValueConfiguration_t(void *ptr) {
    m_ptr = ptr;
}
std::string GParticleNamedValueConfiguration_t::GetConfigName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_ConfigName").Get();
}
void GParticleNamedValueConfiguration_t::SetConfigName(std::string value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_ConfigName", true, CUtlString(value.c_str()));
}
uint64_t GParticleNamedValueConfiguration_t::GetAttachType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ParticleNamedValueConfiguration_t", "m_iAttachType");
}
void GParticleNamedValueConfiguration_t::SetAttachType(uint64_t value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_iAttachType", true, value);
}
std::string GParticleNamedValueConfiguration_t::GetBoundEntityPath() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_BoundEntityPath").Get();
}
void GParticleNamedValueConfiguration_t::SetBoundEntityPath(std::string value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_BoundEntityPath", true, CUtlString(value.c_str()));
}
std::string GParticleNamedValueConfiguration_t::GetStrEntityScope() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_strEntityScope").Get();
}
void GParticleNamedValueConfiguration_t::SetStrEntityScope(std::string value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_strEntityScope", true, CUtlString(value.c_str()));
}
std::string GParticleNamedValueConfiguration_t::GetStrAttachmentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleNamedValueConfiguration_t", "m_strAttachmentName").Get();
}
void GParticleNamedValueConfiguration_t::SetStrAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "ParticleNamedValueConfiguration_t", "m_strAttachmentName", true, CUtlString(value.c_str()));
}
std::string GParticleNamedValueConfiguration_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleNamedValueConfiguration_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleNamedValueConfiguration_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleNamedValueConfiguration_t>("ParticleNamedValueConfiguration_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ConfigName", &GParticleNamedValueConfiguration_t::GetConfigName, &GParticleNamedValueConfiguration_t::SetConfigName)
        .addProperty("AttachType", &GParticleNamedValueConfiguration_t::GetAttachType, &GParticleNamedValueConfiguration_t::SetAttachType)
        .addProperty("BoundEntityPath", &GParticleNamedValueConfiguration_t::GetBoundEntityPath, &GParticleNamedValueConfiguration_t::SetBoundEntityPath)
        .addProperty("StrEntityScope", &GParticleNamedValueConfiguration_t::GetStrEntityScope, &GParticleNamedValueConfiguration_t::SetStrEntityScope)
        .addProperty("StrAttachmentName", &GParticleNamedValueConfiguration_t::GetStrAttachmentName, &GParticleNamedValueConfiguration_t::SetStrAttachmentName)
        .addFunction("ToPtr", &GParticleNamedValueConfiguration_t::ToPtr)
        .addFunction("IsValid", &GParticleNamedValueConfiguration_t::IsValid)
        .endClass();
}