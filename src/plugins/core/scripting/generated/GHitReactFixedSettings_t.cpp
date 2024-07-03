#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GHitReactFixedSettings_t::GHitReactFixedSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GHitReactFixedSettings_t::GHitReactFixedSettings_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GHitReactFixedSettings_t::GetWeightListIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "HitReactFixedSettings_t", "m_nWeightListIndex");
}
void GHitReactFixedSettings_t::SetWeightListIndex(int32_t value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_nWeightListIndex", true, value);
}
int32_t GHitReactFixedSettings_t::GetEffectedBoneCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "HitReactFixedSettings_t", "m_nEffectedBoneCount");
}
void GHitReactFixedSettings_t::SetEffectedBoneCount(int32_t value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_nEffectedBoneCount", true, value);
}
float GHitReactFixedSettings_t::GetMaxImpactForce() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flMaxImpactForce");
}
void GHitReactFixedSettings_t::SetMaxImpactForce(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flMaxImpactForce", true, value);
}
float GHitReactFixedSettings_t::GetMinImpactForce() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flMinImpactForce");
}
void GHitReactFixedSettings_t::SetMinImpactForce(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flMinImpactForce", true, value);
}
float GHitReactFixedSettings_t::GetWhipImpactScale() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flWhipImpactScale");
}
void GHitReactFixedSettings_t::SetWhipImpactScale(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flWhipImpactScale", true, value);
}
float GHitReactFixedSettings_t::GetCounterRotationScale() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flCounterRotationScale");
}
void GHitReactFixedSettings_t::SetCounterRotationScale(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flCounterRotationScale", true, value);
}
float GHitReactFixedSettings_t::GetDistanceFadeScale() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flDistanceFadeScale");
}
void GHitReactFixedSettings_t::SetDistanceFadeScale(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flDistanceFadeScale", true, value);
}
float GHitReactFixedSettings_t::GetPropagationScale() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flPropagationScale");
}
void GHitReactFixedSettings_t::SetPropagationScale(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flPropagationScale", true, value);
}
float GHitReactFixedSettings_t::GetWhipDelay() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flWhipDelay");
}
void GHitReactFixedSettings_t::SetWhipDelay(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flWhipDelay", true, value);
}
float GHitReactFixedSettings_t::GetSpringStrength() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flSpringStrength");
}
void GHitReactFixedSettings_t::SetSpringStrength(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flSpringStrength", true, value);
}
float GHitReactFixedSettings_t::GetWhipSpringStrength() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flWhipSpringStrength");
}
void GHitReactFixedSettings_t::SetWhipSpringStrength(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flWhipSpringStrength", true, value);
}
float GHitReactFixedSettings_t::GetMaxAngleRadians() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flMaxAngleRadians");
}
void GHitReactFixedSettings_t::SetMaxAngleRadians(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flMaxAngleRadians", true, value);
}
int32_t GHitReactFixedSettings_t::GetHipBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "HitReactFixedSettings_t", "m_nHipBoneIndex");
}
void GHitReactFixedSettings_t::SetHipBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_nHipBoneIndex", true, value);
}
float GHitReactFixedSettings_t::GetHipBoneTranslationScale() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipBoneTranslationScale");
}
void GHitReactFixedSettings_t::SetHipBoneTranslationScale(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipBoneTranslationScale", true, value);
}
float GHitReactFixedSettings_t::GetHipDipSpringStrength() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipDipSpringStrength");
}
void GHitReactFixedSettings_t::SetHipDipSpringStrength(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipDipSpringStrength", true, value);
}
float GHitReactFixedSettings_t::GetHipDipImpactScale() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipDipImpactScale");
}
void GHitReactFixedSettings_t::SetHipDipImpactScale(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipDipImpactScale", true, value);
}
float GHitReactFixedSettings_t::GetHipDipDelay() const {
    return GetSchemaValue<float>(m_ptr, "HitReactFixedSettings_t", "m_flHipDipDelay");
}
void GHitReactFixedSettings_t::SetHipDipDelay(float value) {
    SetSchemaValue(m_ptr, "HitReactFixedSettings_t", "m_flHipDipDelay", true, value);
}
std::string GHitReactFixedSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GHitReactFixedSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassHitReactFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GHitReactFixedSettings_t>("HitReactFixedSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeightListIndex", &GHitReactFixedSettings_t::GetWeightListIndex, &GHitReactFixedSettings_t::SetWeightListIndex)
        .addProperty("EffectedBoneCount", &GHitReactFixedSettings_t::GetEffectedBoneCount, &GHitReactFixedSettings_t::SetEffectedBoneCount)
        .addProperty("MaxImpactForce", &GHitReactFixedSettings_t::GetMaxImpactForce, &GHitReactFixedSettings_t::SetMaxImpactForce)
        .addProperty("MinImpactForce", &GHitReactFixedSettings_t::GetMinImpactForce, &GHitReactFixedSettings_t::SetMinImpactForce)
        .addProperty("WhipImpactScale", &GHitReactFixedSettings_t::GetWhipImpactScale, &GHitReactFixedSettings_t::SetWhipImpactScale)
        .addProperty("CounterRotationScale", &GHitReactFixedSettings_t::GetCounterRotationScale, &GHitReactFixedSettings_t::SetCounterRotationScale)
        .addProperty("DistanceFadeScale", &GHitReactFixedSettings_t::GetDistanceFadeScale, &GHitReactFixedSettings_t::SetDistanceFadeScale)
        .addProperty("PropagationScale", &GHitReactFixedSettings_t::GetPropagationScale, &GHitReactFixedSettings_t::SetPropagationScale)
        .addProperty("WhipDelay", &GHitReactFixedSettings_t::GetWhipDelay, &GHitReactFixedSettings_t::SetWhipDelay)
        .addProperty("SpringStrength", &GHitReactFixedSettings_t::GetSpringStrength, &GHitReactFixedSettings_t::SetSpringStrength)
        .addProperty("WhipSpringStrength", &GHitReactFixedSettings_t::GetWhipSpringStrength, &GHitReactFixedSettings_t::SetWhipSpringStrength)
        .addProperty("MaxAngleRadians", &GHitReactFixedSettings_t::GetMaxAngleRadians, &GHitReactFixedSettings_t::SetMaxAngleRadians)
        .addProperty("HipBoneIndex", &GHitReactFixedSettings_t::GetHipBoneIndex, &GHitReactFixedSettings_t::SetHipBoneIndex)
        .addProperty("HipBoneTranslationScale", &GHitReactFixedSettings_t::GetHipBoneTranslationScale, &GHitReactFixedSettings_t::SetHipBoneTranslationScale)
        .addProperty("HipDipSpringStrength", &GHitReactFixedSettings_t::GetHipDipSpringStrength, &GHitReactFixedSettings_t::SetHipDipSpringStrength)
        .addProperty("HipDipImpactScale", &GHitReactFixedSettings_t::GetHipDipImpactScale, &GHitReactFixedSettings_t::SetHipDipImpactScale)
        .addProperty("HipDipDelay", &GHitReactFixedSettings_t::GetHipDipDelay, &GHitReactFixedSettings_t::SetHipDipDelay)
        .addFunction("ToPtr", &GHitReactFixedSettings_t::ToPtr)
        .addFunction("IsValid", &GHitReactFixedSettings_t::IsValid)
        .endClass();
}