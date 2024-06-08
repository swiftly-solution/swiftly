class GC_OP_RenderProjected;

#ifndef _gcc_op_renderprojected_h
#define _gcc_op_renderprojected_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendType_t.h"
#include "GRenderProjectedMaterial_t.h"
#include "GCPerParticleFloatInput.h"
#include "GMaterialVariable_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderProjected
{
private:
    void *m_ptr;

public:
    GC_OP_RenderProjected() {}
    GC_OP_RenderProjected(void *ptr) : m_ptr(ptr) {}

    bool GetProjectCharacter() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderProjected", "m_bProjectCharacter"); }
    void SetProjectCharacter(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_bProjectCharacter", false, value); }
    bool GetProjectWorld() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderProjected", "m_bProjectWorld"); }
    void SetProjectWorld(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_bProjectWorld", false, value); }
    bool GetProjectWater() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderProjected", "m_bProjectWater"); }
    void SetProjectWater(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_bProjectWater", false, value); }
    bool GetFlipHorizontal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderProjected", "m_bFlipHorizontal"); }
    void SetFlipHorizontal(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_bFlipHorizontal", false, value); }
    bool GetEnableProjectedDepthControls() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderProjected", "m_bEnableProjectedDepthControls"); }
    void SetEnableProjectedDepthControls(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_bEnableProjectedDepthControls", false, value); }
    float GetMinProjectionDepth() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderProjected", "m_flMinProjectionDepth"); }
    void SetMinProjectionDepth(float value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flMinProjectionDepth", false, value); }
    float GetMaxProjectionDepth() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderProjected", "m_flMaxProjectionDepth"); }
    void SetMaxProjectionDepth(float value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flMaxProjectionDepth", false, value); }
    std::vector<GRenderProjectedMaterial_t> GetProjectedMaterials() const { CUtlVector<GRenderProjectedMaterial_t>* vec = GetSchemaValue<CUtlVector<GRenderProjectedMaterial_t>*>(m_ptr, "C_OP_RenderProjected", "m_vecProjectedMaterials"); std::vector<GRenderProjectedMaterial_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetProjectedMaterials(std::vector<GRenderProjectedMaterial_t> value) { SetSchemaValueCUtlVector<GRenderProjectedMaterial_t>(m_ptr, "C_OP_RenderProjected", "m_vecProjectedMaterials", false, value); }
    GCPerParticleFloatInput GetMaterialSelection() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderProjected", "m_flMaterialSelection"); }
    void SetMaterialSelection(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flMaterialSelection", false, value); }
    float GetAnimationTimeScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderProjected", "m_flAnimationTimeScale"); }
    void SetAnimationTimeScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flAnimationTimeScale", false, value); }
    bool GetOrientToNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderProjected", "m_bOrientToNormal"); }
    void SetOrientToNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_bOrientToNormal", false, value); }
    std::vector<GMaterialVariable_t> GetMaterialVars() const { CUtlVector<GMaterialVariable_t>* vec = GetSchemaValue<CUtlVector<GMaterialVariable_t>*>(m_ptr, "C_OP_RenderProjected", "m_MaterialVars"); std::vector<GMaterialVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialVars(std::vector<GMaterialVariable_t> value) { SetSchemaValueCUtlVector<GMaterialVariable_t>(m_ptr, "C_OP_RenderProjected", "m_MaterialVars", false, value); }
    GCParticleCollectionFloatInput GetRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderProjected", "m_flRadiusScale"); }
    void SetRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetAlphaScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderProjected", "m_flAlphaScale"); }
    void SetAlphaScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flAlphaScale", false, value); }
    GCParticleCollectionFloatInput GetRollScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderProjected", "m_flRollScale"); }
    void SetRollScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_flRollScale", false, value); }
    GParticleAttributeIndex_t GetAlpha2Field() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderProjected", "m_nAlpha2Field"); }
    void SetAlpha2Field(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_nAlpha2Field", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderProjected", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderProjected", "m_nColorBlendType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif