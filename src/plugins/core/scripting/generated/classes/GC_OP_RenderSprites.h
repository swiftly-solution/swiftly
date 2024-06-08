class GC_OP_RenderSprites;

#ifndef _gcc_op_rendersprites_h
#define _gcc_op_rendersprites_h

#include "../../../scripting.h"

#include "../types/GParticleOrientationChoiceList_t.h"
#include "../types/GParticleLightingQuality_t.h"
#include "GCParticleCollectionRendererFloatInput.h"
#include "GCReplicationParameters.h"

class GC_OP_RenderSprites
{
private:
    void *m_ptr;

public:
    GC_OP_RenderSprites() {}
    GC_OP_RenderSprites(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionRendererFloatInput GetSequenceOverride() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_nSequenceOverride"); }
    void SetSequenceOverride(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_nSequenceOverride", false, value); }
    ParticleOrientationChoiceList_t GetOrientationType() const { return GetSchemaValue<ParticleOrientationChoiceList_t>(m_ptr, "C_OP_RenderSprites", "m_nOrientationType"); }
    void SetOrientationType(ParticleOrientationChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_nOrientationType", false, value); }
    int32_t GetOrientationControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderSprites", "m_nOrientationControlPoint"); }
    void SetOrientationControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_nOrientationControlPoint", false, value); }
    bool GetUseYawWithNormalAligned() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSprites", "m_bUseYawWithNormalAligned"); }
    void SetUseYawWithNormalAligned(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_bUseYawWithNormalAligned", false, value); }
    GCParticleCollectionRendererFloatInput GetMinSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flMinSize"); }
    void SetMinSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flMinSize", false, value); }
    GCParticleCollectionRendererFloatInput GetMaxSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flMaxSize"); }
    void SetMaxSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flMaxSize", false, value); }
    GCParticleCollectionRendererFloatInput GetAlphaAdjustWithSizeAdjust() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flAlphaAdjustWithSizeAdjust"); }
    void SetAlphaAdjustWithSizeAdjust(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flAlphaAdjustWithSizeAdjust", false, value); }
    GCParticleCollectionRendererFloatInput GetStartFadeSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flStartFadeSize"); }
    void SetStartFadeSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flStartFadeSize", false, value); }
    GCParticleCollectionRendererFloatInput GetEndFadeSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flEndFadeSize"); }
    void SetEndFadeSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flEndFadeSize", false, value); }
    float GetStartFadeDot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flStartFadeDot"); }
    void SetStartFadeDot(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flStartFadeDot", false, value); }
    float GetEndFadeDot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flEndFadeDot"); }
    void SetEndFadeDot(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flEndFadeDot", false, value); }
    bool GetDistanceAlpha() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSprites", "m_bDistanceAlpha"); }
    void SetDistanceAlpha(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_bDistanceAlpha", false, value); }
    bool GetSoftEdges() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSprites", "m_bSoftEdges"); }
    void SetSoftEdges(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_bSoftEdges", false, value); }
    float GetEdgeSoftnessStart() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flEdgeSoftnessStart"); }
    void SetEdgeSoftnessStart(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flEdgeSoftnessStart", false, value); }
    float GetEdgeSoftnessEnd() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flEdgeSoftnessEnd"); }
    void SetEdgeSoftnessEnd(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flEdgeSoftnessEnd", false, value); }
    bool GetOutline() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSprites", "m_bOutline"); }
    void SetOutline(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_bOutline", false, value); }
    Color GetOutlineColor() const { return GetSchemaValue<Color>(m_ptr, "C_OP_RenderSprites", "m_OutlineColor"); }
    void SetOutlineColor(Color value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_OutlineColor", false, value); }
    int32_t GetOutlineAlpha() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderSprites", "m_nOutlineAlpha"); }
    void SetOutlineAlpha(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_nOutlineAlpha", false, value); }
    float GetOutlineStart0() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flOutlineStart0"); }
    void SetOutlineStart0(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flOutlineStart0", false, value); }
    float GetOutlineStart1() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flOutlineStart1"); }
    void SetOutlineStart1(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flOutlineStart1", false, value); }
    float GetOutlineEnd0() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flOutlineEnd0"); }
    void SetOutlineEnd0(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flOutlineEnd0", false, value); }
    float GetOutlineEnd1() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flOutlineEnd1"); }
    void SetOutlineEnd1(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flOutlineEnd1", false, value); }
    ParticleLightingQuality_t GetLightingMode() const { return GetSchemaValue<ParticleLightingQuality_t>(m_ptr, "C_OP_RenderSprites", "m_nLightingMode"); }
    void SetLightingMode(ParticleLightingQuality_t value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_nLightingMode", false, value); }
    GCParticleCollectionRendererFloatInput GetLightingTessellation() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flLightingTessellation"); }
    void SetLightingTessellation(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flLightingTessellation", false, value); }
    GCParticleCollectionRendererFloatInput GetLightingDirectionality() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderSprites", "m_flLightingDirectionality"); }
    void SetLightingDirectionality(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flLightingDirectionality", false, value); }
    bool GetParticleShadows() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderSprites", "m_bParticleShadows"); }
    void SetParticleShadows(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_bParticleShadows", false, value); }
    float GetShadowDensity() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderSprites", "m_flShadowDensity"); }
    void SetShadowDensity(float value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_flShadowDensity", false, value); }
    GCReplicationParameters GetReplicationParameters() const { return GetSchemaValue<GCReplicationParameters>(m_ptr, "C_OP_RenderSprites", "m_replicationParameters"); }
    void SetReplicationParameters(GCReplicationParameters value) { SetSchemaValue(m_ptr, "C_OP_RenderSprites", "m_replicationParameters", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif