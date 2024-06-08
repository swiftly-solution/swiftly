class GCMathColorBlend;

#ifndef _gccmathcolorblend_h
#define _gccmathcolorblend_h

#include "../../../scripting.h"




class GCMathColorBlend
{
private:
    void *m_ptr;

public:
    GCMathColorBlend() {}
    GCMathColorBlend(void *ptr) : m_ptr(ptr) {}

    float GetInMin() const { return GetSchemaValue<float>(m_ptr, "CMathColorBlend", "m_flInMin"); }
    void SetInMin(float value) { SetSchemaValue(m_ptr, "CMathColorBlend", "m_flInMin", false, value); }
    float GetInMax() const { return GetSchemaValue<float>(m_ptr, "CMathColorBlend", "m_flInMax"); }
    void SetInMax(float value) { SetSchemaValue(m_ptr, "CMathColorBlend", "m_flInMax", false, value); }
    Color GetOutColor1() const { return GetSchemaValue<Color>(m_ptr, "CMathColorBlend", "m_OutColor1"); }
    void SetOutColor1(Color value) { SetSchemaValue(m_ptr, "CMathColorBlend", "m_OutColor1", false, value); }
    Color GetOutColor2() const { return GetSchemaValue<Color>(m_ptr, "CMathColorBlend", "m_OutColor2"); }
    void SetOutColor2(Color value) { SetSchemaValue(m_ptr, "CMathColorBlend", "m_OutColor2", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif