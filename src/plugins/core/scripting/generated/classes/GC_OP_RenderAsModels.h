class GC_OP_RenderAsModels;

#ifndef _gcc_op_renderasmodels_h
#define _gcc_op_renderasmodels_h

#include "../../../scripting.h"


#include "GModelReference_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RenderAsModels
{
private:
    void *m_ptr;

public:
    GC_OP_RenderAsModels() {}
    GC_OP_RenderAsModels(void *ptr) : m_ptr(ptr) {}

    std::vector<GModelReference_t> GetModelList() const { CUtlVector<GModelReference_t>* vec = GetSchemaValue<CUtlVector<GModelReference_t>*>(m_ptr, "C_OP_RenderAsModels", "m_ModelList"); std::vector<GModelReference_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetModelList(std::vector<GModelReference_t> value) { SetSchemaValueCUtlVector<GModelReference_t>(m_ptr, "C_OP_RenderAsModels", "m_ModelList", false, value); }
    float GetModelScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderAsModels", "m_flModelScale"); }
    void SetModelScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_flModelScale", false, value); }
    bool GetFitToModelSize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderAsModels", "m_bFitToModelSize"); }
    void SetFitToModelSize(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_bFitToModelSize", false, value); }
    bool GetNonUniformScaling() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderAsModels", "m_bNonUniformScaling"); }
    void SetNonUniformScaling(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_bNonUniformScaling", false, value); }
    GParticleAttributeIndex_t GetXAxisScalingAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderAsModels", "m_nXAxisScalingAttribute"); }
    void SetXAxisScalingAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_nXAxisScalingAttribute", false, value); }
    GParticleAttributeIndex_t GetYAxisScalingAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderAsModels", "m_nYAxisScalingAttribute"); }
    void SetYAxisScalingAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_nYAxisScalingAttribute", false, value); }
    GParticleAttributeIndex_t GetZAxisScalingAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderAsModels", "m_nZAxisScalingAttribute"); }
    void SetZAxisScalingAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_nZAxisScalingAttribute", false, value); }
    int32_t GetSizeCullBloat() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderAsModels", "m_nSizeCullBloat"); }
    void SetSizeCullBloat(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderAsModels", "m_nSizeCullBloat", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif