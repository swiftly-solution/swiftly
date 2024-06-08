class GC_OP_RenderTreeShake;

#ifndef _gcc_op_rendertreeshake_h
#define _gcc_op_rendertreeshake_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderTreeShake
{
private:
    void *m_ptr;

public:
    GC_OP_RenderTreeShake() {}
    GC_OP_RenderTreeShake(void *ptr) : m_ptr(ptr) {}

    float GetPeakStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flPeakStrength"); }
    void SetPeakStrength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flPeakStrength", false, value); }
    GParticleAttributeIndex_t GetPeakStrengthFieldOverride() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTreeShake", "m_nPeakStrengthFieldOverride"); }
    void SetPeakStrengthFieldOverride(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_nPeakStrengthFieldOverride", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flRadius", false, value); }
    GParticleAttributeIndex_t GetRadiusFieldOverride() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTreeShake", "m_nRadiusFieldOverride"); }
    void SetRadiusFieldOverride(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_nRadiusFieldOverride", false, value); }
    float GetShakeDuration() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flShakeDuration"); }
    void SetShakeDuration(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flShakeDuration", false, value); }
    float GetTransitionTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flTransitionTime"); }
    void SetTransitionTime(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flTransitionTime", false, value); }
    float GetTwistAmount() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flTwistAmount"); }
    void SetTwistAmount(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flTwistAmount", false, value); }
    float GetRadialAmount() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flRadialAmount"); }
    void SetRadialAmount(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flRadialAmount", false, value); }
    float GetControlPointOrientationAmount() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTreeShake", "m_flControlPointOrientationAmount"); }
    void SetControlPointOrientationAmount(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_flControlPointOrientationAmount", false, value); }
    int32_t GetControlPointForLinearDirection() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderTreeShake", "m_nControlPointForLinearDirection"); }
    void SetControlPointForLinearDirection(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTreeShake", "m_nControlPointForLinearDirection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif