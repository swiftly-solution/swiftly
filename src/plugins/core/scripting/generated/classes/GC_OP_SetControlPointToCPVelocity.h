class GC_OP_SetControlPointToCPVelocity;

#ifndef _gcc_op_setcontrolpointtocpvelocity_h
#define _gcc_op_setcontrolpointtocpvelocity_h

#include "../../../scripting.h"




class GC_OP_SetControlPointToCPVelocity
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointToCPVelocity() {}
    GC_OP_SetControlPointToCPVelocity(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPInput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPInput"); }
    void SetCPInput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPInput", false, value); }
    int32_t GetCPOutputVel() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPOutputVel"); }
    void SetCPOutputVel(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPOutputVel", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_bNormalize", false, value); }
    int32_t GetCPOutputMag() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPOutputMag"); }
    void SetCPOutputMag(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPOutputMag", false, value); }
    int32_t GetCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPField"); }
    void SetCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointToCPVelocity", "m_nCPField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif