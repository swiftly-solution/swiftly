class GC_INIT_RandomModelSequence;

#ifndef _gcc_init_randommodelsequence_h
#define _gcc_init_randommodelsequence_h

#include "../../../scripting.h"




class GC_INIT_RandomModelSequence
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomModelSequence() {}
    GC_INIT_RandomModelSequence(void *ptr) : m_ptr(ptr) {}

    std::string GetActivityName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_RandomModelSequence", "m_ActivityName"); }
    void SetActivityName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_RandomModelSequence", "m_ActivityName", false, value); }
    std::string GetSequenceName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_RandomModelSequence", "m_SequenceName"); }
    void SetSequenceName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_RandomModelSequence", "m_SequenceName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif