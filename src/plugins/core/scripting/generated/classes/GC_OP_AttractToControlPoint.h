class GC_OP_AttractToControlPoint;

#ifndef _gcc_op_attracttocontrolpoint_h
#define _gcc_op_attracttocontrolpoint_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCParticleTransformInput.h"

class GC_OP_AttractToControlPoint
{
private:
    void *m_ptr;

public:
    GC_OP_AttractToControlPoint() {}
    GC_OP_AttractToControlPoint(void *ptr) : m_ptr(ptr) {}

    Vector GetComponentScale() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_AttractToControlPoint", "m_vecComponentScale"); }
    void SetComponentScale(Vector value) { SetSchemaValue(m_ptr, "C_OP_AttractToControlPoint", "m_vecComponentScale", false, value); }
    GCPerParticleFloatInput GetForceAmount() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_AttractToControlPoint", "m_fForceAmount"); }
    void SetForceAmount(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_AttractToControlPoint", "m_fForceAmount", false, value); }
    float GetFalloffPower() const { return GetSchemaValue<float>(m_ptr, "C_OP_AttractToControlPoint", "m_fFalloffPower"); }
    void SetFalloffPower(float value) { SetSchemaValue(m_ptr, "C_OP_AttractToControlPoint", "m_fFalloffPower", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_AttractToControlPoint", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_AttractToControlPoint", "m_TransformInput", false, value); }
    GCPerParticleFloatInput GetForceAmountMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_AttractToControlPoint", "m_fForceAmountMin"); }
    void SetForceAmountMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_AttractToControlPoint", "m_fForceAmountMin", false, value); }
    bool GetApplyMinForce() const { return GetSchemaValue<bool>(m_ptr, "C_OP_AttractToControlPoint", "m_bApplyMinForce"); }
    void SetApplyMinForce(bool value) { SetSchemaValue(m_ptr, "C_OP_AttractToControlPoint", "m_bApplyMinForce", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif