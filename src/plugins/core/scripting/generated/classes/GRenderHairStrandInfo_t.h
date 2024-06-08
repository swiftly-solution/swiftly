class GRenderHairStrandInfo_t;

#ifndef _gcrenderhairstrandinfo_t_h
#define _gcrenderhairstrandinfo_t_h

#include "../../../scripting.h"




class GRenderHairStrandInfo_t
{
private:
    void *m_ptr;

public:
    GRenderHairStrandInfo_t() {}
    GRenderHairStrandInfo_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint32_t> GetGuideHairIndices_nSurfaceTriIndex() const { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nGuideHairIndices_nSurfaceTriIndex"); std::vector<uint32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetGuideHairIndices_nSurfaceTriIndex(std::vector<uint32_t> value) { uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nGuideHairIndices_nSurfaceTriIndex"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nGuideHairIndices_nSurfaceTriIndex", true, outValue); }
    std::vector<uint16_t> GetGuideBary_vBaseBary() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vGuideBary_vBaseBary"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetGuideBary_vBaseBary(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vGuideBary_vBaseBary"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_vGuideBary_vBaseBary", true, outValue); }
    std::vector<uint16_t> GetRootOffset_flLengthScale() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vRootOffset_flLengthScale"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetRootOffset_flLengthScale(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vRootOffset_flLengthScale"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_vRootOffset_flLengthScale", true, outValue); }
    std::vector<uint16_t> GetPackedBaseUv() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedBaseUv"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetPackedBaseUv(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedBaseUv"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nPackedBaseUv", true, outValue); }
    uint32_t GetPackedSurfaceNormalOs() const { return GetSchemaValue<uint32_t>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceNormalOs"); }
    void SetPackedSurfaceNormalOs(uint32_t value) { SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceNormalOs", true, value); }
    uint32_t GetPackedSurfaceTangentOs() const { return GetSchemaValue<uint32_t>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceTangentOs"); }
    void SetPackedSurfaceTangentOs(uint32_t value) { SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceTangentOs", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif