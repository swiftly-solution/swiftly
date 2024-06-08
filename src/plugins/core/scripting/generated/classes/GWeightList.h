class GWeightList;

#ifndef _gcweightlist_h
#define _gcweightlist_h

#include "../../../scripting.h"




class GWeightList
{
private:
    void *m_ptr;

public:
    GWeightList() {}
    GWeightList(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "WeightList", "m_name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "WeightList", "m_name", false, value); }
    std::vector<float32> GetWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "WeightList", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "WeightList", "m_weights", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif