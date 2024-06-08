class GCNmBoneMask;

#ifndef _gccnmbonemask_h
#define _gccnmbonemask_h

#include "../../../scripting.h"


#include "GCNmBoneMask.h"

class GCNmBoneMask
{
private:
    void *m_ptr;

public:
    GCNmBoneMask() {}
    GCNmBoneMask(void *ptr) : m_ptr(ptr) {}

    GCNmBoneMask GetWeightInfo() const { return GetSchemaValue<GCNmBoneMask>(m_ptr, "CNmBoneMask", "m_weightInfo"); }
    void SetWeightInfo(GCNmBoneMask value) { SetSchemaValue(m_ptr, "CNmBoneMask", "m_weightInfo", false, value); }
    std::vector<float32> GetWeights() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CNmBoneMask", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWeights(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CNmBoneMask", "m_weights", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif