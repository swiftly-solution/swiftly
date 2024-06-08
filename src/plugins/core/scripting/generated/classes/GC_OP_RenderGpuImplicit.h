class GC_OP_RenderGpuImplicit;

#ifndef _gcc_op_rendergpuimplicit_h
#define _gcc_op_rendergpuimplicit_h

#include "../../../scripting.h"


#include "GCParticleCollectionRendererFloatInput.h"

class GC_OP_RenderGpuImplicit
{
private:
    void *m_ptr;

public:
    GC_OP_RenderGpuImplicit() {}
    GC_OP_RenderGpuImplicit(void *ptr) : m_ptr(ptr) {}

    bool GetUsePerParticleRadius() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderGpuImplicit", "m_bUsePerParticleRadius"); }
    void SetUsePerParticleRadius(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_bUsePerParticleRadius", false, value); }
    uint32_t GetVertexCountKb() const { return GetSchemaValue<uint32_t>(m_ptr, "C_OP_RenderGpuImplicit", "m_nVertexCountKb"); }
    void SetVertexCountKb(uint32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_nVertexCountKb", false, value); }
    uint32_t GetIndexCountKb() const { return GetSchemaValue<uint32_t>(m_ptr, "C_OP_RenderGpuImplicit", "m_nIndexCountKb"); }
    void SetIndexCountKb(uint32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_nIndexCountKb", false, value); }
    GCParticleCollectionRendererFloatInput GetGridSize() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderGpuImplicit", "m_fGridSize"); }
    void SetGridSize(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_fGridSize", false, value); }
    GCParticleCollectionRendererFloatInput GetRadiusScale() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderGpuImplicit", "m_fRadiusScale"); }
    void SetRadiusScale(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_fRadiusScale", false, value); }
    GCParticleCollectionRendererFloatInput GetIsosurfaceThreshold() const { return GetSchemaValue<GCParticleCollectionRendererFloatInput>(m_ptr, "C_OP_RenderGpuImplicit", "m_fIsosurfaceThreshold"); }
    void SetIsosurfaceThreshold(GCParticleCollectionRendererFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_fIsosurfaceThreshold", false, value); }
    int32_t GetScaleCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderGpuImplicit", "m_nScaleCP"); }
    void SetScaleCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderGpuImplicit", "m_nScaleCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif