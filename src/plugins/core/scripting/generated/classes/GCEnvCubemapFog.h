class GCEnvCubemapFog;

#ifndef _gccenvcubemapfog_h
#define _gccenvcubemapfog_h

#include "../../../scripting.h"




class GCEnvCubemapFog
{
private:
    void *m_ptr;

public:
    GCEnvCubemapFog() {}
    GCEnvCubemapFog(void *ptr) : m_ptr(ptr) {}

    float GetEndDistance() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flEndDistance"); }
    void SetEndDistance(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flEndDistance", false, value); }
    float GetStartDistance() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flStartDistance"); }
    void SetStartDistance(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flStartDistance", false, value); }
    float GetFogFalloffExponent() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogFalloffExponent"); }
    void SetFogFalloffExponent(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogFalloffExponent", false, value); }
    bool GetHeightFogEnabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bHeightFogEnabled"); }
    void SetHeightFogEnabled(bool value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bHeightFogEnabled", false, value); }
    float GetFogHeightWidth() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightWidth"); }
    void SetFogHeightWidth(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightWidth", false, value); }
    float GetFogHeightEnd() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightEnd"); }
    void SetFogHeightEnd(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightEnd", false, value); }
    float GetFogHeightStart() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightStart"); }
    void SetFogHeightStart(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightStart", false, value); }
    float GetFogHeightExponent() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogHeightExponent"); }
    void SetFogHeightExponent(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogHeightExponent", false, value); }
    float GetLODBias() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flLODBias"); }
    void SetLODBias(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flLODBias", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bActive", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bStartDisabled", false, value); }
    float GetFogMaxOpacity() const { return GetSchemaValue<float>(m_ptr, "CEnvCubemapFog", "m_flFogMaxOpacity"); }
    void SetFogMaxOpacity(float value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_flFogMaxOpacity", false, value); }
    int32_t GetCubemapSourceType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemapFog", "m_nCubemapSourceType"); }
    void SetCubemapSourceType(int32_t value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_nCubemapSourceType", false, value); }
    CUtlSymbolLarge GetSkyEntity() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvCubemapFog", "m_iszSkyEntity"); }
    void SetSkyEntity(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_iszSkyEntity", false, value); }
    bool GetHasHeightFogEnd() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bHasHeightFogEnd"); }
    void SetHasHeightFogEnd(bool value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bHasHeightFogEnd", false, value); }
    bool GetFirstTime() const { return GetSchemaValue<bool>(m_ptr, "CEnvCubemapFog", "m_bFirstTime"); }
    void SetFirstTime(bool value) { SetSchemaValue(m_ptr, "CEnvCubemapFog", "m_bFirstTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif