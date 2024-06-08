class GC_OP_SDFForce;

#ifndef _gcc_op_sdfforce_h
#define _gcc_op_sdfforce_h

#include "../../../scripting.h"




class GC_OP_SDFForce
{
private:
    void *m_ptr;

public:
    GC_OP_SDFForce() {}
    GC_OP_SDFForce(void *ptr) : m_ptr(ptr) {}

    float GetForceScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_SDFForce", "m_flForceScale"); }
    void SetForceScale(float value) { SetSchemaValue(m_ptr, "C_OP_SDFForce", "m_flForceScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif