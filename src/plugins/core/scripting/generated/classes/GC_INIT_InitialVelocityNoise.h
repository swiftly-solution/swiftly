class GC_INIT_InitialVelocityNoise;

#ifndef _gcc_init_initialvelocitynoise_h
#define _gcc_init_initialvelocitynoise_h

#include "../../../scripting.h"


#include "GCPerParticleVecInput.h"
#include "GCPerParticleFloatInput.h"
#include "GCParticleTransformInput.h"

class GC_INIT_InitialVelocityNoise
{
private:
    void *m_ptr;

public:
    GC_INIT_InitialVelocityNoise() {}
    GC_INIT_InitialVelocityNoise(void *ptr) : m_ptr(ptr) {}

    Vector GetAbsVal() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecAbsVal"); }
    void SetAbsVal(Vector value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecAbsVal", false, value); }
    Vector GetAbsValInv() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecAbsValInv"); }
    void SetAbsValInv(Vector value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecAbsValInv", false, value); }
    GCPerParticleVecInput GetOffsetLoc() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecOffsetLoc"); }
    void SetOffsetLoc(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecOffsetLoc", false, value); }
    GCPerParticleFloatInput GetOffset() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_flOffset"); }
    void SetOffset(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_flOffset", false, value); }
    GCPerParticleVecInput GetOutputMin() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecOutputMin"); }
    void SetOutputMin(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecOutputMin", false, value); }
    GCPerParticleVecInput GetOutputMax() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecOutputMax"); }
    void SetOutputMax(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_vecOutputMax", false, value); }
    GCPerParticleFloatInput GetNoiseScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_flNoiseScale"); }
    void SetNoiseScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_flNoiseScale", false, value); }
    GCPerParticleFloatInput GetNoiseScaleLoc() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_flNoiseScaleLoc"); }
    void SetNoiseScaleLoc(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_flNoiseScaleLoc", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_InitialVelocityNoise", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_TransformInput", false, value); }
    bool GetIgnoreDt() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_InitialVelocityNoise", "m_bIgnoreDt"); }
    void SetIgnoreDt(bool value) { SetSchemaValue(m_ptr, "C_INIT_InitialVelocityNoise", "m_bIgnoreDt", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif