class GCProductQuantizer;

#ifndef _gccproductquantizer_h
#define _gccproductquantizer_h

#include "../../../scripting.h"


#include "GCVectorQuantizer.h"

class GCProductQuantizer
{
private:
    void *m_ptr;

public:
    GCProductQuantizer() {}
    GCProductQuantizer(void *ptr) : m_ptr(ptr) {}

    std::vector<GCVectorQuantizer> GetSubQuantizers() const { CUtlVector<GCVectorQuantizer>* vec = GetSchemaValue<CUtlVector<GCVectorQuantizer>*>(m_ptr, "CProductQuantizer", "m_subQuantizers"); std::vector<GCVectorQuantizer> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSubQuantizers(std::vector<GCVectorQuantizer> value) { SetSchemaValueCUtlVector<GCVectorQuantizer>(m_ptr, "CProductQuantizer", "m_subQuantizers", false, value); }
    int32_t GetDimensions() const { return GetSchemaValue<int32_t>(m_ptr, "CProductQuantizer", "m_nDimensions"); }
    void SetDimensions(int32_t value) { SetSchemaValue(m_ptr, "CProductQuantizer", "m_nDimensions", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif