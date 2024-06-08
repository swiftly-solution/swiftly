class GCMorphBundleData;

#ifndef _gccmorphbundledata_h
#define _gccmorphbundledata_h

#include "../../../scripting.h"




class GCMorphBundleData
{
private:
    void *m_ptr;

public:
    GCMorphBundleData() {}
    GCMorphBundleData(void *ptr) : m_ptr(ptr) {}

    float GetULeftSrc() const { return GetSchemaValue<float>(m_ptr, "CMorphBundleData", "m_flULeftSrc"); }
    void SetULeftSrc(float value) { SetSchemaValue(m_ptr, "CMorphBundleData", "m_flULeftSrc", false, value); }
    float GetVTopSrc() const { return GetSchemaValue<float>(m_ptr, "CMorphBundleData", "m_flVTopSrc"); }
    void SetVTopSrc(float value) { SetSchemaValue(m_ptr, "CMorphBundleData", "m_flVTopSrc", false, value); }
    std::vector<float32> GetOffsets() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMorphBundleData", "m_offsets"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOffsets(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CMorphBundleData", "m_offsets", false, value); }
    std::vector<float32> GetRanges() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMorphBundleData", "m_ranges"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRanges(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CMorphBundleData", "m_ranges", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif