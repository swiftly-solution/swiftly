#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSound::GCSound(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSound::GCSound(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCSound::GetOwner() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSound", "m_hOwner"));
    return value;
}
void GCSound::SetOwner(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
GCBaseEntity GCSound::GetTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSound", "m_hTarget"));
    return value;
}
void GCSound::SetTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n");
}
int32_t GCSound::GetVolume() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSound", "m_iVolume");
}
void GCSound::SetVolume(int32_t value) {
    SetSchemaValue(m_ptr, "CSound", "m_iVolume", false, value);
}
float GCSound::GetOcclusionScale() const {
    return GetSchemaValue<float>(m_ptr, "CSound", "m_flOcclusionScale");
}
void GCSound::SetOcclusionScale(float value) {
    SetSchemaValue(m_ptr, "CSound", "m_flOcclusionScale", false, value);
}
int32_t GCSound::GetNextAudible() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSound", "m_iNextAudible");
}
void GCSound::SetNextAudible(int32_t value) {
    SetSchemaValue(m_ptr, "CSound", "m_iNextAudible", false, value);
}
float GCSound::GetExpireTime() const {
    return GetSchemaValue<float>(m_ptr, "CSound", "m_flExpireTime");
}
void GCSound::SetExpireTime(float value) {
    SetSchemaValue(m_ptr, "CSound", "m_flExpireTime", false, value);
}
int16_t GCSound::GetNext() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSound", "m_iNext");
}
void GCSound::SetNext(int16_t value) {
    SetSchemaValue(m_ptr, "CSound", "m_iNext", false, value);
}
bool GCSound::GetNoExpirationTime() const {
    return GetSchemaValue<bool>(m_ptr, "CSound", "m_bNoExpirationTime");
}
void GCSound::SetNoExpirationTime(bool value) {
    SetSchemaValue(m_ptr, "CSound", "m_bNoExpirationTime", false, value);
}
int32_t GCSound::GetOwnerChannelIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSound", "m_ownerChannelIndex");
}
void GCSound::SetOwnerChannelIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CSound", "m_ownerChannelIndex", false, value);
}
Vector GCSound::GetOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CSound", "m_vecOrigin");
}
void GCSound::SetOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CSound", "m_vecOrigin", false, value);
}
bool GCSound::GetHasOwner() const {
    return GetSchemaValue<bool>(m_ptr, "CSound", "m_bHasOwner");
}
void GCSound::SetHasOwner(bool value) {
    SetSchemaValue(m_ptr, "CSound", "m_bHasOwner", false, value);
}
std::string GCSound::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSound::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSound(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSound>("CSound")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Owner", &GCSound::GetOwner, &GCSound::SetOwner)
        .addProperty("Target", &GCSound::GetTarget, &GCSound::SetTarget)
        .addProperty("Volume", &GCSound::GetVolume, &GCSound::SetVolume)
        .addProperty("OcclusionScale", &GCSound::GetOcclusionScale, &GCSound::SetOcclusionScale)
        .addProperty("NextAudible", &GCSound::GetNextAudible, &GCSound::SetNextAudible)
        .addProperty("ExpireTime", &GCSound::GetExpireTime, &GCSound::SetExpireTime)
        .addProperty("Next", &GCSound::GetNext, &GCSound::SetNext)
        .addProperty("NoExpirationTime", &GCSound::GetNoExpirationTime, &GCSound::SetNoExpirationTime)
        .addProperty("OwnerChannelIndex", &GCSound::GetOwnerChannelIndex, &GCSound::SetOwnerChannelIndex)
        .addProperty("Origin", &GCSound::GetOrigin, &GCSound::SetOrigin)
        .addProperty("HasOwner", &GCSound::GetHasOwner, &GCSound::SetHasOwner)
        .addFunction("ToPtr", &GCSound::ToPtr)
        .addFunction("IsValid", &GCSound::IsValid)
        .endClass();
}