class GC_OP_RenderModels;

#ifndef _gcc_op_rendermodels_h
#define _gcc_op_rendermodels_h

#include "../../../scripting.h"

#include "../types/GRenderModelSubModelFieldType_t.h"
#include "../types/GParticleColorBlendType_t.h"
#include "GModelReference_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleVecInput.h"
#include "GCPerParticleFloatInput.h"
#include "GMaterialVariable_t.h"
#include "GCParticleModelInput.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_RenderModels
{
private:
    void *m_ptr;

public:
    GC_OP_RenderModels() {}
    GC_OP_RenderModels(void *ptr) : m_ptr(ptr) {}

    bool GetOnlyRenderInEffectsBloomPass() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bOnlyRenderInEffectsBloomPass"); }
    void SetOnlyRenderInEffectsBloomPass(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bOnlyRenderInEffectsBloomPass", false, value); }
    bool GetOnlyRenderInEffectsWaterPass() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bOnlyRenderInEffectsWaterPass"); }
    void SetOnlyRenderInEffectsWaterPass(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bOnlyRenderInEffectsWaterPass", false, value); }
    bool GetUseMixedResolutionRendering() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bUseMixedResolutionRendering"); }
    void SetUseMixedResolutionRendering(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bUseMixedResolutionRendering", false, value); }
    bool GetOnlyRenderInEffecsGameOverlay() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bOnlyRenderInEffecsGameOverlay"); }
    void SetOnlyRenderInEffecsGameOverlay(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bOnlyRenderInEffecsGameOverlay", false, value); }
    std::vector<GModelReference_t> GetModelList() const { CUtlVector<GModelReference_t>* vec = GetSchemaValue<CUtlVector<GModelReference_t>*>(m_ptr, "C_OP_RenderModels", "m_ModelList"); std::vector<GModelReference_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetModelList(std::vector<GModelReference_t> value) { SetSchemaValueCUtlVector<GModelReference_t>(m_ptr, "C_OP_RenderModels", "m_ModelList", false, value); }
    GParticleAttributeIndex_t GetBodyGroupField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderModels", "m_nBodyGroupField"); }
    void SetBodyGroupField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nBodyGroupField", false, value); }
    GParticleAttributeIndex_t GetSubModelField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderModels", "m_nSubModelField"); }
    void SetSubModelField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nSubModelField", false, value); }
    bool GetIgnoreNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bIgnoreNormal"); }
    void SetIgnoreNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bIgnoreNormal", false, value); }
    bool GetOrientZ() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bOrientZ"); }
    void SetOrientZ(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bOrientZ", false, value); }
    bool GetCenterOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bCenterOffset"); }
    void SetCenterOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bCenterOffset", false, value); }
    GCPerParticleVecInput GetLocalOffset() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_RenderModels", "m_vecLocalOffset"); }
    void SetLocalOffset(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_vecLocalOffset", false, value); }
    GCPerParticleVecInput GetLocalRotation() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_RenderModels", "m_vecLocalRotation"); }
    void SetLocalRotation(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_vecLocalRotation", false, value); }
    bool GetIgnoreRadius() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bIgnoreRadius"); }
    void SetIgnoreRadius(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bIgnoreRadius", false, value); }
    int32_t GetModelScaleCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderModels", "m_nModelScaleCP"); }
    void SetModelScaleCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nModelScaleCP", false, value); }
    GCPerParticleVecInput GetComponentScale() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_OP_RenderModels", "m_vecComponentScale"); }
    void SetComponentScale(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_vecComponentScale", false, value); }
    bool GetLocalScale() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bLocalScale"); }
    void SetLocalScale(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bLocalScale", false, value); }
    int32_t GetSizeCullBloat() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderModels", "m_nSizeCullBloat"); }
    void SetSizeCullBloat(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nSizeCullBloat", false, value); }
    bool GetAnimated() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bAnimated"); }
    void SetAnimated(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bAnimated", false, value); }
    GCPerParticleFloatInput GetAnimationRate() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderModels", "m_flAnimationRate"); }
    void SetAnimationRate(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_flAnimationRate", false, value); }
    bool GetScaleAnimationRate() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bScaleAnimationRate"); }
    void SetScaleAnimationRate(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bScaleAnimationRate", false, value); }
    bool GetForceLoopingAnimation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bForceLoopingAnimation"); }
    void SetForceLoopingAnimation(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bForceLoopingAnimation", false, value); }
    bool GetResetAnimOnStop() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bResetAnimOnStop"); }
    void SetResetAnimOnStop(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bResetAnimOnStop", false, value); }
    bool GetManualAnimFrame() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bManualAnimFrame"); }
    void SetManualAnimFrame(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bManualAnimFrame", false, value); }
    GParticleAttributeIndex_t GetAnimationScaleField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderModels", "m_nAnimationScaleField"); }
    void SetAnimationScaleField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nAnimationScaleField", false, value); }
    GParticleAttributeIndex_t GetAnimationField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderModels", "m_nAnimationField"); }
    void SetAnimationField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nAnimationField", false, value); }
    GParticleAttributeIndex_t GetManualFrameField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderModels", "m_nManualFrameField"); }
    void SetManualFrameField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nManualFrameField", false, value); }
    std::string GetActivityName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RenderModels", "m_ActivityName"); }
    void SetActivityName(std::string value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_ActivityName", false, value); }
    std::string GetSequenceName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RenderModels", "m_SequenceName"); }
    void SetSequenceName(std::string value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_SequenceName", false, value); }
    bool GetEnableClothSimulation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bEnableClothSimulation"); }
    void SetEnableClothSimulation(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bEnableClothSimulation", false, value); }
    std::string GetClothEffectName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RenderModels", "m_ClothEffectName"); }
    void SetClothEffectName(std::string value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_ClothEffectName", false, value); }
    bool GetOverrideTranslucentMaterials() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bOverrideTranslucentMaterials"); }
    void SetOverrideTranslucentMaterials(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bOverrideTranslucentMaterials", false, value); }
    GCPerParticleFloatInput GetSkin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderModels", "m_nSkin"); }
    void SetSkin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nSkin", false, value); }
    std::vector<GMaterialVariable_t> GetMaterialVars() const { CUtlVector<GMaterialVariable_t>* vec = GetSchemaValue<CUtlVector<GMaterialVariable_t>*>(m_ptr, "C_OP_RenderModels", "m_MaterialVars"); std::vector<GMaterialVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialVars(std::vector<GMaterialVariable_t> value) { SetSchemaValueCUtlVector<GMaterialVariable_t>(m_ptr, "C_OP_RenderModels", "m_MaterialVars", false, value); }
    GCPerParticleFloatInput GetManualModelSelection() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderModels", "m_flManualModelSelection"); }
    void SetManualModelSelection(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_flManualModelSelection", false, value); }
    GCParticleModelInput GetModelInput() const { return GetSchemaValue<GCParticleModelInput>(m_ptr, "C_OP_RenderModels", "m_modelInput"); }
    void SetModelInput(GCParticleModelInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_modelInput", false, value); }
    int32_t GetLOD() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderModels", "m_nLOD"); }
    void SetLOD(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nLOD", false, value); }
    std::string GetEconSlotName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RenderModels", "m_EconSlotName"); }
    void SetEconSlotName(std::string value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_EconSlotName", false, value); }
    bool GetOriginalModel() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bOriginalModel"); }
    void SetOriginalModel(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bOriginalModel", false, value); }
    bool GetSuppressTint() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bSuppressTint"); }
    void SetSuppressTint(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bSuppressTint", false, value); }
    RenderModelSubModelFieldType_t GetSubModelFieldType() const { return GetSchemaValue<RenderModelSubModelFieldType_t>(m_ptr, "C_OP_RenderModels", "m_nSubModelFieldType"); }
    void SetSubModelFieldType(RenderModelSubModelFieldType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nSubModelFieldType", false, value); }
    bool GetDisableShadows() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bDisableShadows"); }
    void SetDisableShadows(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bDisableShadows", false, value); }
    bool GetDisableDepthPrepass() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bDisableDepthPrepass"); }
    void SetDisableDepthPrepass(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bDisableDepthPrepass", false, value); }
    bool GetAcceptsDecals() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bAcceptsDecals"); }
    void SetAcceptsDecals(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bAcceptsDecals", false, value); }
    bool GetForceDrawInterlevedWithSiblings() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bForceDrawInterlevedWithSiblings"); }
    void SetForceDrawInterlevedWithSiblings(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bForceDrawInterlevedWithSiblings", false, value); }
    bool GetDoNotDrawInParticlePass() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bDoNotDrawInParticlePass"); }
    void SetDoNotDrawInParticlePass(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bDoNotDrawInParticlePass", false, value); }
    bool GetAllowApproximateTransforms() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderModels", "m_bAllowApproximateTransforms"); }
    void SetAllowApproximateTransforms(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_bAllowApproximateTransforms", false, value); }
    std::string GetRenderAttribute() const { return GetSchemaValue<char*>(m_ptr, "C_OP_RenderModels", "m_szRenderAttribute"); }
    void SetRenderAttribute(std::string value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_szRenderAttribute", false, value); }
    GCParticleCollectionFloatInput GetRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderModels", "m_flRadiusScale"); }
    void SetRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_flRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetAlphaScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderModels", "m_flAlphaScale"); }
    void SetAlphaScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_flAlphaScale", false, value); }
    GCParticleCollectionFloatInput GetRollScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderModels", "m_flRollScale"); }
    void SetRollScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_flRollScale", false, value); }
    GParticleAttributeIndex_t GetAlpha2Field() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderModels", "m_nAlpha2Field"); }
    void SetAlpha2Field(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nAlpha2Field", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderModels", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderModels", "m_nColorBlendType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif