class GC_INIT_RandomAlphaWindowThreshold;

#ifndef _gcc_init_randomalphawindowthreshold_h
#define _gcc_init_randomalphawindowthreshold_h

#include "../../../scripting.h"




class GC_INIT_RandomAlphaWindowThreshold
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomAlphaWindowThreshold() {}
    GC_INIT_RandomAlphaWindowThreshold(void *ptr) : m_ptr(ptr) {}

    float GetMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomAlphaWindowThreshold", "m_flMin"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlphaWindowThreshold", "m_flMin", false, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomAlphaWindowThreshold", "m_flMax"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlphaWindowThreshold", "m_flMax", false, value); }
    float GetExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomAlphaWindowThreshold", "m_flExponent"); }
    void SetExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomAlphaWindowThreshold", "m_flExponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif