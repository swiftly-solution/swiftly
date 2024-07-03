#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunction::GCParticleFunction(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunction::GCParticleFunction(void *ptr) {
    m_ptr = ptr;
}
GCParticleCollectionFloatInput GCParticleFunction::GetOpStrength() const {
    GCParticleCollectionFloatInput value(GetSchemaPtr(m_ptr, "CParticleFunction", "m_flOpStrength"));
    return value;
}
void GCParticleFunction::SetOpStrength(GCParticleCollectionFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpStrength", false, value);
}
uint64_t GCParticleFunction::GetOpEndCapState() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFunction", "m_nOpEndCapState");
}
void GCParticleFunction::SetOpEndCapState(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_nOpEndCapState", false, value);
}
float GCParticleFunction::GetOpStartFadeInTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpStartFadeInTime");
}
void GCParticleFunction::SetOpStartFadeInTime(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpStartFadeInTime", false, value);
}
float GCParticleFunction::GetOpEndFadeInTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpEndFadeInTime");
}
void GCParticleFunction::SetOpEndFadeInTime(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpEndFadeInTime", false, value);
}
float GCParticleFunction::GetOpStartFadeOutTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpStartFadeOutTime");
}
void GCParticleFunction::SetOpStartFadeOutTime(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpStartFadeOutTime", false, value);
}
float GCParticleFunction::GetOpEndFadeOutTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpEndFadeOutTime");
}
void GCParticleFunction::SetOpEndFadeOutTime(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpEndFadeOutTime", false, value);
}
float GCParticleFunction::GetOpFadeOscillatePeriod() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpFadeOscillatePeriod");
}
void GCParticleFunction::SetOpFadeOscillatePeriod(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpFadeOscillatePeriod", false, value);
}
bool GCParticleFunction::GetNormalizeToStopTime() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFunction", "m_bNormalizeToStopTime");
}
void GCParticleFunction::SetNormalizeToStopTime(bool value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_bNormalizeToStopTime", false, value);
}
float GCParticleFunction::GetOpTimeOffsetMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMin");
}
void GCParticleFunction::SetOpTimeOffsetMin(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMin", false, value);
}
float GCParticleFunction::GetOpTimeOffsetMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMax");
}
void GCParticleFunction::SetOpTimeOffsetMax(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeOffsetMax", false, value);
}
int32_t GCParticleFunction::GetOpTimeOffsetSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFunction", "m_nOpTimeOffsetSeed");
}
void GCParticleFunction::SetOpTimeOffsetSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_nOpTimeOffsetSeed", false, value);
}
int32_t GCParticleFunction::GetOpTimeScaleSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFunction", "m_nOpTimeScaleSeed");
}
void GCParticleFunction::SetOpTimeScaleSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_nOpTimeScaleSeed", false, value);
}
float GCParticleFunction::GetOpTimeScaleMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeScaleMin");
}
void GCParticleFunction::SetOpTimeScaleMin(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeScaleMin", false, value);
}
float GCParticleFunction::GetOpTimeScaleMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFunction", "m_flOpTimeScaleMax");
}
void GCParticleFunction::SetOpTimeScaleMax(float value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_flOpTimeScaleMax", false, value);
}
bool GCParticleFunction::GetDisableOperator() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFunction", "m_bDisableOperator");
}
void GCParticleFunction::SetDisableOperator(bool value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_bDisableOperator", false, value);
}
std::string GCParticleFunction::GetNotes() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CParticleFunction", "m_Notes").Get();
}
void GCParticleFunction::SetNotes(std::string value) {
    SetSchemaValue(m_ptr, "CParticleFunction", "m_Notes", false, CUtlString(value.c_str()));
}
std::string GCParticleFunction::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunction::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleFunction(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunction>("CParticleFunction")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpStrength", &GCParticleFunction::GetOpStrength, &GCParticleFunction::SetOpStrength)
        .addProperty("OpEndCapState", &GCParticleFunction::GetOpEndCapState, &GCParticleFunction::SetOpEndCapState)
        .addProperty("OpStartFadeInTime", &GCParticleFunction::GetOpStartFadeInTime, &GCParticleFunction::SetOpStartFadeInTime)
        .addProperty("OpEndFadeInTime", &GCParticleFunction::GetOpEndFadeInTime, &GCParticleFunction::SetOpEndFadeInTime)
        .addProperty("OpStartFadeOutTime", &GCParticleFunction::GetOpStartFadeOutTime, &GCParticleFunction::SetOpStartFadeOutTime)
        .addProperty("OpEndFadeOutTime", &GCParticleFunction::GetOpEndFadeOutTime, &GCParticleFunction::SetOpEndFadeOutTime)
        .addProperty("OpFadeOscillatePeriod", &GCParticleFunction::GetOpFadeOscillatePeriod, &GCParticleFunction::SetOpFadeOscillatePeriod)
        .addProperty("NormalizeToStopTime", &GCParticleFunction::GetNormalizeToStopTime, &GCParticleFunction::SetNormalizeToStopTime)
        .addProperty("OpTimeOffsetMin", &GCParticleFunction::GetOpTimeOffsetMin, &GCParticleFunction::SetOpTimeOffsetMin)
        .addProperty("OpTimeOffsetMax", &GCParticleFunction::GetOpTimeOffsetMax, &GCParticleFunction::SetOpTimeOffsetMax)
        .addProperty("OpTimeOffsetSeed", &GCParticleFunction::GetOpTimeOffsetSeed, &GCParticleFunction::SetOpTimeOffsetSeed)
        .addProperty("OpTimeScaleSeed", &GCParticleFunction::GetOpTimeScaleSeed, &GCParticleFunction::SetOpTimeScaleSeed)
        .addProperty("OpTimeScaleMin", &GCParticleFunction::GetOpTimeScaleMin, &GCParticleFunction::SetOpTimeScaleMin)
        .addProperty("OpTimeScaleMax", &GCParticleFunction::GetOpTimeScaleMax, &GCParticleFunction::SetOpTimeScaleMax)
        .addProperty("DisableOperator", &GCParticleFunction::GetDisableOperator, &GCParticleFunction::SetDisableOperator)
        .addProperty("Notes", &GCParticleFunction::GetNotes, &GCParticleFunction::SetNotes)
        .addFunction("ToPtr", &GCParticleFunction::ToPtr)
        .addFunction("IsValid", &GCParticleFunction::IsValid)
        .endClass();
}