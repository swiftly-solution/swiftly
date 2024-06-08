class GCEnvSky;

#ifndef _gccenvsky_h
#define _gccenvsky_h

#include "../../../scripting.h"




class GCEnvSky
{
private:
    void *m_ptr;

public:
    GCEnvSky() {}
    GCEnvSky(void *ptr) : m_ptr(ptr) {}

    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvSky", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CEnvSky", "m_bStartDisabled", false, value); }
    Color GetTintColor() const { return GetSchemaValue<Color>(m_ptr, "CEnvSky", "m_vTintColor"); }
    void SetTintColor(Color value) { SetSchemaValue(m_ptr, "CEnvSky", "m_vTintColor", false, value); }
    Color GetTintColorLightingOnly() const { return GetSchemaValue<Color>(m_ptr, "CEnvSky", "m_vTintColorLightingOnly"); }
    void SetTintColorLightingOnly(Color value) { SetSchemaValue(m_ptr, "CEnvSky", "m_vTintColorLightingOnly", false, value); }
    float GetBrightnessScale() const { return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flBrightnessScale"); }
    void SetBrightnessScale(float value) { SetSchemaValue(m_ptr, "CEnvSky", "m_flBrightnessScale", false, value); }
    int32_t GetFogType() const { return GetSchemaValue<int32_t>(m_ptr, "CEnvSky", "m_nFogType"); }
    void SetFogType(int32_t value) { SetSchemaValue(m_ptr, "CEnvSky", "m_nFogType", false, value); }
    float GetFogMinStart() const { return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMinStart"); }
    void SetFogMinStart(float value) { SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMinStart", false, value); }
    float GetFogMinEnd() const { return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMinEnd"); }
    void SetFogMinEnd(float value) { SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMinEnd", false, value); }
    float GetFogMaxStart() const { return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMaxStart"); }
    void SetFogMaxStart(float value) { SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMaxStart", false, value); }
    float GetFogMaxEnd() const { return GetSchemaValue<float>(m_ptr, "CEnvSky", "m_flFogMaxEnd"); }
    void SetFogMaxEnd(float value) { SetSchemaValue(m_ptr, "CEnvSky", "m_flFogMaxEnd", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CEnvSky", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CEnvSky", "m_bEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif