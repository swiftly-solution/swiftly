class GCVectorAnimParameter;

#ifndef _gccvectoranimparameter_h
#define _gccvectoranimparameter_h

#include "../../../scripting.h"




class GCVectorAnimParameter
{
private:
    void *m_ptr;

public:
    GCVectorAnimParameter() {}
    GCVectorAnimParameter(void *ptr) : m_ptr(ptr) {}

    Vector GetDefaultValue() const { return GetSchemaValue<Vector>(m_ptr, "CVectorAnimParameter", "m_defaultValue"); }
    void SetDefaultValue(Vector value) { SetSchemaValue(m_ptr, "CVectorAnimParameter", "m_defaultValue", false, value); }
    bool GetInterpolate() const { return GetSchemaValue<bool>(m_ptr, "CVectorAnimParameter", "m_bInterpolate"); }
    void SetInterpolate(bool value) { SetSchemaValue(m_ptr, "CVectorAnimParameter", "m_bInterpolate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif