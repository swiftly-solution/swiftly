#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleAnimTag::GCParticleAnimTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleAnimTag::GCParticleAnimTag(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleAnimTag::GetParticleSystemName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_particleSystemName").Get();
}
void GCParticleAnimTag::SetParticleSystemName(std::string value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_particleSystemName", false, CUtlString(value.c_str()));
}
std::string GCParticleAnimTag::GetConfigName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_configName").Get();
}
void GCParticleAnimTag::SetConfigName(std::string value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_configName", false, CUtlString(value.c_str()));
}
bool GCParticleAnimTag::GetDetachFromOwner() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleAnimTag", "m_bDetachFromOwner");
}
void GCParticleAnimTag::SetDetachFromOwner(bool value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_bDetachFromOwner", false, value);
}
bool GCParticleAnimTag::GetStopWhenTagEnds() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleAnimTag", "m_bStopWhenTagEnds");
}
void GCParticleAnimTag::SetStopWhenTagEnds(bool value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_bStopWhenTagEnds", false, value);
}
bool GCParticleAnimTag::GetTagEndStopIsInstant() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleAnimTag", "m_bTagEndStopIsInstant");
}
void GCParticleAnimTag::SetTagEndStopIsInstant(bool value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_bTagEndStopIsInstant", false, value);
}
std::string GCParticleAnimTag::GetAttachmentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_attachmentName").Get();
}
void GCParticleAnimTag::SetAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentName", false, CUtlString(value.c_str()));
}
uint64_t GCParticleAnimTag::GetAttachmentType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleAnimTag", "m_attachmentType");
}
void GCParticleAnimTag::SetAttachmentType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentType", false, value);
}
std::string GCParticleAnimTag::GetAttachmentCP1Name() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CParticleAnimTag", "m_attachmentCP1Name").Get();
}
void GCParticleAnimTag::SetAttachmentCP1Name(std::string value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentCP1Name", false, CUtlString(value.c_str()));
}
uint64_t GCParticleAnimTag::GetAttachmentCP1Type() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleAnimTag", "m_attachmentCP1Type");
}
void GCParticleAnimTag::SetAttachmentCP1Type(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleAnimTag", "m_attachmentCP1Type", false, value);
}
std::string GCParticleAnimTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleAnimTag::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimTagBase GCParticleAnimTag::GetParent() const {
    GCAnimTagBase value(m_ptr);
    return value;
}
void GCParticleAnimTag::SetParent(GCAnimTagBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleAnimTag>("CParticleAnimTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParticleSystemName", &GCParticleAnimTag::GetParticleSystemName, &GCParticleAnimTag::SetParticleSystemName)
        .addProperty("ConfigName", &GCParticleAnimTag::GetConfigName, &GCParticleAnimTag::SetConfigName)
        .addProperty("DetachFromOwner", &GCParticleAnimTag::GetDetachFromOwner, &GCParticleAnimTag::SetDetachFromOwner)
        .addProperty("StopWhenTagEnds", &GCParticleAnimTag::GetStopWhenTagEnds, &GCParticleAnimTag::SetStopWhenTagEnds)
        .addProperty("TagEndStopIsInstant", &GCParticleAnimTag::GetTagEndStopIsInstant, &GCParticleAnimTag::SetTagEndStopIsInstant)
        .addProperty("AttachmentName", &GCParticleAnimTag::GetAttachmentName, &GCParticleAnimTag::SetAttachmentName)
        .addProperty("AttachmentType", &GCParticleAnimTag::GetAttachmentType, &GCParticleAnimTag::SetAttachmentType)
        .addProperty("AttachmentCP1Name", &GCParticleAnimTag::GetAttachmentCP1Name, &GCParticleAnimTag::SetAttachmentCP1Name)
        .addProperty("AttachmentCP1Type", &GCParticleAnimTag::GetAttachmentCP1Type, &GCParticleAnimTag::SetAttachmentCP1Type)
        .addProperty("Parent", &GCParticleAnimTag::GetParent, &GCParticleAnimTag::SetParent)
        .addFunction("ToPtr", &GCParticleAnimTag::ToPtr)
        .addFunction("IsValid", &GCParticleAnimTag::IsValid)
        .endClass();
}