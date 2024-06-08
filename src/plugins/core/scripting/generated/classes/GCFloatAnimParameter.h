class GCFloatAnimParameter;

#ifndef _gccfloatanimparameter_h
#define _gccfloatanimparameter_h

#include "../../../scripting.h"




class GCFloatAnimParameter
{
private:
    void *m_ptr;

public:
    GCFloatAnimParameter() {}
    GCFloatAnimParameter(void *ptr) : m_ptr(ptr) {}

    float GetDefaultValue() const { return GetSchemaValue<float>(m_ptr, "CFloatAnimParameter", "m_fDefaultValue"); }
    void SetDefaultValue(float value) { SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_fDefaultValue", false, value); }
    float GetMinValue() const { return GetSchemaValue<float>(m_ptr, "CFloatAnimParameter", "m_fMinValue"); }
    void SetMinValue(float value) { SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_fMinValue", false, value); }
    float GetMaxValue() const { return GetSchemaValue<float>(m_ptr, "CFloatAnimParameter", "m_fMaxValue"); }
    void SetMaxValue(float value) { SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_fMaxValue", false, value); }
    bool GetInterpolate() const { return GetSchemaValue<bool>(m_ptr, "CFloatAnimParameter", "m_bInterpolate"); }
    void SetInterpolate(bool value) { SetSchemaValue(m_ptr, "CFloatAnimParameter", "m_bInterpolate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif