class GCPhysTorque;

#ifndef _gccphystorque_h
#define _gccphystorque_h

#include "../../../scripting.h"




class GCPhysTorque
{
private:
    void *m_ptr;

public:
    GCPhysTorque() {}
    GCPhysTorque(void *ptr) : m_ptr(ptr) {}

    Vector GetAxis() const { return GetSchemaValue<Vector>(m_ptr, "CPhysTorque", "m_axis"); }
    void SetAxis(Vector value) { SetSchemaValue(m_ptr, "CPhysTorque", "m_axis", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif