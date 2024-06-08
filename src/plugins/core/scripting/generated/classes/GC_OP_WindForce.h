class GC_OP_WindForce;

#ifndef _gcc_op_windforce_h
#define _gcc_op_windforce_h

#include "../../../scripting.h"




class GC_OP_WindForce
{
private:
    void *m_ptr;

public:
    GC_OP_WindForce() {}
    GC_OP_WindForce(void *ptr) : m_ptr(ptr) {}

    Vector GetForce() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_WindForce", "m_vForce"); }
    void SetForce(Vector value) { SetSchemaValue(m_ptr, "C_OP_WindForce", "m_vForce", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif