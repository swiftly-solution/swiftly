class GC_OP_MovementMoveAlongSkinnedCPSnapshot;

#ifndef _gcc_op_movementmovealongskinnedcpsnapshot_h
#define _gcc_op_movementmovealongskinnedcpsnapshot_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_OP_MovementMoveAlongSkinnedCPSnapshot
{
private:
    void *m_ptr;

public:
    GC_OP_MovementMoveAlongSkinnedCPSnapshot() {}
    GC_OP_MovementMoveAlongSkinnedCPSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_nControlPointNumber", false, value); }
    int32_t GetSnapshotControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_nSnapshotControlPointNumber"); }
    void SetSnapshotControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_nSnapshotControlPointNumber", false, value); }
    bool GetSetNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_bSetNormal"); }
    void SetSetNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_bSetNormal", false, value); }
    bool GetSetRadius() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_bSetRadius"); }
    void SetSetRadius(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_bSetRadius", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_flInterpolation", false, value); }
    GCPerParticleFloatInput GetTValue() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_flTValue"); }
    void SetTValue(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementMoveAlongSkinnedCPSnapshot", "m_flTValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif