class GExtraVertexStreamOverride_t;

#ifndef _gcextravertexstreamoverride_t_h
#define _gcextravertexstreamoverride_t_h

#include "../../../scripting.h"

#include "../types/GMeshDrawPrimitiveFlags_t.h"
#include "GCRenderBufferBinding.h"

class GExtraVertexStreamOverride_t
{
private:
    void *m_ptr;

public:
    GExtraVertexStreamOverride_t() {}
    GExtraVertexStreamOverride_t(void *ptr) : m_ptr(ptr) {}

    uint32_t GetSubSceneObject() const { return GetSchemaValue<uint32_t>(m_ptr, "ExtraVertexStreamOverride_t", "m_nSubSceneObject"); }
    void SetSubSceneObject(uint32_t value) { SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_nSubSceneObject", true, value); }
    uint32_t GetDrawCallIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "ExtraVertexStreamOverride_t", "m_nDrawCallIndex"); }
    void SetDrawCallIndex(uint32_t value) { SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_nDrawCallIndex", true, value); }
    MeshDrawPrimitiveFlags_t GetAdditionalMeshDrawPrimitiveFlags() const { return GetSchemaValue<MeshDrawPrimitiveFlags_t>(m_ptr, "ExtraVertexStreamOverride_t", "m_nAdditionalMeshDrawPrimitiveFlags"); }
    void SetAdditionalMeshDrawPrimitiveFlags(MeshDrawPrimitiveFlags_t value) { SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_nAdditionalMeshDrawPrimitiveFlags", true, value); }
    GCRenderBufferBinding GetExtraBufferBinding() const { return GetSchemaValue<GCRenderBufferBinding>(m_ptr, "ExtraVertexStreamOverride_t", "m_extraBufferBinding"); }
    void SetExtraBufferBinding(GCRenderBufferBinding value) { SetSchemaValue(m_ptr, "ExtraVertexStreamOverride_t", "m_extraBufferBinding", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif