class GC_INIT_RadiusFromCPObject;

#ifndef _gcc_init_radiusfromcpobject_h
#define _gcc_init_radiusfromcpobject_h

#include "../../../scripting.h"




class GC_INIT_RadiusFromCPObject
{
private:
    void *m_ptr;

public:
    GC_INIT_RadiusFromCPObject() {}
    GC_INIT_RadiusFromCPObject(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RadiusFromCPObject", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RadiusFromCPObject", "m_nControlPoint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif