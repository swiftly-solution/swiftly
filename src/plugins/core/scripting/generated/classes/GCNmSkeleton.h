class GCNmSkeleton;

#ifndef _gccnmskeleton_h
#define _gccnmskeleton_h

#include "../../../scripting.h"




class GCNmSkeleton
{
private:
    void *m_ptr;

public:
    GCNmSkeleton() {}
    GCNmSkeleton(void *ptr) : m_ptr(ptr) {}

    std::vector<int32> GetParentIndices() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CNmSkeleton", "m_parentIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetParentIndices(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CNmSkeleton", "m_parentIndices", false, value); }
    int32_t GetNumBonesToSampleAtLowLOD() const { return GetSchemaValue<int32_t>(m_ptr, "CNmSkeleton", "m_numBonesToSampleAtLowLOD"); }
    void SetNumBonesToSampleAtLowLOD(int32_t value) { SetSchemaValue(m_ptr, "CNmSkeleton", "m_numBonesToSampleAtLowLOD", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif