class GCMorphRectData;

#ifndef _gccmorphrectdata_h
#define _gccmorphrectdata_h

#include "../../../scripting.h"


#include "GCMorphBundleData.h"

class GCMorphRectData
{
private:
    void *m_ptr;

public:
    GCMorphRectData() {}
    GCMorphRectData(void *ptr) : m_ptr(ptr) {}

    int16_t GetXLeftDst() const { return GetSchemaValue<int16_t>(m_ptr, "CMorphRectData", "m_nXLeftDst"); }
    void SetXLeftDst(int16_t value) { SetSchemaValue(m_ptr, "CMorphRectData", "m_nXLeftDst", false, value); }
    int16_t GetYTopDst() const { return GetSchemaValue<int16_t>(m_ptr, "CMorphRectData", "m_nYTopDst"); }
    void SetYTopDst(int16_t value) { SetSchemaValue(m_ptr, "CMorphRectData", "m_nYTopDst", false, value); }
    float GetUWidthSrc() const { return GetSchemaValue<float>(m_ptr, "CMorphRectData", "m_flUWidthSrc"); }
    void SetUWidthSrc(float value) { SetSchemaValue(m_ptr, "CMorphRectData", "m_flUWidthSrc", false, value); }
    float GetVHeightSrc() const { return GetSchemaValue<float>(m_ptr, "CMorphRectData", "m_flVHeightSrc"); }
    void SetVHeightSrc(float value) { SetSchemaValue(m_ptr, "CMorphRectData", "m_flVHeightSrc", false, value); }
    std::vector<GCMorphBundleData> GetBundleDatas() const { CUtlVector<GCMorphBundleData>* vec = GetSchemaValue<CUtlVector<GCMorphBundleData>*>(m_ptr, "CMorphRectData", "m_bundleDatas"); std::vector<GCMorphBundleData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBundleDatas(std::vector<GCMorphBundleData> value) { SetSchemaValueCUtlVector<GCMorphBundleData>(m_ptr, "CMorphRectData", "m_bundleDatas", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif