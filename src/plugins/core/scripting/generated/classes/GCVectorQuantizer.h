class GCVectorQuantizer;

#ifndef _gccvectorquantizer_h
#define _gccvectorquantizer_h

#include "../../../scripting.h"




class GCVectorQuantizer
{
private:
    void *m_ptr;

public:
    GCVectorQuantizer() {}
    GCVectorQuantizer(void *ptr) : m_ptr(ptr) {}

    std::vector<float32> GetCentroidVectors() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CVectorQuantizer", "m_centroidVectors"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCentroidVectors(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CVectorQuantizer", "m_centroidVectors", false, value); }
    int32_t GetCentroids() const { return GetSchemaValue<int32_t>(m_ptr, "CVectorQuantizer", "m_nCentroids"); }
    void SetCentroids(int32_t value) { SetSchemaValue(m_ptr, "CVectorQuantizer", "m_nCentroids", false, value); }
    int32_t GetDimensions() const { return GetSchemaValue<int32_t>(m_ptr, "CVectorQuantizer", "m_nDimensions"); }
    void SetDimensions(int32_t value) { SetSchemaValue(m_ptr, "CVectorQuantizer", "m_nDimensions", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif