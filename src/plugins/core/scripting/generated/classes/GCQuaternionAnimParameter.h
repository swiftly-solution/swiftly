class GCQuaternionAnimParameter;

#ifndef _gccquaternionanimparameter_h
#define _gccquaternionanimparameter_h

#include "../../../scripting.h"




class GCQuaternionAnimParameter
{
private:
    void *m_ptr;

public:
    GCQuaternionAnimParameter() {}
    GCQuaternionAnimParameter(void *ptr) : m_ptr(ptr) {}

    Quaternion GetDefaultValue() const { return GetSchemaValue<Quaternion>(m_ptr, "CQuaternionAnimParameter", "m_defaultValue"); }
    void SetDefaultValue(Quaternion value) { SetSchemaValue(m_ptr, "CQuaternionAnimParameter", "m_defaultValue", false, value); }
    bool GetInterpolate() const { return GetSchemaValue<bool>(m_ptr, "CQuaternionAnimParameter", "m_bInterpolate"); }
    void SetInterpolate(bool value) { SetSchemaValue(m_ptr, "CQuaternionAnimParameter", "m_bInterpolate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif