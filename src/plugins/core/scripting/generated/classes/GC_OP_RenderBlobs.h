class GC_OP_RenderBlobs;

#ifndef _gcc_op_renderblobs_h
#define _gcc_op_renderblobs_h

#include "../../../scripting.h"


#include "GCParticleCollectionRendererFloatInput.h"
#include "GMaterialVariable_t.h"

class GC_OP_RenderBlobs
{
private:
    void *m_ptr;

public:
    GC_OP_RenderBlobs() {}
    GC_OP_RenderBlobs(void *ptr) : m_ptr(ptr) {}

    GCParticleCollectionRendererFloatInput GetCubeWidth() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderBlobs", "m_cubeWidth"); }
    void SetCubeWidth(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderBlobs", "m_cubeWidth", false, value); }
    GCParticleCollectionRendererFloatInput GetCutoffRadius() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderBlobs", "m_cutoffRadius"); }
    void SetCutoffRadius(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderBlobs", "m_cutoffRadius", false, value); }
    GCParticleCollectionRendererFloatInput GetRenderRadius() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderBlobs", "m_renderRadius"); }
    void SetRenderRadius(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderBlobs", "m_renderRadius", false, value); }
    uint32_t GetVertexCountKb() const { return GetSchemaValue<uint32_t>(m_ptr, "C_OP_RenderBlobs", "m_nVertexCountKb"); }
    void SetVertexCountKb(uint32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderBlobs", "m_nVertexCountKb", false, value); }
    uint32_t GetIndexCountKb() const { return GetSchemaValue<uint32_t>(m_ptr, "C_OP_RenderBlobs", "m_nIndexCountKb"); }
    void SetIndexCountKb(uint32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderBlobs", "m_nIndexCountKb", false, value); }
    int32_t GetScaleCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderBlobs", "m_nScaleCP"); }
    void SetScaleCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderBlobs", "m_nScaleCP", false, value); }
    std::vector<GMaterialVariable_t> GetMaterialVars() const { CUtlVector<GMaterialVariable_t>* vec = GetSchemaValue<CUtlVector<GMaterialVariable_t>*>(m_ptr, "C_OP_RenderBlobs", "m_MaterialVars"); std::vector<GMaterialVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialVars(std::vector<GMaterialVariable_t> value) { SetSchemaValueCUtlVector<GMaterialVariable_t>(m_ptr, "C_OP_RenderBlobs", "m_MaterialVars", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif