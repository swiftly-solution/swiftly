class GC_INIT_RandomSecondSequence;

#ifndef _gcc_init_randomsecondsequence_h
#define _gcc_init_randomsecondsequence_h

#include "../../../scripting.h"




class GC_INIT_RandomSecondSequence
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomSecondSequence() {}
    GC_INIT_RandomSecondSequence(void *ptr) : m_ptr(ptr) {}

    int32_t GetSequenceMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomSecondSequence", "m_nSequenceMin"); }
    void SetSequenceMin(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomSecondSequence", "m_nSequenceMin", false, value); }
    int32_t GetSequenceMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_RandomSecondSequence", "m_nSequenceMax"); }
    void SetSequenceMax(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_RandomSecondSequence", "m_nSequenceMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif