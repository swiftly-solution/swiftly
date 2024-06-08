class GC_OP_LocalAccelerationForce;

#ifndef _gcc_op_localaccelerationforce_h
#define _gcc_op_localaccelerationforce_h

#include "../../../scripting.h"




class GC_OP_LocalAccelerationForce
{
private:
    void *m_ptr;

public:
    GC_OP_LocalAccelerationForce() {}
    GC_OP_LocalAccelerationForce(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LocalAccelerationForce", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LocalAccelerationForce", "m_nCP", false, value); }
    int32_t GetScaleCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LocalAccelerationForce", "m_nScaleCP"); }
    void SetScaleCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LocalAccelerationForce", "m_nScaleCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif