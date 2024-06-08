class GC_OP_ExternalWindForce;

#ifndef _gcc_op_externalwindforce_h
#define _gcc_op_externalwindforce_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_ExternalWindForce
{
private:
    void *m_ptr;

public:
    GC_OP_ExternalWindForce() {}
    GC_OP_ExternalWindForce(void *ptr) : m_ptr(ptr) {}

    GCPerParticleVecInput GetSamplePosition() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ExternalWindForce", "m_vecSamplePosition"); }
    void SetSamplePosition(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_vecSamplePosition", false, value); }
    GCPerParticleVecInput GetScale() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ExternalWindForce", "m_vecScale"); }
    void SetScale(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_vecScale", false, value); }
    bool GetSampleWind() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalWindForce", "m_bSampleWind"); }
    void SetSampleWind(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_bSampleWind", false, value); }
    bool GetSampleWater() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalWindForce", "m_bSampleWater"); }
    void SetSampleWater(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_bSampleWater", false, value); }
    bool GetDampenNearWaterPlane() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalWindForce", "m_bDampenNearWaterPlane"); }
    void SetDampenNearWaterPlane(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_bDampenNearWaterPlane", false, value); }
    bool GetSampleGravity() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalWindForce", "m_bSampleGravity"); }
    void SetSampleGravity(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_bSampleGravity", false, value); }
    GCPerParticleVecInput GetGravityForce() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ExternalWindForce", "m_vecGravityForce"); }
    void SetGravityForce(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_vecGravityForce", false, value); }
    bool GetUseBasicMovementGravity() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ExternalWindForce", "m_bUseBasicMovementGravity"); }
    void SetUseBasicMovementGravity(bool value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_bUseBasicMovementGravity", false, value); }
    GCPerParticleFloatInput GetLocalGravityScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ExternalWindForce", "m_flLocalGravityScale"); }
    void SetLocalGravityScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_flLocalGravityScale", false, value); }
    GCPerParticleFloatInput GetLocalBuoyancyScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ExternalWindForce", "m_flLocalBuoyancyScale"); }
    void SetLocalBuoyancyScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_flLocalBuoyancyScale", false, value); }
    GCPerParticleVecInput GetBuoyancyForce() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_ExternalWindForce", "m_vecBuoyancyForce"); }
    void SetBuoyancyForce(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_ExternalWindForce", "m_vecBuoyancyForce", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif