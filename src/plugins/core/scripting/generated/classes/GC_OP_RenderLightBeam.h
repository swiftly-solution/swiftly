class GC_OP_RenderLightBeam;

#ifndef _gcc_op_renderlightbeam_h
#define _gcc_op_renderlightbeam_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendType_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_RenderLightBeam
{
private:
    void *m_ptr;

public:
    GC_OP_RenderLightBeam() {}
    GC_OP_RenderLightBeam(void *ptr) : m_ptr(ptr) {}

    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderLightBeam", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderLightBeam", "m_nColorBlendType", false, value); }
    GCParticleCollectionFloatInput GetBrightnessLumensPerMeter() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderLightBeam", "m_flBrightnessLumensPerMeter"); }
    void SetBrightnessLumensPerMeter(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderLightBeam", "m_flBrightnessLumensPerMeter", false, value); }
    bool GetCastShadows() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderLightBeam", "m_bCastShadows"); }
    void SetCastShadows(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderLightBeam", "m_bCastShadows", false, value); }
    GCParticleCollectionFloatInput GetSkirt() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderLightBeam", "m_flSkirt"); }
    void SetSkirt(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderLightBeam", "m_flSkirt", false, value); }
    GCParticleCollectionFloatInput GetRange() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderLightBeam", "m_flRange"); }
    void SetRange(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderLightBeam", "m_flRange", false, value); }
    GCParticleCollectionFloatInput GetThickness() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderLightBeam", "m_flThickness"); }
    void SetThickness(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderLightBeam", "m_flThickness", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif