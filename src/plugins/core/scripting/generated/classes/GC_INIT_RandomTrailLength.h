class GC_INIT_RandomTrailLength;

#ifndef _gcc_init_randomtraillength_h
#define _gcc_init_randomtraillength_h

#include "../../../scripting.h"




class GC_INIT_RandomTrailLength
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomTrailLength() {}
    GC_INIT_RandomTrailLength(void *ptr) : m_ptr(ptr) {}

    float GetMinLength() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomTrailLength", "m_flMinLength"); }
    void SetMinLength(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomTrailLength", "m_flMinLength", false, value); }
    float GetMaxLength() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomTrailLength", "m_flMaxLength"); }
    void SetMaxLength(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomTrailLength", "m_flMaxLength", false, value); }
    float GetLengthRandExponent() const { return GetSchemaValue<float>(m_ptr, "C_INIT_RandomTrailLength", "m_flLengthRandExponent"); }
    void SetLengthRandExponent(float value) { SetSchemaValue(m_ptr, "C_INIT_RandomTrailLength", "m_flLengthRandExponent", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif