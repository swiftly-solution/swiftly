class GCNavHullPresetVData;

#ifndef _gccnavhullpresetvdata_h
#define _gccnavhullpresetvdata_h

#include "../../../scripting.h"




class GCNavHullPresetVData
{
private:
    void *m_ptr;

public:
    GCNavHullPresetVData() {}
    GCNavHullPresetVData(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlString> GetNavHulls() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CNavHullPresetVData", "m_vecNavHulls"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNavHulls(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CNavHullPresetVData", "m_vecNavHulls", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif