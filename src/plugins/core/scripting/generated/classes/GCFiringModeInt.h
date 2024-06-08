class GCFiringModeInt;

#ifndef _gccfiringmodeint_h
#define _gccfiringmodeint_h

#include "../../../scripting.h"




class GCFiringModeInt
{
private:
    void *m_ptr;

public:
    GCFiringModeInt() {}
    GCFiringModeInt(void *ptr) : m_ptr(ptr) {}

    std::vector<int32_t> GetValues() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CFiringModeInt", "m_nValues"); std::vector<int32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValues(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CFiringModeInt", "m_nValues"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFiringModeInt", "m_nValues", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif