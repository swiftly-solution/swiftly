class GC_INIT_RandomRadius;

#ifndef _gcc_init_randomradius_h
#define _gcc_init_randomradius_h

#include "../../../scripting.h"




class GC_INIT_RandomRadius
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomRadius() {}
    GC_INIT_RandomRadius(void *ptr) : m_ptr(ptr) {}

    float GetRadiusMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomRadius", "m_flRadiusMin"); }
    void SetRadiusMin(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomRadius", "m_flRadiusMin", false, value); }
    float GetRadiusMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomRadius", "m_flRadiusMax"); }
    void SetRadiusMax(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomRadius", "m_flRadiusMax", false, value); }
    float GetRadiusRandExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomRadius", "m_flRadiusRandExponent"); }
    void SetRadiusRandExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomRadius", "m_flRadiusRandExponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif