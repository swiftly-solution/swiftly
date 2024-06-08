class GCMultiLightProxy;

#ifndef _gccmultilightproxy_h
#define _gccmultilightproxy_h

#include "../../../scripting.h"




class GCMultiLightProxy
{
private:
    void *m_ptr;

public:
    GCMultiLightProxy() {}
    GCMultiLightProxy(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetLightNameFilter() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMultiLightProxy", "m_iszLightNameFilter"); }
    void SetLightNameFilter(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_iszLightNameFilter", false, value); }
    CUtlSymbolLarge GetLightClassFilter() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMultiLightProxy", "m_iszLightClassFilter"); }
    void SetLightClassFilter(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_iszLightClassFilter", false, value); }
    float GetLightRadiusFilter() const { return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flLightRadiusFilter"); }
    void SetLightRadiusFilter(float value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flLightRadiusFilter", false, value); }
    float GetBrightnessDelta() const { return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flBrightnessDelta"); }
    void SetBrightnessDelta(float value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flBrightnessDelta", false, value); }
    bool GetPerformScreenFade() const { return GetSchemaValue<bool>(m_ptr, "CMultiLightProxy", "m_bPerformScreenFade"); }
    void SetPerformScreenFade(bool value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_bPerformScreenFade", false, value); }
    float GetTargetBrightnessMultiplier() const { return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flTargetBrightnessMultiplier"); }
    void SetTargetBrightnessMultiplier(float value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flTargetBrightnessMultiplier", false, value); }
    float GetCurrentBrightnessMultiplier() const { return GetSchemaValue<float>(m_ptr, "CMultiLightProxy", "m_flCurrentBrightnessMultiplier"); }
    void SetCurrentBrightnessMultiplier(float value) { SetSchemaValue(m_ptr, "CMultiLightProxy", "m_flCurrentBrightnessMultiplier", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif