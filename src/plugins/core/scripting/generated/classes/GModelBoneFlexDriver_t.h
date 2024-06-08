class GModelBoneFlexDriver_t;

#ifndef _gcmodelboneflexdriver_t_h
#define _gcmodelboneflexdriver_t_h

#include "../../../scripting.h"


#include "GModelBoneFlexDriverControl_t.h"

class GModelBoneFlexDriver_t
{
private:
    void *m_ptr;

public:
    GModelBoneFlexDriver_t() {}
    GModelBoneFlexDriver_t(void *ptr) : m_ptr(ptr) {}

    CUtlString GetBoneName() const { return GetSchemaValue<CUtlString>(m_ptr, "ModelBoneFlexDriver_t", "m_boneName"); }
    void SetBoneName(CUtlString value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriver_t", "m_boneName", true, value); }
    uint32_t GetBoneNameToken() const { return GetSchemaValue<uint32_t>(m_ptr, "ModelBoneFlexDriver_t", "m_boneNameToken"); }
    void SetBoneNameToken(uint32_t value) { SetSchemaValue(m_ptr, "ModelBoneFlexDriver_t", "m_boneNameToken", true, value); }
    std::vector<GModelBoneFlexDriverControl_t> GetControls() const { CUtlVector<GModelBoneFlexDriverControl_t>* vec = GetSchemaValue<CUtlVector<GModelBoneFlexDriverControl_t>*>(m_ptr, "ModelBoneFlexDriver_t", "m_controls"); std::vector<GModelBoneFlexDriverControl_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetControls(std::vector<GModelBoneFlexDriverControl_t> value) { SetSchemaValueCUtlVector<GModelBoneFlexDriverControl_t>(m_ptr, "ModelBoneFlexDriver_t", "m_controls", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif