class Glocksound_t;

#ifndef _gclocksound_t_h
#define _gclocksound_t_h

#include "../../../scripting.h"




class Glocksound_t
{
private:
    void *m_ptr;

public:
    Glocksound_t() {}
    Glocksound_t(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetLockedSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "locksound_t", "sLockedSound"); }
    void SetLockedSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "locksound_t", "sLockedSound", true, value); }
    CUtlSymbolLarge GetUnlockedSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "locksound_t", "sUnlockedSound"); }
    void SetUnlockedSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "locksound_t", "sUnlockedSound", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif