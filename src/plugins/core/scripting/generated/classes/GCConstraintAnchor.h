class GCConstraintAnchor;

#ifndef _gccconstraintanchor_h
#define _gccconstraintanchor_h

#include "../../../scripting.h"




class GCConstraintAnchor
{
private:
    void *m_ptr;

public:
    GCConstraintAnchor() {}
    GCConstraintAnchor(void *ptr) : m_ptr(ptr) {}

    float GetMassScale() const { return GetSchemaValue<float>(m_ptr, "CConstraintAnchor", "m_massScale"); }
    void SetMassScale(float value) { SetSchemaValue(m_ptr, "CConstraintAnchor", "m_massScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif