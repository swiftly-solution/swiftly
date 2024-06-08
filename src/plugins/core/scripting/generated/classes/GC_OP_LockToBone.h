class GC_OP_LockToBone;

#ifndef _gcc_op_locktobone_h
#define _gcc_op_locktobone_h

#include "../../../scripting.h"

#include "../types/GParticleRotationLockType_t.h"
#include "GCParticleModelInput.h"
#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleVecInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_LockToBone
{
private:
    void *m_ptr;

public:
    GC_OP_LockToBone() {}
    GC_OP_LockToBone(void *ptr) : m_ptr(ptr) {}

    GCParticleModelInput GetModelInput() const { return GetSchemaValue<GCParticleModelInput>(m_ptr, "C_OP_LockToBone", "m_modelInput"); }
    void SetModelInput(GCParticleModelInput value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_modelInput", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_LockToBone", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_transformInput", false, value); }
    float GetLifeTimeFadeStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToBone", "m_flLifeTimeFadeStart"); }
    void SetLifeTimeFadeStart(float value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_flLifeTimeFadeStart", false, value); }
    float GetLifeTimeFadeEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToBone", "m_flLifeTimeFadeEnd"); }
    void SetLifeTimeFadeEnd(float value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_flLifeTimeFadeEnd", false, value); }
    float GetJumpThreshold() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToBone", "m_flJumpThreshold"); }
    void SetJumpThreshold(float value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_flJumpThreshold", false, value); }
    float GetPrevPosScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_LockToBone", "m_flPrevPosScale"); }
    void SetPrevPosScale(float value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_flPrevPosScale", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_LockToBone", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_HitboxSetName", false, value); }
    bool GetRigid() const { return GetSchemaValue<bool>(m_ptr, "C_OP_LockToBone", "m_bRigid"); }
    void SetRigid(bool value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_bRigid", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_OP_LockToBone", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_bUseBones", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LockToBone", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldOutputPrev() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LockToBone", "m_nFieldOutputPrev"); }
    void SetFieldOutputPrev(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_nFieldOutputPrev", false, value); }
    ParticleRotationLockType_t GetRotationSetType() const { return GetSchemaValue<ParticleRotationLockType_t>(m_ptr, "C_OP_LockToBone", "m_nRotationSetType"); }
    void SetRotationSetType(ParticleRotationLockType_t value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_nRotationSetType", false, value); }
    bool GetRigidRotationLock() const { return GetSchemaValue<bool>(m_ptr, "C_OP_LockToBone", "m_bRigidRotationLock"); }
    void SetRigidRotationLock(bool value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_bRigidRotationLock", false, value); }
    GCPerParticleVecInput GetRotation() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_LockToBone", "m_vecRotation"); }
    void SetRotation(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_vecRotation", false, value); }
    GCPerParticleFloatInput GetRotLerp() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_LockToBone", "m_flRotLerp"); }
    void SetRotLerp(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LockToBone", "m_flRotLerp", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif