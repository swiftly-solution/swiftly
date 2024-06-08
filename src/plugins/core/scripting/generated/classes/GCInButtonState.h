class GCInButtonState;

#ifndef _gccinbuttonstate_h
#define _gccinbuttonstate_h

#include "../../../scripting.h"




class GCInButtonState
{
private:
    void *m_ptr;

public:
    GCInButtonState() {}
    GCInButtonState(void *ptr) : m_ptr(ptr) {}

    std::vector<uint64_t> GetButtonStates() const { uint64_t* outValue = GetSchemaValue<uint64_t*>(m_ptr, "CInButtonState", "m_pButtonStates"); std::vector<uint64_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetButtonStates(std::vector<uint64_t> value) { uint64_t* outValue = GetSchemaValue<uint64_t*>(m_ptr, "CInButtonState", "m_pButtonStates"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInButtonState", "m_pButtonStates", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif