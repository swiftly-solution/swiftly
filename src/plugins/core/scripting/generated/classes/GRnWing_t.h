class GRnWing_t;

#ifndef _gcrnwing_t_h
#define _gcrnwing_t_h

#include "../../../scripting.h"




class GRnWing_t
{
private:
    void *m_ptr;

public:
    GRnWing_t() {}
    GRnWing_t(void *ptr) : m_ptr(ptr) {}

    std::vector<int32_t> GetIndex() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnWing_t", "m_nIndex"); std::vector<int32_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetIndex(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnWing_t", "m_nIndex"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnWing_t", "m_nIndex", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif