class GCSplineConstraint;

#ifndef _gccsplineconstraint_h
#define _gccsplineconstraint_h

#include "../../../scripting.h"




class GCSplineConstraint
{
private:
    void *m_ptr;

public:
    GCSplineConstraint() {}
    GCSplineConstraint(void *ptr) : m_ptr(ptr) {}

    Vector GetAnchorOffsetRestore() const { return GetSchemaValue<Vector>(m_ptr, "CSplineConstraint", "m_vAnchorOffsetRestore"); }
    void SetAnchorOffsetRestore(Vector value) { SetSchemaValue(m_ptr, "CSplineConstraint", "m_vAnchorOffsetRestore", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif