class GCBoolAnimParameter;

#ifndef _gccboolanimparameter_h
#define _gccboolanimparameter_h

#include "../../../scripting.h"




class GCBoolAnimParameter
{
private:
    void *m_ptr;

public:
    GCBoolAnimParameter() {}
    GCBoolAnimParameter(void *ptr) : m_ptr(ptr) {}

    bool GetDefaultValue() const { return GetSchemaValue<bool>(m_ptr, "CBoolAnimParameter", "m_bDefaultValue"); }
    void SetDefaultValue(bool value) { SetSchemaValue(m_ptr, "CBoolAnimParameter", "m_bDefaultValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif