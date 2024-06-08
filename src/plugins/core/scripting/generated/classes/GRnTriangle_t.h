class GRnTriangle_t;

#ifndef _gcrntriangle_t_h
#define _gcrntriangle_t_h

#include "../../../scripting.h"




class GRnTriangle_t
{
private:
    void *m_ptr;

public:
    GRnTriangle_t() {}
    GRnTriangle_t(void *ptr) : m_ptr(ptr) {}

    std::vector<int32_t> GetIndex() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnTriangle_t", "m_nIndex"); std::vector<int32_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetIndex(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "RnTriangle_t", "m_nIndex"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnTriangle_t", "m_nIndex", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif