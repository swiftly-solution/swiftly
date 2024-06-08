class GCMathRemap;

#ifndef _gccmathremap_h
#define _gccmathremap_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCMathRemap
{
private:
    void *m_ptr;

public:
    GCMathRemap() {}
    GCMathRemap(void *ptr) : m_ptr(ptr) {}

    float GetInMin() const { return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flInMin"); }
    void SetInMin(float value) { SetSchemaValue(m_ptr, "CMathRemap", "m_flInMin", false, value); }
    float GetInMax() const { return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flInMax"); }
    void SetInMax(float value) { SetSchemaValue(m_ptr, "CMathRemap", "m_flInMax", false, value); }
    float GetOut1() const { return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flOut1"); }
    void SetOut1(float value) { SetSchemaValue(m_ptr, "CMathRemap", "m_flOut1", false, value); }
    float GetOut2() const { return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flOut2"); }
    void SetOut2(float value) { SetSchemaValue(m_ptr, "CMathRemap", "m_flOut2", false, value); }
    float GetOldInValue() const { return GetSchemaValue<float>(m_ptr, "CMathRemap", "m_flOldInValue"); }
    void SetOldInValue(float value) { SetSchemaValue(m_ptr, "CMathRemap", "m_flOldInValue", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CMathRemap", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CMathRemap", "m_bEnabled", false, value); }
    GCEntityIOOutput GetOnRoseAboveMin() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathRemap", "m_OnRoseAboveMin"); }
    void SetOnRoseAboveMin(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathRemap", "m_OnRoseAboveMin", false, value); }
    GCEntityIOOutput GetOnRoseAboveMax() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathRemap", "m_OnRoseAboveMax"); }
    void SetOnRoseAboveMax(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathRemap", "m_OnRoseAboveMax", false, value); }
    GCEntityIOOutput GetOnFellBelowMin() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathRemap", "m_OnFellBelowMin"); }
    void SetOnFellBelowMin(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathRemap", "m_OnFellBelowMin", false, value); }
    GCEntityIOOutput GetOnFellBelowMax() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathRemap", "m_OnFellBelowMax"); }
    void SetOnFellBelowMax(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathRemap", "m_OnFellBelowMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif