class GCMathCounter;

#ifndef _gccmathcounter_h
#define _gccmathcounter_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCMathCounter
{
private:
    void *m_ptr;

public:
    GCMathCounter() {}
    GCMathCounter(void *ptr) : m_ptr(ptr) {}

    float GetMin() const { return GetSchemaValue<float>(m_ptr, "CMathCounter", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "CMathCounter", "m_flMin", false, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "CMathCounter", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "CMathCounter", "m_flMax", false, value); }
    bool GetHitMin() const { return GetSchemaValue<bool>(m_ptr, "CMathCounter", "m_bHitMin"); }
    void SetHitMin(bool value) { SetSchemaValue(m_ptr, "CMathCounter", "m_bHitMin", false, value); }
    bool GetHitMax() const { return GetSchemaValue<bool>(m_ptr, "CMathCounter", "m_bHitMax"); }
    void SetHitMax(bool value) { SetSchemaValue(m_ptr, "CMathCounter", "m_bHitMax", false, value); }
    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CMathCounter", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CMathCounter", "m_bDisabled", false, value); }
    GCEntityIOOutput GetOnHitMin() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathCounter", "m_OnHitMin"); }
    void SetOnHitMin(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathCounter", "m_OnHitMin", false, value); }
    GCEntityIOOutput GetOnHitMax() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathCounter", "m_OnHitMax"); }
    void SetOnHitMax(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathCounter", "m_OnHitMax", false, value); }
    GCEntityIOOutput GetOnChangedFromMin() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathCounter", "m_OnChangedFromMin"); }
    void SetOnChangedFromMin(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathCounter", "m_OnChangedFromMin", false, value); }
    GCEntityIOOutput GetOnChangedFromMax() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMathCounter", "m_OnChangedFromMax"); }
    void SetOnChangedFromMax(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMathCounter", "m_OnChangedFromMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif