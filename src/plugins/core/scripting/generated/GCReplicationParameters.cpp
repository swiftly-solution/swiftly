#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCReplicationParameters::GCReplicationParameters(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCReplicationParameters::GCReplicationParameters(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCReplicationParameters::GetReplicationMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CReplicationParameters", "m_nReplicationMode");
}
void GCReplicationParameters::SetReplicationMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CReplicationParameters", "m_nReplicationMode", false, value);
}
bool GCReplicationParameters::GetScaleChildParticleRadii() const {
    return GetSchemaValue<bool>(m_ptr, "CReplicationParameters", "m_bScaleChildParticleRadii");
}
void GCReplicationParameters::SetScaleChildParticleRadii(bool value) {
    SetSchemaValue(m_ptr, "CReplicationParameters", "m_bScaleChildParticleRadii", false, value);
}
GCParticleCollectionFloatInput GCReplicationParameters::GetMinRandomRadiusScale() const {
    GCParticleCollectionFloatInput value(GetSchemaPtr(m_ptr, "CReplicationParameters", "m_flMinRandomRadiusScale"));
    return value;
}
void GCReplicationParameters::SetMinRandomRadiusScale(GCParticleCollectionFloatInput value) {
    SetSchemaValue(m_ptr, "CReplicationParameters", "m_flMinRandomRadiusScale", false, value);
}
GCParticleCollectionFloatInput GCReplicationParameters::GetMaxRandomRadiusScale() const {
    GCParticleCollectionFloatInput value(GetSchemaPtr(m_ptr, "CReplicationParameters", "m_flMaxRandomRadiusScale"));
    return value;
}
void GCReplicationParameters::SetMaxRandomRadiusScale(GCParticleCollectionFloatInput value) {
    SetSchemaValue(m_ptr, "CReplicationParameters", "m_flMaxRandomRadiusScale", false, value);
}
GCParticleCollectionFloatInput GCReplicationParameters::GetModellingScale() const {
    GCParticleCollectionFloatInput value(GetSchemaPtr(m_ptr, "CReplicationParameters", "m_flModellingScale"));
    return value;
}
void GCReplicationParameters::SetModellingScale(GCParticleCollectionFloatInput value) {
    SetSchemaValue(m_ptr, "CReplicationParameters", "m_flModellingScale", false, value);
}
std::string GCReplicationParameters::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCReplicationParameters::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCReplicationParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCReplicationParameters>("CReplicationParameters")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ReplicationMode", &GCReplicationParameters::GetReplicationMode, &GCReplicationParameters::SetReplicationMode)
        .addProperty("ScaleChildParticleRadii", &GCReplicationParameters::GetScaleChildParticleRadii, &GCReplicationParameters::SetScaleChildParticleRadii)
        .addProperty("MinRandomRadiusScale", &GCReplicationParameters::GetMinRandomRadiusScale, &GCReplicationParameters::SetMinRandomRadiusScale)
        .addProperty("MaxRandomRadiusScale", &GCReplicationParameters::GetMaxRandomRadiusScale, &GCReplicationParameters::SetMaxRandomRadiusScale)
        .addProperty("ModellingScale", &GCReplicationParameters::GetModellingScale, &GCReplicationParameters::SetModellingScale)
        .addFunction("ToPtr", &GCReplicationParameters::ToPtr)
        .addFunction("IsValid", &GCReplicationParameters::IsValid)
        .endClass();
}