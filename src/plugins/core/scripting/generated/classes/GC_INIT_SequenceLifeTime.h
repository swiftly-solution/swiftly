class GC_INIT_SequenceLifeTime;

#ifndef _gcc_init_sequencelifetime_h
#define _gcc_init_sequencelifetime_h

#include "../../../scripting.h"




class GC_INIT_SequenceLifeTime
{
private:
    void *m_ptr;

public:
    GC_INIT_SequenceLifeTime() {}
    GC_INIT_SequenceLifeTime(void *ptr) : m_ptr(ptr) {}

    float GetFramerate() const { return GetSchemaValue<float>(m_ptr, "C_INIT_SequenceLifeTime", "m_flFramerate"); }
    void SetFramerate(float value) { SetSchemaValue(m_ptr, "C_INIT_SequenceLifeTime", "m_flFramerate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif