class GCFiringModeFloat;

#ifndef _gccfiringmodefloat_h
#define _gccfiringmodefloat_h

#include "../../../scripting.h"




class GCFiringModeFloat
{
private:
    void *m_ptr;

public:
    GCFiringModeFloat() {}
    GCFiringModeFloat(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetValues() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CFiringModeFloat", "m_flValues"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValues(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CFiringModeFloat", "m_flValues"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CFiringModeFloat", "m_flValues", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif