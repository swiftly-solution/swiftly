class GCMaterialDrawDescriptor;

#ifndef _gccmaterialdrawdescriptor_h
#define _gccmaterialdrawdescriptor_h

#include "../../../scripting.h"

#include "../types/GRenderPrimitiveType_t.h"
#include "GCRenderBufferBinding.h"

class GCMaterialDrawDescriptor
{
private:
    void *m_ptr;

public:
    GCMaterialDrawDescriptor() {}
    GCMaterialDrawDescriptor(void *ptr) : m_ptr(ptr) {}

    float GetUvDensity() const { return GetSchemaValue<float>(m_ptr, "CMaterialDrawDescriptor", "m_flUvDensity"); }
    void SetUvDensity(float value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_flUvDensity", false, value); }
    Vector GetTintColor() const { return GetSchemaValue<Vector>(m_ptr, "CMaterialDrawDescriptor", "m_vTintColor"); }
    void SetTintColor(Vector value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_vTintColor", false, value); }
    float GetAlpha() const { return GetSchemaValue<float>(m_ptr, "CMaterialDrawDescriptor", "m_flAlpha"); }
    void SetAlpha(float value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_flAlpha", false, value); }
    uint32_t GetFirstMeshlet() const { return GetSchemaValue<uint32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nFirstMeshlet"); }
    void SetFirstMeshlet(uint32_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nFirstMeshlet", false, value); }
    uint16_t GetNumMeshlets() const { return GetSchemaValue<uint16_t>(m_ptr, "CMaterialDrawDescriptor", "m_nNumMeshlets"); }
    void SetNumMeshlets(uint16_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nNumMeshlets", false, value); }
    RenderPrimitiveType_t GetPrimitiveType() const { return GetSchemaValue<RenderPrimitiveType_t>(m_ptr, "CMaterialDrawDescriptor", "m_nPrimitiveType"); }
    void SetPrimitiveType(RenderPrimitiveType_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nPrimitiveType", false, value); }
    int32_t GetBaseVertex() const { return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nBaseVertex"); }
    void SetBaseVertex(int32_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nBaseVertex", false, value); }
    int32_t GetVertexCount() const { return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nVertexCount"); }
    void SetVertexCount(int32_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nVertexCount", false, value); }
    int32_t GetStartIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nStartIndex"); }
    void SetStartIndex(int32_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nStartIndex", false, value); }
    int32_t GetIndexCount() const { return GetSchemaValue<int32_t>(m_ptr, "CMaterialDrawDescriptor", "m_nIndexCount"); }
    void SetIndexCount(int32_t value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_nIndexCount", false, value); }
    GCRenderBufferBinding GetIndexBuffer() const { return GetSchemaValue<GCRenderBufferBinding>(m_ptr, "CMaterialDrawDescriptor", "m_indexBuffer"); }
    void SetIndexBuffer(GCRenderBufferBinding value) { SetSchemaValue(m_ptr, "CMaterialDrawDescriptor", "m_indexBuffer", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif