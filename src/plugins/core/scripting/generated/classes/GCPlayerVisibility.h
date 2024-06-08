class GCPlayerVisibility;

#ifndef _gccplayervisibility_h
#define _gccplayervisibility_h

#include "../../../scripting.h"




class GCPlayerVisibility
{
private:
    void *m_ptr;

public:
    GCPlayerVisibility() {}
    GCPlayerVisibility(void *ptr) : m_ptr(ptr) {}

    float GetVisibilityStrength() const { return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flVisibilityStrength"); }
    void SetVisibilityStrength(float value) { SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flVisibilityStrength", false, value); }
    float GetFogDistanceMultiplier() const { return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flFogDistanceMultiplier"); }
    void SetFogDistanceMultiplier(float value) { SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flFogDistanceMultiplier", false, value); }
    float GetFogMaxDensityMultiplier() const { return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flFogMaxDensityMultiplier"); }
    void SetFogMaxDensityMultiplier(float value) { SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flFogMaxDensityMultiplier", false, value); }
    float GetFadeTime() const { return GetSchemaValue<float>(m_ptr, "CPlayerVisibility", "m_flFadeTime"); }
    void SetFadeTime(float value) { SetSchemaValue(m_ptr, "CPlayerVisibility", "m_flFadeTime", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CPlayerVisibility", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CPlayerVisibility", "m_bStartDisabled", false, value); }
    bool GetIsEnabled() const { return GetSchemaValue<bool>(m_ptr, "CPlayerVisibility", "m_bIsEnabled"); }
    void SetIsEnabled(bool value) { SetSchemaValue(m_ptr, "CPlayerVisibility", "m_bIsEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif