class GFeVertexMapDesc_t;

#ifndef _gcfevertexmapdesc_t_h
#define _gcfevertexmapdesc_t_h

#include "../../../scripting.h"




class GFeVertexMapDesc_t
{
private:
    void *m_ptr;

public:
    GFeVertexMapDesc_t() {}
    GFeVertexMapDesc_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "FeVertexMapDesc_t", "sName"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "sName", true, value); }
    uint32_t GetNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nNameHash"); }
    void SetNameHash(uint32_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nNameHash", true, value); }
    uint32_t GetColor() const { return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nColor"); }
    void SetColor(uint32_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nColor", true, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nFlags", true, value); }
    uint16_t GetVertexBase() const { return GetSchemaValue<uint16_t>(m_ptr, "FeVertexMapDesc_t", "nVertexBase"); }
    void SetVertexBase(uint16_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nVertexBase", true, value); }
    uint16_t GetVertexCount() const { return GetSchemaValue<uint16_t>(m_ptr, "FeVertexMapDesc_t", "nVertexCount"); }
    void SetVertexCount(uint16_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nVertexCount", true, value); }
    uint32_t GetMapOffset() const { return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nMapOffset"); }
    void SetMapOffset(uint32_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nMapOffset", true, value); }
    uint32_t GetNodeListOffset() const { return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapDesc_t", "nNodeListOffset"); }
    void SetNodeListOffset(uint32_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nNodeListOffset", true, value); }
    Vector GetCenterOfMass() const { return GetSchemaValue<Vector>(m_ptr, "FeVertexMapDesc_t", "vCenterOfMass"); }
    void SetCenterOfMass(Vector value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "vCenterOfMass", true, value); }
    float GetVolumetricSolveStrength() const { return GetSchemaValue<float>(m_ptr, "FeVertexMapDesc_t", "flVolumetricSolveStrength"); }
    void SetVolumetricSolveStrength(float value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "flVolumetricSolveStrength", true, value); }
    int16_t GetScaleSourceNode() const { return GetSchemaValue<int16_t>(m_ptr, "FeVertexMapDesc_t", "nScaleSourceNode"); }
    void SetScaleSourceNode(int16_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nScaleSourceNode", true, value); }
    uint16_t GetNodeListCount() const { return GetSchemaValue<uint16_t>(m_ptr, "FeVertexMapDesc_t", "nNodeListCount"); }
    void SetNodeListCount(uint16_t value) { SetSchemaValue(m_ptr, "FeVertexMapDesc_t", "nNodeListCount", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif