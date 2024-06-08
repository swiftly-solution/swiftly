class GCGlowProperty;

#ifndef _gccglowproperty_h
#define _gccglowproperty_h

#include "../../../scripting.h"




class GCGlowProperty
{
private:
    void *m_ptr;

public:
    GCGlowProperty() {}
    GCGlowProperty(void *ptr) : m_ptr(ptr) {}

    Vector GetGlowColor() const { return GetSchemaValue<Vector>(m_ptr, "CGlowProperty", "m_fGlowColor"); }
    void SetGlowColor(Vector value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_fGlowColor", false, value); }
    int32_t GetGlowType() const { return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_iGlowType"); }
    void SetGlowType(int32_t value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_iGlowType", false, value); }
    int32_t GetGlowTeam() const { return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_iGlowTeam"); }
    void SetGlowTeam(int32_t value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_iGlowTeam", false, value); }
    int32_t GetGlowRange() const { return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_nGlowRange"); }
    void SetGlowRange(int32_t value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_nGlowRange", false, value); }
    int32_t GetGlowRangeMin() const { return GetSchemaValue<int32_t>(m_ptr, "CGlowProperty", "m_nGlowRangeMin"); }
    void SetGlowRangeMin(int32_t value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_nGlowRangeMin", false, value); }
    Color GetGlowColorOverride() const { return GetSchemaValue<Color>(m_ptr, "CGlowProperty", "m_glowColorOverride"); }
    void SetGlowColorOverride(Color value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_glowColorOverride", false, value); }
    bool GetFlashing() const { return GetSchemaValue<bool>(m_ptr, "CGlowProperty", "m_bFlashing"); }
    void SetFlashing(bool value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_bFlashing", false, value); }
    float GetGlowTime() const { return GetSchemaValue<float>(m_ptr, "CGlowProperty", "m_flGlowTime"); }
    void SetGlowTime(float value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_flGlowTime", false, value); }
    float GetGlowStartTime() const { return GetSchemaValue<float>(m_ptr, "CGlowProperty", "m_flGlowStartTime"); }
    void SetGlowStartTime(float value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_flGlowStartTime", false, value); }
    bool GetEligibleForScreenHighlight() const { return GetSchemaValue<bool>(m_ptr, "CGlowProperty", "m_bEligibleForScreenHighlight"); }
    void SetEligibleForScreenHighlight(bool value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_bEligibleForScreenHighlight", false, value); }
    bool GetGlowing() const { return GetSchemaValue<bool>(m_ptr, "CGlowProperty", "m_bGlowing"); }
    void SetGlowing(bool value) { SetSchemaValue(m_ptr, "CGlowProperty", "m_bGlowing", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif