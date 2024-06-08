class GC_OP_RenderStandardLight;

#ifndef _gcc_op_renderstandardlight_h
#define _gcc_op_renderstandardlight_h

#include "../../../scripting.h"

#include "../types/GParticleLightTypeChoiceList_t.h"
#include "../types/GParticleColorBlendType_t.h"
#include "../types/GStandardLightingAttenuationStyle_t.h"
#include "../types/GParticleLightFogLightingMode_t.h"
#include "../types/GParticleLightBehaviorChoiceList_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCParticleCollectionRendererFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderStandardLight
{
private:
    void *m_ptr;

public:
    GC_OP_RenderStandardLight() {}
    GC_OP_RenderStandardLight(void *ptr) : m_ptr(ptr) {}

    ParticleLightTypeChoiceList_t GetLightType() const { return GetSchemaValue<ParticleLightTypeChoiceList_t>(m_ptr, "C_OP_RenderStandardLight", "m_nLightType"); }
    void SetLightType(ParticleLightTypeChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nLightType", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderStandardLight", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nColorBlendType", false, value); }
    GCParticleCollectionFloatInput GetIntensity() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flIntensity"); }
    void SetIntensity(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flIntensity", false, value); }
    bool GetCastShadows() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderStandardLight", "m_bCastShadows"); }
    void SetCastShadows(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_bCastShadows", false, value); }
    GCParticleCollectionFloatInput GetTheta() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flTheta"); }
    void SetTheta(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flTheta", false, value); }
    GCParticleCollectionFloatInput GetPhi() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flPhi"); }
    void SetPhi(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flPhi", false, value); }
    GCParticleCollectionFloatInput GetRadiusMultiplier() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flRadiusMultiplier"); }
    void SetRadiusMultiplier(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flRadiusMultiplier", false, value); }
    StandardLightingAttenuationStyle_t GetAttenuationStyle() const { return GetSchemaValue<StandardLightingAttenuationStyle_t>(m_ptr, "C_OP_RenderStandardLight", "m_nAttenuationStyle"); }
    void SetAttenuationStyle(StandardLightingAttenuationStyle_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nAttenuationStyle", false, value); }
    GCParticleCollectionFloatInput GetFalloffLinearity() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flFalloffLinearity"); }
    void SetFalloffLinearity(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flFalloffLinearity", false, value); }
    GCParticleCollectionFloatInput GetFiftyPercentFalloff() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flFiftyPercentFalloff"); }
    void SetFiftyPercentFalloff(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flFiftyPercentFalloff", false, value); }
    GCParticleCollectionFloatInput GetZeroPercentFalloff() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flZeroPercentFalloff"); }
    void SetZeroPercentFalloff(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flZeroPercentFalloff", false, value); }
    bool GetRenderDiffuse() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderStandardLight", "m_bRenderDiffuse"); }
    void SetRenderDiffuse(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_bRenderDiffuse", false, value); }
    bool GetRenderSpecular() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderStandardLight", "m_bRenderSpecular"); }
    void SetRenderSpecular(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_bRenderSpecular", false, value); }
    CUtlString GetLightCookie() const { return GetSchemaValue<CUtlString>(m_ptr, "C_OP_RenderStandardLight", "m_lightCookie"); }
    void SetLightCookie(CUtlString value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_lightCookie", false, value); }
    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderStandardLight", "m_nPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nPriority", false, value); }
    ParticleLightFogLightingMode_t GetFogLightingMode() const { return GetSchemaValue<ParticleLightFogLightingMode_t>(m_ptr, "C_OP_RenderStandardLight", "m_nFogLightingMode"); }
    void SetFogLightingMode(ParticleLightFogLightingMode_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nFogLightingMode", false, value); }
    GCParticleCollectionRendererFloatInput GetFogContribution() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderStandardLight", "m_flFogContribution"); }
    void SetFogContribution(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flFogContribution", false, value); }
    ParticleLightBehaviorChoiceList_t GetCapsuleLightBehavior() const { return GetSchemaValue<ParticleLightBehaviorChoiceList_t>(m_ptr, "C_OP_RenderStandardLight", "m_nCapsuleLightBehavior"); }
    void SetCapsuleLightBehavior(ParticleLightBehaviorChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nCapsuleLightBehavior", false, value); }
    float GetCapsuleLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderStandardLight", "m_flCapsuleLength"); }
    void SetCapsuleLength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flCapsuleLength", false, value); }
    bool GetReverseOrder() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderStandardLight", "m_bReverseOrder"); }
    void SetReverseOrder(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_bReverseOrder", false, value); }
    bool GetClosedLoop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderStandardLight", "m_bClosedLoop"); }
    void SetClosedLoop(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_bClosedLoop", false, value); }
    GParticleAttributeIndex_t GetPrevPntSource() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderStandardLight", "m_nPrevPntSource"); }
    void SetPrevPntSource(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_nPrevPntSource", false, value); }
    float GetMaxLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderStandardLight", "m_flMaxLength"); }
    void SetMaxLength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flMaxLength", false, value); }
    float GetMinLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderStandardLight", "m_flMinLength"); }
    void SetMinLength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flMinLength", false, value); }
    bool GetIgnoreDT() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderStandardLight", "m_bIgnoreDT"); }
    void SetIgnoreDT(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_bIgnoreDT", false, value); }
    float GetConstrainRadiusToLengthRatio() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderStandardLight", "m_flConstrainRadiusToLengthRatio"); }
    void SetConstrainRadiusToLengthRatio(float value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flConstrainRadiusToLengthRatio", false, value); }
    float GetLengthScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderStandardLight", "m_flLengthScale"); }
    void SetLengthScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flLengthScale", false, value); }
    float GetLengthFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderStandardLight", "m_flLengthFadeInTime"); }
    void SetLengthFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_RenderStandardLight", "m_flLengthFadeInTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif