class GC_OP_RandomForce;

#ifndef _gcc_op_randomforce_h
#define _gcc_op_randomforce_h

#include "../../../scripting.h"




class GC_OP_RandomForce
{
private:
    void *m_ptr;

public:
    GC_OP_RandomForce() {}
    GC_OP_RandomForce(void *ptr) : m_ptr(ptr) {}

    Vector GetMinForce() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RandomForce", "m_MinForce"); }
    void SetMinForce(Vector value) { SetSchemaValue(m_ptr, "C_OP_RandomForce", "m_MinForce", false, value); }
    Vector GetMaxForce() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RandomForce", "m_MaxForce"); }
    void SetMaxForce(Vector value) { SetSchemaValue(m_ptr, "C_OP_RandomForce", "m_MaxForce", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif