class GC_OP_RenderCables;

#ifndef _gcc_op_rendercables_h
#define _gcc_op_rendercables_h

#include "../../../scripting.h"

#include "../types/GParticleColorBlendType_t.h"
#include "../types/GTextureRepetitionMode_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCParticleTransformInput.h"
#include "GVecInputMaterialVariable_t.h"
#include "GMaterialVariable_t.h"

class GC_OP_RenderCables
{
private:
    void *m_ptr;

public:
    GC_OP_RenderCables() {}
    GC_OP_RenderCables(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionFloatInput GetRadiusScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flRadiusScale"); }
    void SetRadiusScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flRadiusScale", false, value); }
    GCParticleCollectionFloatInput GetAlphaScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flAlphaScale"); }
    void SetAlphaScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flAlphaScale", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderCables", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_nColorBlendType", false, value); }
    TextureRepetitionMode_t GetTextureRepetitionMode() const { return GetSchemaValue<TextureRepetitionMode_t>(m_ptr, "C_OP_RenderCables", "m_nTextureRepetitionMode"); }
    void SetTextureRepetitionMode(TextureRepetitionMode_t value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_nTextureRepetitionMode", false, value); }
    GCParticleCollectionFloatInput GetTextureRepeatsPerSegment() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flTextureRepeatsPerSegment"); }
    void SetTextureRepeatsPerSegment(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flTextureRepeatsPerSegment", false, value); }
    GCParticleCollectionFloatInput GetTextureRepeatsCircumference() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flTextureRepeatsCircumference"); }
    void SetTextureRepeatsCircumference(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flTextureRepeatsCircumference", false, value); }
    GCParticleCollectionFloatInput GetColorMapOffsetV() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flColorMapOffsetV"); }
    void SetColorMapOffsetV(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flColorMapOffsetV", false, value); }
    GCParticleCollectionFloatInput GetColorMapOffsetU() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flColorMapOffsetU"); }
    void SetColorMapOffsetU(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flColorMapOffsetU", false, value); }
    GCParticleCollectionFloatInput GetNormalMapOffsetV() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flNormalMapOffsetV"); }
    void SetNormalMapOffsetV(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flNormalMapOffsetV", false, value); }
    GCParticleCollectionFloatInput GetNormalMapOffsetU() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderCables", "m_flNormalMapOffsetU"); }
    void SetNormalMapOffsetU(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flNormalMapOffsetU", false, value); }
    bool GetDrawCableCaps() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderCables", "m_bDrawCableCaps"); }
    void SetDrawCableCaps(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_bDrawCableCaps", false, value); }
    float GetCapRoundness() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderCables", "m_flCapRoundness"); }
    void SetCapRoundness(float value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flCapRoundness", false, value); }
    float GetCapOffsetAmount() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderCables", "m_flCapOffsetAmount"); }
    void SetCapOffsetAmount(float value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flCapOffsetAmount", false, value); }
    float GetTessScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderCables", "m_flTessScale"); }
    void SetTessScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_flTessScale", false, value); }
    int32_t GetMinTesselation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderCables", "m_nMinTesselation"); }
    void SetMinTesselation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_nMinTesselation", false, value); }
    int32_t GetMaxTesselation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderCables", "m_nMaxTesselation"); }
    void SetMaxTesselation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_nMaxTesselation", false, value); }
    int32_t GetRoundness() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderCables", "m_nRoundness"); }
    void SetRoundness(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_nRoundness", false, value); }
    GCParticleTransformInput GetLightingTransform() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_OP_RenderCables", "m_LightingTransform"); }
    void SetLightingTransform(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_OP_RenderCables", "m_LightingTransform", false, value); }
    std::vector<GVecInputMaterialVariable_t> GetMaterialVecVars() const { CUtlVector<GVecInputMaterialVariable_t>* vec = GetSchemaValue<CUtlVector<GVecInputMaterialVariable_t>*>(m_ptr, "C_OP_RenderCables", "m_MaterialVecVars"); std::vector<GVecInputMaterialVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialVecVars(std::vector<GVecInputMaterialVariable_t> value) { SetSchemaValueCUtlVector<GVecInputMaterialVariable_t>(m_ptr, "C_OP_RenderCables", "m_MaterialVecVars", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif