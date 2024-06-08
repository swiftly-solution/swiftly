class GC_OP_VectorFieldSnapshot;

#ifndef _gcc_op_vectorfieldsnapshot_h
#define _gcc_op_vectorfieldsnapshot_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"
#include "GCPerParticleVecInput.h"

class GC_OP_VectorFieldSnapshot
{
private:
    void *m_ptr;

public:
    GC_OP_VectorFieldSnapshot() {}
    GC_OP_VectorFieldSnapshot(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_VectorFieldSnapshot", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_nControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetAttributeToWrite() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_VectorFieldSnapshot", "m_nAttributeToWrite"); }
    void SetAttributeToWrite(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_nAttributeToWrite", false, value); }
    int32_t GetLocalSpaceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_VectorFieldSnapshot", "m_nLocalSpaceCP"); }
    void SetLocalSpaceCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_nLocalSpaceCP", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_VectorFieldSnapshot", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_flInterpolation", false, value); }
    GCPerParticleVecInput GetScale() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_VectorFieldSnapshot", "m_vecScale"); }
    void SetScale(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_vecScale", false, value); }
    float GetBoundaryDampening() const { return GetSchemaValue<float>(m_ptr, "C_OP_VectorFieldSnapshot", "m_flBoundaryDampening"); }
    void SetBoundaryDampening(float value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_flBoundaryDampening", false, value); }
    bool GetSetVelocity() const { return GetSchemaValue<bool>(m_ptr, "C_OP_VectorFieldSnapshot", "m_bSetVelocity"); }
    void SetSetVelocity(bool value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_bSetVelocity", false, value); }
    bool GetLockToSurface() const { return GetSchemaValue<bool>(m_ptr, "C_OP_VectorFieldSnapshot", "m_bLockToSurface"); }
    void SetLockToSurface(bool value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_bLockToSurface", false, value); }
    float GetGridSpacing() const { return GetSchemaValue<float>(m_ptr, "C_OP_VectorFieldSnapshot", "m_flGridSpacing"); }
    void SetGridSpacing(float value) { SetSchemaValue(m_ptr, "C_OP_VectorFieldSnapshot", "m_flGridSpacing", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif