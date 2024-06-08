class GC_OP_MovementRigidAttachToCP;

#ifndef _gcc_op_movementrigidattachtocp_h
#define _gcc_op_movementrigidattachtocp_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_MovementRigidAttachToCP
{
private:
    void *m_ptr;

public:
    GC_OP_MovementRigidAttachToCP() {}
    GC_OP_MovementRigidAttachToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nControlPointNumber", false, value); }
    int32_t GetScaleControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nScaleControlPoint"); }
    void SetScaleControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nScaleControlPoint", false, value); }
    int32_t GetScaleCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nScaleCPField"); }
    void SetScaleCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nScaleCPField", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_MovementRigidAttachToCP", "m_nFieldOutput", false, value); }
    bool GetOffsetLocal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementRigidAttachToCP", "m_bOffsetLocal"); }
    void SetOffsetLocal(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementRigidAttachToCP", "m_bOffsetLocal", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif