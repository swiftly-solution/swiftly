class GFeTreeChildren_t;

#ifndef _gcfetreechildren_t_h
#define _gcfetreechildren_t_h

#include "../../../scripting.h"




class GFeTreeChildren_t
{
private:
    void *m_ptr;

public:
    GFeTreeChildren_t() {}
    GFeTreeChildren_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint16_t> GetChild() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTreeChildren_t", "nChild"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetChild(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTreeChildren_t", "nChild"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTreeChildren_t", "nChild", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif