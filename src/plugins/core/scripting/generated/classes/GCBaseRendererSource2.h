class GCBaseRendererSource2;

#ifndef _gccbaserenderersource2_h
#define _gccbaserenderersource2_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendType_t.h"
#include "../types/GSpriteCardShaderType_t.h"
#include "../types/GParticleSequenceCropOverride_t.h"
#include "../types/GAnimationType_t.h"
#include "../types/GParticleOutputBlendMode_t.h"
#include "../types/GParticleFogType_t.h"
#include "../types/GSpriteCardPerParticleScale_t.h"
#include "../types/GParticleAlphaReferenceType_t.h"
#include "../types/GBlurFilterType_t.h"
#include "../types/GParticleDepthFeatheringMode_t.h"
#include "../types/GParticleSortingChoiceList_t.h"
#include "GCParticleCollectionRendererFloatInput.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionRendererVecInput.h"
#include "GTextureGroup_t.h"

class GCBaseRendererSource2
{
private:
    void *m_ptr;

public:
    GCBaseRendererSource2() {}
    GCBaseRendererSource2(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionRendererFloatInput GetRadiusScale() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flRadiusScale"); }
    void SetRadiusScale(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flRadiusScale", false, value); }
    GCParticleCollectionRendererFloatInput GetAlphaScale() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flAlphaScale"); }
    void SetAlphaScale(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAlphaScale", false, value); }
    GCParticleCollectionRendererFloatInput GetRollScale() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flRollScale"); }
    void SetRollScale(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flRollScale", false, value); }
    GParticleAttributeIndex_t GetAlpha2Field() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CBaseRendererSource2", "m_nAlpha2Field"); }
    void SetAlpha2Field(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nAlpha2Field", false, value); }
    GCParticleCollectionRendererVecInput GetColorScale() const { return GetSchemaValue<GCParticleCollectionRendererVecInput>(m_ptr, "CBaseRendererSource2", "m_vecColorScale"); }
    void SetColorScale(GCParticleCollectionRendererVecInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_vecColorScale", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "CBaseRendererSource2", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nColorBlendType", false, value); }
    SpriteCardShaderType_t GetShaderType() const { return GetSchemaValue<SpriteCardShaderType_t>(m_ptr, "CBaseRendererSource2", "m_nShaderType"); }
    void SetShaderType(SpriteCardShaderType_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nShaderType", false, value); }
    CUtlString GetStrShaderOverride() const { return GetSchemaValue<CUtlString>(m_ptr, "CBaseRendererSource2", "m_strShaderOverride"); }
    void SetStrShaderOverride(CUtlString value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_strShaderOverride", false, value); }
    GCParticleCollectionRendererFloatInput GetCenterXOffset() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flCenterXOffset"); }
    void SetCenterXOffset(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flCenterXOffset", false, value); }
    GCParticleCollectionRendererFloatInput GetCenterYOffset() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flCenterYOffset"); }
    void SetCenterYOffset(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flCenterYOffset", false, value); }
    float GetBumpStrength() const { return GetSchemaValue<float>(m_ptr, "CBaseRendererSource2", "m_flBumpStrength"); }
    void SetBumpStrength(float value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flBumpStrength", false, value); }
    ParticleSequenceCropOverride_t GetCropTextureOverride() const { return GetSchemaValue<ParticleSequenceCropOverride_t>(m_ptr, "CBaseRendererSource2", "m_nCropTextureOverride"); }
    void SetCropTextureOverride(ParticleSequenceCropOverride_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nCropTextureOverride", false, value); }
    std::vector<GTextureGroup_t> GetTexturesInput() const { CUtlVector<GTextureGroup_t>* vec = GetSchemaValue<CUtlVector<GTextureGroup_t>*>(m_ptr, "CBaseRendererSource2", "m_vecTexturesInput"); std::vector<GTextureGroup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTexturesInput(std::vector<GTextureGroup_t> value) { SetSchemaValueCUtlVector<GTextureGroup_t>(m_ptr, "CBaseRendererSource2", "m_vecTexturesInput", false, value); }
    float GetAnimationRate() const { return GetSchemaValue<float>(m_ptr, "CBaseRendererSource2", "m_flAnimationRate"); }
    void SetAnimationRate(float value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAnimationRate", false, value); }
    AnimationType_t GetAnimationType() const { return GetSchemaValue<AnimationType_t>(m_ptr, "CBaseRendererSource2", "m_nAnimationType"); }
    void SetAnimationType(AnimationType_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nAnimationType", false, value); }
    bool GetAnimateInFPS() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bAnimateInFPS"); }
    void SetAnimateInFPS(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bAnimateInFPS", false, value); }
    GCParticleCollectionRendererFloatInput GetSelfIllumAmount() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flSelfIllumAmount"); }
    void SetSelfIllumAmount(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flSelfIllumAmount", false, value); }
    GCParticleCollectionRendererFloatInput GetDiffuseAmount() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flDiffuseAmount"); }
    void SetDiffuseAmount(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDiffuseAmount", false, value); }
    GCParticleCollectionRendererFloatInput GetDiffuseClamp() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flDiffuseClamp"); }
    void SetDiffuseClamp(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDiffuseClamp", false, value); }
    int32_t GetLightingControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseRendererSource2", "m_nLightingControlPoint"); }
    void SetLightingControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nLightingControlPoint", false, value); }
    GParticleAttributeIndex_t GetSelfIllumPerParticle() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CBaseRendererSource2", "m_nSelfIllumPerParticle"); }
    void SetSelfIllumPerParticle(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nSelfIllumPerParticle", false, value); }
    ParticleOutputBlendMode_t GetOutputBlendMode() const { return GetSchemaValue<ParticleOutputBlendMode_t>(m_ptr, "CBaseRendererSource2", "m_nOutputBlendMode"); }
    void SetOutputBlendMode(ParticleOutputBlendMode_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nOutputBlendMode", false, value); }
    bool GetGammaCorrectVertexColors() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bGammaCorrectVertexColors"); }
    void SetGammaCorrectVertexColors(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bGammaCorrectVertexColors", false, value); }
    bool GetSaturateColorPreAlphaBlend() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bSaturateColorPreAlphaBlend"); }
    void SetSaturateColorPreAlphaBlend(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bSaturateColorPreAlphaBlend", false, value); }
    GCParticleCollectionRendererFloatInput GetAddSelfAmount() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flAddSelfAmount"); }
    void SetAddSelfAmount(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAddSelfAmount", false, value); }
    GCParticleCollectionRendererFloatInput GetDesaturation() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flDesaturation"); }
    void SetDesaturation(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDesaturation", false, value); }
    GCParticleCollectionRendererFloatInput GetOverbrightFactor() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flOverbrightFactor"); }
    void SetOverbrightFactor(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flOverbrightFactor", false, value); }
    int32_t GetHSVShiftControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseRendererSource2", "m_nHSVShiftControlPoint"); }
    void SetHSVShiftControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nHSVShiftControlPoint", false, value); }
    ParticleFogType_t GetFogType() const { return GetSchemaValue<ParticleFogType_t>(m_ptr, "CBaseRendererSource2", "m_nFogType"); }
    void SetFogType(ParticleFogType_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nFogType", false, value); }
    GCParticleCollectionRendererFloatInput GetFogAmount() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flFogAmount"); }
    void SetFogAmount(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFogAmount", false, value); }
    bool GetTintByFOW() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bTintByFOW"); }
    void SetTintByFOW(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bTintByFOW", false, value); }
    bool GetTintByGlobalLight() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bTintByGlobalLight"); }
    void SetTintByGlobalLight(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bTintByGlobalLight", false, value); }
    SpriteCardPerParticleScale_t GetPerParticleAlphaReference() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaReference"); }
    void SetPerParticleAlphaReference(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaReference", false, value); }
    SpriteCardPerParticleScale_t GetPerParticleAlphaRefWindow() const { return GetSchemaValue<SpriteCardPerParticleScale_t>(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaRefWindow"); }
    void SetPerParticleAlphaRefWindow(SpriteCardPerParticleScale_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nPerParticleAlphaRefWindow", false, value); }
    ParticleAlphaReferenceType_t GetAlphaReferenceType() const { return GetSchemaValue<ParticleAlphaReferenceType_t>(m_ptr, "CBaseRendererSource2", "m_nAlphaReferenceType"); }
    void SetAlphaReferenceType(ParticleAlphaReferenceType_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nAlphaReferenceType", false, value); }
    GCParticleCollectionRendererFloatInput GetAlphaReferenceSoftness() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flAlphaReferenceSoftness"); }
    void SetAlphaReferenceSoftness(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flAlphaReferenceSoftness", false, value); }
    GCParticleCollectionRendererFloatInput GetSourceAlphaValueToMapToZero() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToZero"); }
    void SetSourceAlphaValueToMapToZero(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToZero", false, value); }
    GCParticleCollectionRendererFloatInput GetSourceAlphaValueToMapToOne() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToOne"); }
    void SetSourceAlphaValueToMapToOne(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flSourceAlphaValueToMapToOne", false, value); }
    bool GetRefract() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bRefract"); }
    void SetRefract(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bRefract", false, value); }
    bool GetRefractSolid() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bRefractSolid"); }
    void SetRefractSolid(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bRefractSolid", false, value); }
    GCParticleCollectionRendererFloatInput GetRefractAmount() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flRefractAmount"); }
    void SetRefractAmount(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flRefractAmount", false, value); }
    int32_t GetRefractBlurRadius() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseRendererSource2", "m_nRefractBlurRadius"); }
    void SetRefractBlurRadius(int32_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nRefractBlurRadius", false, value); }
    BlurFilterType_t GetRefractBlurType() const { return GetSchemaValue<BlurFilterType_t>(m_ptr, "CBaseRendererSource2", "m_nRefractBlurType"); }
    void SetRefractBlurType(BlurFilterType_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nRefractBlurType", false, value); }
    bool GetOnlyRenderInEffectsBloomPass() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsBloomPass"); }
    void SetOnlyRenderInEffectsBloomPass(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsBloomPass", false, value); }
    bool GetOnlyRenderInEffectsWaterPass() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsWaterPass"); }
    void SetOnlyRenderInEffectsWaterPass(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffectsWaterPass", false, value); }
    bool GetUseMixedResolutionRendering() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bUseMixedResolutionRendering"); }
    void SetUseMixedResolutionRendering(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bUseMixedResolutionRendering", false, value); }
    bool GetOnlyRenderInEffecsGameOverlay() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffecsGameOverlay"); }
    void SetOnlyRenderInEffecsGameOverlay(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bOnlyRenderInEffecsGameOverlay", false, value); }
    std::string GetStencilTestID() const { return GetSchemaValue<char*>(m_ptr, "CBaseRendererSource2", "m_stencilTestID"); }
    void SetStencilTestID(std::string value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_stencilTestID", false, value); }
    bool GetStencilTestExclude() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bStencilTestExclude"); }
    void SetStencilTestExclude(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bStencilTestExclude", false, value); }
    std::string GetStencilWriteID() const { return GetSchemaValue<char*>(m_ptr, "CBaseRendererSource2", "m_stencilWriteID"); }
    void SetStencilWriteID(std::string value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_stencilWriteID", false, value); }
    bool GetWriteStencilOnDepthPass() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthPass"); }
    void SetWriteStencilOnDepthPass(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthPass", false, value); }
    bool GetWriteStencilOnDepthFail() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthFail"); }
    void SetWriteStencilOnDepthFail(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bWriteStencilOnDepthFail", false, value); }
    bool GetReverseZBuffering() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bReverseZBuffering"); }
    void SetReverseZBuffering(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bReverseZBuffering", false, value); }
    bool GetDisableZBuffering() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bDisableZBuffering"); }
    void SetDisableZBuffering(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bDisableZBuffering", false, value); }
    ParticleDepthFeatheringMode_t GetFeatheringMode() const { return GetSchemaValue<ParticleDepthFeatheringMode_t>(m_ptr, "CBaseRendererSource2", "m_nFeatheringMode"); }
    void SetFeatheringMode(ParticleDepthFeatheringMode_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nFeatheringMode", false, value); }
    GCParticleCollectionRendererFloatInput GetFeatheringMinDist() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flFeatheringMinDist"); }
    void SetFeatheringMinDist(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFeatheringMinDist", false, value); }
    GCParticleCollectionRendererFloatInput GetFeatheringMaxDist() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flFeatheringMaxDist"); }
    void SetFeatheringMaxDist(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFeatheringMaxDist", false, value); }
    GCParticleCollectionRendererFloatInput GetFeatheringFilter() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flFeatheringFilter"); }
    void SetFeatheringFilter(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flFeatheringFilter", false, value); }
    GCParticleCollectionRendererFloatInput GetDepthBias() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "CBaseRendererSource2", "m_flDepthBias"); }
    void SetDepthBias(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_flDepthBias", false, value); }
    ParticleSortingChoiceList_t GetSortMethod() const { return GetSchemaValue<ParticleSortingChoiceList_t>(m_ptr, "CBaseRendererSource2", "m_nSortMethod"); }
    void SetSortMethod(ParticleSortingChoiceList_t value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_nSortMethod", false, value); }
    bool GetBlendFramesSeq0() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bBlendFramesSeq0"); }
    void SetBlendFramesSeq0(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bBlendFramesSeq0", false, value); }
    bool GetMaxLuminanceBlendingSequence0() const { return GetSchemaValue<bool>(m_ptr, "CBaseRendererSource2", "m_bMaxLuminanceBlendingSequence0"); }
    void SetMaxLuminanceBlendingSequence0(bool value) { SetSchemaValue(m_ptr, "CBaseRendererSource2", "m_bMaxLuminanceBlendingSequence0", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif