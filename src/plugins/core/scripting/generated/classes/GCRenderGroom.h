class GCRenderGroom;

#ifndef _gccrendergroom_h
#define _gccrendergroom_h

#include "../../../scripting.h"


#include "GRenderHairStrandInfo_t.h"

class GCRenderGroom
{
private:
    void *m_ptr;

public:
    GCRenderGroom() {}
    GCRenderGroom(void *ptr) : m_ptr(ptr) {}

    std::vector<GRenderHairStrandInfo_t> GetHairs() const { CUtlVector<GRenderHairStrandInfo_t>* vec = GetSchemaValue<CUtlVector<GRenderHairStrandInfo_t>*>(m_ptr, "CRenderGroom", "m_hairs"); std::vector<GRenderHairStrandInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetHairs(std::vector<GRenderHairStrandInfo_t> value) { SetSchemaValueCUtlVector<GRenderHairStrandInfo_t>(m_ptr, "CRenderGroom", "m_hairs", false, value); }
    int32_t GetSegmentsPerHairStrand() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nSegmentsPerHairStrand"); }
    void SetSegmentsPerHairStrand(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nSegmentsPerHairStrand", false, value); }
    int32_t GetGuideHairCount() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nGuideHairCount"); }
    void SetGuideHairCount(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nGuideHairCount", false, value); }
    int32_t GetHairCount() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nHairCount"); }
    void SetHairCount(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nHairCount", false, value); }
    int32_t GetGroomGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nGroomGroupID"); }
    void SetGroomGroupID(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nGroomGroupID", false, value); }
    int32_t GetAttachBoneIdx() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nAttachBoneIdx"); }
    void SetAttachBoneIdx(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nAttachBoneIdx", false, value); }
    int32_t GetAttachMeshIdx() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nAttachMeshIdx"); }
    void SetAttachMeshIdx(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nAttachMeshIdx", false, value); }
    int32_t GetAttachMeshDrawCallIdx() const { return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nAttachMeshDrawCallIdx"); }
    void SetAttachMeshDrawCallIdx(int32_t value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_nAttachMeshDrawCallIdx", false, value); }
    float GetSumOfAllHairLengths() const { return GetSchemaValue<float>(m_ptr, "CRenderGroom", "m_flSumOfAllHairLengths"); }
    void SetSumOfAllHairLengths(float value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_flSumOfAllHairLengths", false, value); }
    bool GetEnableSimulation() const { return GetSchemaValue<bool>(m_ptr, "CRenderGroom", "m_bEnableSimulation"); }
    void SetEnableSimulation(bool value) { SetSchemaValue(m_ptr, "CRenderGroom", "m_bEnableSimulation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif