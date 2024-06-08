class GC_OP_MoveToHitbox;

#ifndef _gcc_op_movetohitbox_h
#define _gcc_op_movetohitbox_h

#include "../../../scripting.h"

#include "../types/GHitboxLerpType_t.h"
#include "GCParticleModelInput.h"
#include "GCParticleTransformInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_MoveToHitbox
{
private:
    void *m_ptr;

public:
    GC_OP_MoveToHitbox() {}
    GC_OP_MoveToHitbox(void *ptr) : m_ptr(ptr) {}

    GCParticleModelInput GetModelInput() const { return GetSchemaValue<GCParticleModelInput>(m_ptr, "C_OP_MoveToHitbox", "m_modelInput"); }
    void SetModelInput(GCParticleModelInput value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_modelInput", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_MoveToHitbox", "m_transformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_transformInput", false, value); }
    float GetLifeTimeLerpStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_MoveToHitbox", "m_flLifeTimeLerpStart"); }
    void SetLifeTimeLerpStart(float value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_flLifeTimeLerpStart", false, value); }
    float GetLifeTimeLerpEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_MoveToHitbox", "m_flLifeTimeLerpEnd"); }
    void SetLifeTimeLerpEnd(float value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_flLifeTimeLerpEnd", false, value); }
    float GetPrevPosScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_MoveToHitbox", "m_flPrevPosScale"); }
    void SetPrevPosScale(float value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_flPrevPosScale", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_MoveToHitbox", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_HitboxSetName", false, value); }
    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MoveToHitbox", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_bUseBones", false, value); }
    HitboxLerpType_t GetLerpType() const { return GetSchemaValue<HitboxLerpType_t>(m_ptr, "C_OP_MoveToHitbox", "m_nLerpType"); }
    void SetLerpType(HitboxLerpType_t value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_nLerpType", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_MoveToHitbox", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MoveToHitbox", "m_flInterpolation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif