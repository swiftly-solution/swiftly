class GFeVertexMapBuild_t;

#ifndef _gcfevertexmapbuild_t_h
#define _gcfevertexmapbuild_t_h

#include "../../../scripting.h"




class GFeVertexMapBuild_t
{
private:
    void *m_ptr;

public:
    GFeVertexMapBuild_t() {}
    GFeVertexMapBuild_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetVertexMapName() const { return GetSchemaValue<CUtlString>(m_ptr, "FeVertexMapBuild_t", "m_VertexMapName"); }
    void SetVertexMapName(CUtlString value) { SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_VertexMapName", true, value); }
    uint32_t GetNameHash() const { return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapBuild_t", "m_nNameHash"); }
    void SetNameHash(uint32_t value) { SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_nNameHash", true, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "FeVertexMapBuild_t", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_Color", true, value); }
    float GetVolumetricSolveStrength() const { return GetSchemaValue<float>(m_ptr, "FeVertexMapBuild_t", "m_flVolumetricSolveStrength"); }
    void SetVolumetricSolveStrength(float value) { SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_flVolumetricSolveStrength", true, value); }
    int32_t GetScaleSourceNode() const { return GetSchemaValue<int32_t>(m_ptr, "FeVertexMapBuild_t", "m_nScaleSourceNode"); }
    void SetScaleSourceNode(int32_t value) { SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_nScaleSourceNode", true, value); }
    std::vector<float32> GetWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "FeVertexMapBuild_t", "m_Weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "FeVertexMapBuild_t", "m_Weights", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif