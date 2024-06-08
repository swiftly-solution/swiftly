class GCRangeInt;

#ifndef _gccrangeint_h
#define _gccrangeint_h

#include "../../../scripting.h"




class GCRangeInt
{
private:
    void *m_ptr;

public:
    GCRangeInt() {}
    GCRangeInt(void *ptr) : m_ptr(ptr) {}

    std::vector<int32_t> GetValue() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CRangeInt", "m_pValue"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValue(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CRangeInt", "m_pValue"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CRangeInt", "m_pValue", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif