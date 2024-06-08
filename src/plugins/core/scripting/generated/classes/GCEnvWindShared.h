class GCEnvWindShared;

#ifndef _gccenvwindshared_h
#define _gccenvwindshared_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCEnvWindShared
{
private:
    void *m_ptr;

public:
    GCEnvWindShared() {}
    GCEnvWindShared(void *ptr) : m_ptr(ptr) {}

    uint32_t GetWindSeed() const { return GetSchemaValue<uint32_t>(m_ptr, "CEnvWindShared", "m_iWindSeed"); }
    void SetWindSeed(uint32_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iWindSeed", false, value); }
    uint16_t GetMinWind() const { return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMinWind"); }
    void SetMinWind(uint16_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMinWind", false, value); }
    uint16_t GetMaxWind() const { return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMaxWind"); }
    void SetMaxWind(uint16_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMaxWind", false, value); }
    int32_t GetWindRadius() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvWindShared", "m_windRadius"); }
    void SetWindRadius(int32_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_windRadius", false, value); }
    uint16_t GetMinGust() const { return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMinGust"); }
    void SetMinGust(uint16_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMinGust", false, value); }
    uint16_t GetMaxGust() const { return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iMaxGust"); }
    void SetMaxGust(uint16_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iMaxGust", false, value); }
    float GetMinGustDelay() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flMinGustDelay"); }
    void SetMinGustDelay(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flMinGustDelay", false, value); }
    float GetMaxGustDelay() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flMaxGustDelay"); }
    void SetMaxGustDelay(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flMaxGustDelay", false, value); }
    float GetGustDuration() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flGustDuration"); }
    void SetGustDuration(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flGustDuration", false, value); }
    uint16_t GetGustDirChange() const { return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iGustDirChange"); }
    void SetGustDirChange(uint16_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iGustDirChange", false, value); }
    Vector GetLocation() const { return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_location"); }
    void SetLocation(Vector value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_location", false, value); }
    int32_t GetGustSound() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvWindShared", "m_iszGustSound"); }
    void SetGustSound(int32_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iszGustSound", false, value); }
    int32_t GetWindDir() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvWindShared", "m_iWindDir"); }
    void SetWindDir(int32_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iWindDir", false, value); }
    float GetWindSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flWindSpeed"); }
    void SetWindSpeed(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flWindSpeed", false, value); }
    Vector GetCurrentWindVector() const { return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_currentWindVector"); }
    void SetCurrentWindVector(Vector value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_currentWindVector", false, value); }
    Vector GetCurrentSwayVector() const { return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_CurrentSwayVector"); }
    void SetCurrentSwayVector(Vector value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_CurrentSwayVector", false, value); }
    Vector GetPrevSwayVector() const { return GetSchemaValue<Vector>(m_ptr, "CEnvWindShared", "m_PrevSwayVector"); }
    void SetPrevSwayVector(Vector value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_PrevSwayVector", false, value); }
    uint16_t GetInitialWindDir() const { return GetSchemaValue<uint16_t>(m_ptr, "CEnvWindShared", "m_iInitialWindDir"); }
    void SetInitialWindDir(uint16_t value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iInitialWindDir", false, value); }
    float GetInitialWindSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flInitialWindSpeed"); }
    void SetInitialWindSpeed(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flInitialWindSpeed", false, value); }
    GCEntityIOOutput GetOnGustStart() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvWindShared", "m_OnGustStart"); }
    void SetOnGustStart(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_OnGustStart", false, value); }
    GCEntityIOOutput GetOnGustEnd() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CEnvWindShared", "m_OnGustEnd"); }
    void SetOnGustEnd(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_OnGustEnd", false, value); }
    float GetAveWindSpeed() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flAveWindSpeed"); }
    void SetAveWindSpeed(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flAveWindSpeed", false, value); }
    bool GetGusting() const { return GetSchemaValue<bool>(m_ptr, "CEnvWindShared", "m_bGusting"); }
    void SetGusting(bool value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_bGusting", false, value); }
    float GetWindAngleVariation() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flWindAngleVariation"); }
    void SetWindAngleVariation(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flWindAngleVariation", false, value); }
    float GetWindSpeedVariation() const { return GetSchemaValue<float>(m_ptr, "CEnvWindShared", "m_flWindSpeedVariation"); }
    void SetWindSpeedVariation(float value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_flWindSpeedVariation", false, value); }
    CEntityIndex GetEntIndex() const { return GetSchemaValue<CEntityIndex>(m_ptr, "CEnvWindShared", "m_iEntIndex"); }
    void SetEntIndex(CEntityIndex value) { SetSchemaValue(m_ptr, "CEnvWindShared", "m_iEntIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif