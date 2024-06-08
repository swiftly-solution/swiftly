class GCIntAnimParameter;

#ifndef _gccintanimparameter_h
#define _gccintanimparameter_h

#include "../../../scripting.h"




class GCIntAnimParameter
{
private:
    void *m_ptr;

public:
    GCIntAnimParameter() {}
    GCIntAnimParameter(void *ptr) : m_ptr(ptr) {}

    int32_t GetDefaultValue() const { return GetSchemaValue<int32_t>(m_ptr, "CIntAnimParameter", "m_defaultValue"); }
    void SetDefaultValue(int32_t value) { SetSchemaValue(m_ptr, "CIntAnimParameter", "m_defaultValue", false, value); }
    int32_t GetMinValue() const { return GetSchemaValue<int32_t>(m_ptr, "CIntAnimParameter", "m_minValue"); }
    void SetMinValue(int32_t value) { SetSchemaValue(m_ptr, "CIntAnimParameter", "m_minValue", false, value); }
    int32_t GetMaxValue() const { return GetSchemaValue<int32_t>(m_ptr, "CIntAnimParameter", "m_maxValue"); }
    void SetMaxValue(int32_t value) { SetSchemaValue(m_ptr, "CIntAnimParameter", "m_maxValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif