class GC_OP_ParentVortices;

#ifndef _gcc_op_parentvortices_h
#define _gcc_op_parentvortices_h

#include "../../../scripting.h"




class GC_OP_ParentVortices
{
private:
    void *m_ptr;

public:
    GC_OP_ParentVortices() {}
    GC_OP_ParentVortices(void *ptr) : m_ptr(ptr) {}

    float GetForceScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_ParentVortices", "m_flForceScale"); }
    void SetForceScale(float value) { SetSchemaValue(m_ptr, "C_OP_ParentVortices", "m_flForceScale", false, value); }
    Vector GetTwistAxis() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ParentVortices", "m_vecTwistAxis"); }
    void SetTwistAxis(Vector value) { SetSchemaValue(m_ptr, "C_OP_ParentVortices", "m_vecTwistAxis", false, value); }
    bool GetFlipBasedOnYaw() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ParentVortices", "m_bFlipBasedOnYaw"); }
    void SetFlipBasedOnYaw(bool value) { SetSchemaValue(m_ptr, "C_OP_ParentVortices", "m_bFlipBasedOnYaw", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif