class GCRangeFloat;

#ifndef _gccrangefloat_h
#define _gccrangefloat_h

#include "../../../scripting.h"




class GCRangeFloat
{
private:
    void *m_ptr;

public:
    GCRangeFloat() {}
    GCRangeFloat(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetValue() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CRangeFloat", "m_pValue"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValue(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CRangeFloat", "m_pValue"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CRangeFloat", "m_pValue", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif