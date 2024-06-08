class GC_OP_CurlNoiseForce;

#ifndef _gcc_op_curlnoiseforce_h
#define _gcc_op_curlnoiseforce_h

#include "../../../scripting.h"

#include "../types/GParticleDirectionNoiseType_t.h"
#include "GCPerParticleVecInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_CurlNoiseForce
{
private:
    void *m_ptr;

public:
    GC_OP_CurlNoiseForce() {}
    GC_OP_CurlNoiseForce(void *ptr) : m_ptr(ptr) {}

    ParticleDirectionNoiseType_t GetNoiseType() const { return GetSchemaValue<ParticleDirectionNoiseType_t>(m_ptr, "C_OP_CurlNoiseForce", "m_nNoiseType"); }
    void SetNoiseType(ParticleDirectionNoiseType_t value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_nNoiseType", false, value); }
    GCPerParticleVecInput GetNoiseFreq() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_CurlNoiseForce", "m_vecNoiseFreq"); }
    void SetNoiseFreq(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_vecNoiseFreq", false, value); }
    GCPerParticleVecInput GetNoiseScale() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_CurlNoiseForce", "m_vecNoiseScale"); }
    void SetNoiseScale(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_vecNoiseScale", false, value); }
    GCPerParticleVecInput GetOffset() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_CurlNoiseForce", "m_vecOffset"); }
    void SetOffset(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_vecOffset", false, value); }
    GCPerParticleVecInput GetOffsetRate() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_CurlNoiseForce", "m_vecOffsetRate"); }
    void SetOffsetRate(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_vecOffsetRate", false, value); }
    GCPerParticleFloatInput GetWorleySeed() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CurlNoiseForce", "m_flWorleySeed"); }
    void SetWorleySeed(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_flWorleySeed", false, value); }
    GCPerParticleFloatInput GetWorleyJitter() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CurlNoiseForce", "m_flWorleyJitter"); }
    void SetWorleyJitter(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CurlNoiseForce", "m_flWorleyJitter", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif