#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvWindShared::GCEnvWindShared(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvWindShared::GCEnvWindShared(void *ptr) {
    m_ptr = ptr;
}
float GCEnvWindShared::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flStartTime");
}
void GCEnvWindShared::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flStartTime", false, value);
}
uint32_t GCEnvWindShared::GetWindSeed() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEnvWindShared", "m_iWindSeed");
}
void GCEnvWindShared::SetWindSeed(uint32_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iWindSeed", false, value);
}
uint16_t GCEnvWindShared::GetMinWind() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMinWind");
}
void GCEnvWindShared::SetMinWind(uint16_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMinWind", false, value);
}
uint16_t GCEnvWindShared::GetMaxWind() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMaxWind");
}
void GCEnvWindShared::SetMaxWind(uint16_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMaxWind", false, value);
}
int32_t GCEnvWindShared::GetWindRadius() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvWindShared", "m_windRadius");
}
void GCEnvWindShared::SetWindRadius(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_windRadius", false, value);
}
uint16_t GCEnvWindShared::GetMinGust() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMinGust");
}
void GCEnvWindShared::SetMinGust(uint16_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMinGust", false, value);
}
uint16_t GCEnvWindShared::GetMaxGust() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMaxGust");
}
void GCEnvWindShared::SetMaxGust(uint16_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMaxGust", false, value);
}
float GCEnvWindShared::GetMinGustDelay() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flMinGustDelay");
}
void GCEnvWindShared::SetMinGustDelay(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flMinGustDelay", false, value);
}
float GCEnvWindShared::GetMaxGustDelay() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flMaxGustDelay");
}
void GCEnvWindShared::SetMaxGustDelay(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flMaxGustDelay", false, value);
}
float GCEnvWindShared::GetGustDuration() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flGustDuration");
}
void GCEnvWindShared::SetGustDuration(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flGustDuration", false, value);
}
uint16_t GCEnvWindShared::GetGustDirChange() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iGustDirChange");
}
void GCEnvWindShared::SetGustDirChange(uint16_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iGustDirChange", false, value);
}
Vector GCEnvWindShared::GetLocation() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_location");
}
void GCEnvWindShared::SetLocation(Vector value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_location", false, value);
}
int32_t GCEnvWindShared::GetGustSound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvWindShared", "m_iszGustSound");
}
void GCEnvWindShared::SetGustSound(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iszGustSound", false, value);
}
int32_t GCEnvWindShared::GetWindDir() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvWindShared", "m_iWindDir");
}
void GCEnvWindShared::SetWindDir(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iWindDir", false, value);
}
float GCEnvWindShared::GetWindSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flWindSpeed");
}
void GCEnvWindShared::SetWindSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flWindSpeed", false, value);
}
Vector GCEnvWindShared::GetCurrentWindVector() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_currentWindVector");
}
void GCEnvWindShared::SetCurrentWindVector(Vector value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_currentWindVector", false, value);
}
Vector GCEnvWindShared::GetCurrentSwayVector() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_CurrentSwayVector");
}
void GCEnvWindShared::SetCurrentSwayVector(Vector value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_CurrentSwayVector", false, value);
}
Vector GCEnvWindShared::GetPrevSwayVector() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_PrevSwayVector");
}
void GCEnvWindShared::SetPrevSwayVector(Vector value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_PrevSwayVector", false, value);
}
uint16_t GCEnvWindShared::GetInitialWindDir() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iInitialWindDir");
}
void GCEnvWindShared::SetInitialWindDir(uint16_t value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iInitialWindDir", false, value);
}
float GCEnvWindShared::GetInitialWindSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flInitialWindSpeed");
}
void GCEnvWindShared::SetInitialWindSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flInitialWindSpeed", false, value);
}
GCEntityIOOutput GCEnvWindShared::GetOnGustStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvWindShared", "m_OnGustStart"));
    return value;
}
void GCEnvWindShared::SetOnGustStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_OnGustStart", false, value);
}
GCEntityIOOutput GCEnvWindShared::GetOnGustEnd() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CEnvWindShared", "m_OnGustEnd"));
    return value;
}
void GCEnvWindShared::SetOnGustEnd(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_OnGustEnd", false, value);
}
float GCEnvWindShared::GetVariationTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flVariationTime");
}
void GCEnvWindShared::SetVariationTime(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flVariationTime", false, value);
}
float GCEnvWindShared::GetSwayTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flSwayTime");
}
void GCEnvWindShared::SetSwayTime(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flSwayTime", false, value);
}
float GCEnvWindShared::GetSimTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flSimTime");
}
void GCEnvWindShared::SetSimTime(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flSimTime", false, value);
}
float GCEnvWindShared::GetSwitchTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flSwitchTime");
}
void GCEnvWindShared::SetSwitchTime(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flSwitchTime", false, value);
}
float GCEnvWindShared::GetAveWindSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flAveWindSpeed");
}
void GCEnvWindShared::SetAveWindSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flAveWindSpeed", false, value);
}
bool GCEnvWindShared::GetGusting() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvWindShared", "m_bGusting");
}
void GCEnvWindShared::SetGusting(bool value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_bGusting", false, value);
}
float GCEnvWindShared::GetWindAngleVariation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flWindAngleVariation");
}
void GCEnvWindShared::SetWindAngleVariation(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flWindAngleVariation", false, value);
}
float GCEnvWindShared::GetWindSpeedVariation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flWindSpeedVariation");
}
void GCEnvWindShared::SetWindSpeedVariation(float value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_flWindSpeedVariation", false, value);
}
CEntityIndex GCEnvWindShared::GetEntIndex() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "CEnvWindShared", "m_iEntIndex");
}
void GCEnvWindShared::SetEntIndex(CEntityIndex value) {
    SetSchemaValue(m_ptr, "CEnvWindShared", "m_iEntIndex", false, value);
}
std::string GCEnvWindShared::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvWindShared::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCEnvWindShared(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWindShared>("CEnvWindShared")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GCEnvWindShared::GetStartTime, &GCEnvWindShared::SetStartTime)
        .addProperty("WindSeed", &GCEnvWindShared::GetWindSeed, &GCEnvWindShared::SetWindSeed)
        .addProperty("MinWind", &GCEnvWindShared::GetMinWind, &GCEnvWindShared::SetMinWind)
        .addProperty("MaxWind", &GCEnvWindShared::GetMaxWind, &GCEnvWindShared::SetMaxWind)
        .addProperty("WindRadius", &GCEnvWindShared::GetWindRadius, &GCEnvWindShared::SetWindRadius)
        .addProperty("MinGust", &GCEnvWindShared::GetMinGust, &GCEnvWindShared::SetMinGust)
        .addProperty("MaxGust", &GCEnvWindShared::GetMaxGust, &GCEnvWindShared::SetMaxGust)
        .addProperty("MinGustDelay", &GCEnvWindShared::GetMinGustDelay, &GCEnvWindShared::SetMinGustDelay)
        .addProperty("MaxGustDelay", &GCEnvWindShared::GetMaxGustDelay, &GCEnvWindShared::SetMaxGustDelay)
        .addProperty("GustDuration", &GCEnvWindShared::GetGustDuration, &GCEnvWindShared::SetGustDuration)
        .addProperty("GustDirChange", &GCEnvWindShared::GetGustDirChange, &GCEnvWindShared::SetGustDirChange)
        .addProperty("Location", &GCEnvWindShared::GetLocation, &GCEnvWindShared::SetLocation)
        .addProperty("GustSound", &GCEnvWindShared::GetGustSound, &GCEnvWindShared::SetGustSound)
        .addProperty("WindDir", &GCEnvWindShared::GetWindDir, &GCEnvWindShared::SetWindDir)
        .addProperty("WindSpeed", &GCEnvWindShared::GetWindSpeed, &GCEnvWindShared::SetWindSpeed)
        .addProperty("CurrentWindVector", &GCEnvWindShared::GetCurrentWindVector, &GCEnvWindShared::SetCurrentWindVector)
        .addProperty("CurrentSwayVector", &GCEnvWindShared::GetCurrentSwayVector, &GCEnvWindShared::SetCurrentSwayVector)
        .addProperty("PrevSwayVector", &GCEnvWindShared::GetPrevSwayVector, &GCEnvWindShared::SetPrevSwayVector)
        .addProperty("InitialWindDir", &GCEnvWindShared::GetInitialWindDir, &GCEnvWindShared::SetInitialWindDir)
        .addProperty("InitialWindSpeed", &GCEnvWindShared::GetInitialWindSpeed, &GCEnvWindShared::SetInitialWindSpeed)
        .addProperty("OnGustStart", &GCEnvWindShared::GetOnGustStart, &GCEnvWindShared::SetOnGustStart)
        .addProperty("OnGustEnd", &GCEnvWindShared::GetOnGustEnd, &GCEnvWindShared::SetOnGustEnd)
        .addProperty("VariationTime", &GCEnvWindShared::GetVariationTime, &GCEnvWindShared::SetVariationTime)
        .addProperty("SwayTime", &GCEnvWindShared::GetSwayTime, &GCEnvWindShared::SetSwayTime)
        .addProperty("SimTime", &GCEnvWindShared::GetSimTime, &GCEnvWindShared::SetSimTime)
        .addProperty("SwitchTime", &GCEnvWindShared::GetSwitchTime, &GCEnvWindShared::SetSwitchTime)
        .addProperty("AveWindSpeed", &GCEnvWindShared::GetAveWindSpeed, &GCEnvWindShared::SetAveWindSpeed)
        .addProperty("Gusting", &GCEnvWindShared::GetGusting, &GCEnvWindShared::SetGusting)
        .addProperty("WindAngleVariation", &GCEnvWindShared::GetWindAngleVariation, &GCEnvWindShared::SetWindAngleVariation)
        .addProperty("WindSpeedVariation", &GCEnvWindShared::GetWindSpeedVariation, &GCEnvWindShared::SetWindSpeedVariation)
        .addProperty("EntIndex", &GCEnvWindShared::GetEntIndex, &GCEnvWindShared::SetEntIndex)
        .addFunction("ToPtr", &GCEnvWindShared::ToPtr)
        .addFunction("IsValid", &GCEnvWindShared::IsValid)
        .endClass();
}