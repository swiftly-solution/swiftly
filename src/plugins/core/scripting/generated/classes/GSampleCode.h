class GSampleCode;

#ifndef _gcsamplecode_h
#define _gcsamplecode_h

#include "../../../scripting.h"




class GSampleCode
{
private:
    void *m_ptr;

public:
    GSampleCode() {}
    GSampleCode(void *ptr) : m_ptr(ptr) {}

    std::vector<uint8_t> GetSubCode() const { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "SampleCode", "m_subCode"); std::vector<uint8_t> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSubCode(std::vector<uint8_t> value) { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "SampleCode", "m_subCode"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SampleCode", "m_subCode", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif