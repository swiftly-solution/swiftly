class GC_OP_PositionLock;

#ifndef _gcc_op_positionlock_h
#define _gcc_op_positionlock_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GCParticleCollectionFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_PositionLock
{
private:
    void *m_ptr;

public:
    GC_OP_PositionLock() {}
    GC_OP_PositionLock(void *ptr) : m_ptr(ptr) {}

    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_PositionLock", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_TransformInput", false, value); }
    float GetStartTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flStartTime_min"); }
    void SetStartTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flStartTime_min", false, value); }
    float GetStartTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flStartTime_max"); }
    void SetStartTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flStartTime_max", false, value); }
    float GetStartTime_exp() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flStartTime_exp"); }
    void SetStartTime_exp(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flStartTime_exp", false, value); }
    float GetEndTime_min() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flEndTime_min"); }
    void SetEndTime_min(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flEndTime_min", false, value); }
    float GetEndTime_max() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flEndTime_max"); }
    void SetEndTime_max(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flEndTime_max", false, value); }
    float GetEndTime_exp() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flEndTime_exp"); }
    void SetEndTime_exp(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flEndTime_exp", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flRange", false, value); }
    GCParticleCollectionFloatInput GetRangeBias() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_PositionLock", "m_flRangeBias"); }
    void SetRangeBias(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flRangeBias", false, value); }
    float GetJumpThreshold() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flJumpThreshold"); }
    void SetJumpThreshold(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flJumpThreshold", false, value); }
    float GetPrevPosScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_PositionLock", "m_flPrevPosScale"); }
    void SetPrevPosScale(float value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_flPrevPosScale", false, value); }
    bool GetLockRot() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PositionLock", "m_bLockRot"); }
    void SetLockRot(bool value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_bLockRot", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_PositionLock", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldOutputPrev() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_PositionLock", "m_nFieldOutputPrev"); }
    void SetFieldOutputPrev(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_PositionLock", "m_nFieldOutputPrev", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif