class GCInterpolatedValue;

#ifndef _gccinterpolatedvalue_h
#define _gccinterpolatedvalue_h

#include "../../../scripting.h"




class GCInterpolatedValue
{
private:
    void *m_ptr;

public:
    GCInterpolatedValue() {}
    GCInterpolatedValue(void *ptr) : m_ptr(ptr) {}

    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flEndTime", false, value); }
    float GetStartValue() const { return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flStartValue"); }
    void SetStartValue(float value) { SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flStartValue", false, value); }
    float GetEndValue() const { return GetSchemaValue<float>(m_ptr, "CInterpolatedValue", "m_flEndValue"); }
    void SetEndValue(float value) { SetSchemaValue(m_ptr, "CInterpolatedValue", "m_flEndValue", false, value); }
    int32_t GetInterpType() const { return GetSchemaValue<int32_t>(m_ptr, "CInterpolatedValue", "m_nInterpType"); }
    void SetInterpType(int32_t value) { SetSchemaValue(m_ptr, "CInterpolatedValue", "m_nInterpType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif