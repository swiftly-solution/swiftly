class GCMorphData;

#ifndef _gccmorphdata_h
#define _gccmorphdata_h

#include "../../../scripting.h"


#include "GCMorphRectData.h"

class GCMorphData
{
private:
    void *m_ptr;

public:
    GCMorphData() {}
    GCMorphData(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CMorphData", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CMorphData", "m_name", false, value); }
    std::vector<GCMorphRectData> GetMorphRectDatas() const { CUtlVector<GCMorphRectData>* vec = GetSchemaValue<CUtlVector<GCMorphRectData>*>(m_ptr, "CMorphData", "m_morphRectDatas"); std::vector<GCMorphRectData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphRectDatas(std::vector<GCMorphRectData> value) { SetSchemaValueCUtlVector<GCMorphRectData>(m_ptr, "CMorphData", "m_morphRectDatas", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif