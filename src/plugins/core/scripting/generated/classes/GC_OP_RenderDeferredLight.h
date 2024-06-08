class GC_OP_RenderDeferredLight;

#ifndef _gcc_op_renderdeferredlight_h
#define _gcc_op_renderdeferredlight_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendType_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderDeferredLight
{
private:
    void *m_ptr;

public:
    GC_OP_RenderDeferredLight() {}
    GC_OP_RenderDeferredLight(void *ptr) : m_ptr(ptr) {}

    bool GetUseAlphaTestWindow() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderDeferredLight", "m_bUseAlphaTestWindow"); }
    void SetUseAlphaTestWindow(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_bUseAlphaTestWindow", false, value); }
    bool GetUseTexture() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderDeferredLight", "m_bUseTexture"); }
    void SetUseTexture(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_bUseTexture", false, value); }
    float GetRadiusScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderDeferredLight", "m_flRadiusScale"); }
    void SetRadiusScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_flRadiusScale", false, value); }
    float GetAlphaScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderDeferredLight", "m_flAlphaScale"); }
    void SetAlphaScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_flAlphaScale", false, value); }
    GParticleAttributeIndex_t GetAlpha2Field() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderDeferredLight", "m_nAlpha2Field"); }
    void SetAlpha2Field(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_nAlpha2Field", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderDeferredLight", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_nColorBlendType", false, value); }
    float GetLightDistance() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderDeferredLight", "m_flLightDistance"); }
    void SetLightDistance(float value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_flLightDistance", false, value); }
    float GetStartFalloff() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderDeferredLight", "m_flStartFalloff"); }
    void SetStartFalloff(float value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_flStartFalloff", false, value); }
    float GetDistanceFalloff() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderDeferredLight", "m_flDistanceFalloff"); }
    void SetDistanceFalloff(float value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_flDistanceFalloff", false, value); }
    float GetSpotFoV() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderDeferredLight", "m_flSpotFoV"); }
    void SetSpotFoV(float value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_flSpotFoV", false, value); }
    GParticleAttributeIndex_t GetAlphaTestPointField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderDeferredLight", "m_nAlphaTestPointField"); }
    void SetAlphaTestPointField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_nAlphaTestPointField", false, value); }
    GParticleAttributeIndex_t GetAlphaTestRangeField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderDeferredLight", "m_nAlphaTestRangeField"); }
    void SetAlphaTestRangeField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_nAlphaTestRangeField", false, value); }
    GParticleAttributeIndex_t GetAlphaTestSharpnessField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderDeferredLight", "m_nAlphaTestSharpnessField"); }
    void SetAlphaTestSharpnessField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_nAlphaTestSharpnessField", false, value); }
    int32_t GetHSVShiftControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderDeferredLight", "m_nHSVShiftControlPoint"); }
    void SetHSVShiftControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderDeferredLight", "m_nHSVShiftControlPoint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif