class GC_OP_RenderScreenShake;

#ifndef _gcc_op_renderscreenshake_h
#define _gcc_op_renderscreenshake_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderScreenShake
{
private:
    void *m_ptr;

public:
    GC_OP_RenderScreenShake() {}
    GC_OP_RenderScreenShake(void *ptr) : m_ptr(ptr) {}

    float GetDurationScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderScreenShake", "m_flDurationScale"); }
    void SetDurationScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_flDurationScale", false, value); }
    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderScreenShake", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_flRadiusScale", false, value); }
    float GetFrequencyScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderScreenShake", "m_flFrequencyScale"); }
    void SetFrequencyScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_flFrequencyScale", false, value); }
    float GetAmplitudeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderScreenShake", "m_flAmplitudeScale"); }
    void SetAmplitudeScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_flAmplitudeScale", false, value); }
    GParticleAttributeIndex_t GetRadiusField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderScreenShake", "m_nRadiusField"); }
    void SetRadiusField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_nRadiusField", false, value); }
    GParticleAttributeIndex_t GetDurationField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderScreenShake", "m_nDurationField"); }
    void SetDurationField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_nDurationField", false, value); }
    GParticleAttributeIndex_t GetFrequencyField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderScreenShake", "m_nFrequencyField"); }
    void SetFrequencyField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_nFrequencyField", false, value); }
    GParticleAttributeIndex_t GetAmplitudeField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderScreenShake", "m_nAmplitudeField"); }
    void SetAmplitudeField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_nAmplitudeField", false, value); }
    int32_t GetFilterCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderScreenShake", "m_nFilterCP"); }
    void SetFilterCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenShake", "m_nFilterCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif