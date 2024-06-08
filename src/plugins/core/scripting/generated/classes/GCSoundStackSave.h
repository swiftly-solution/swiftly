class GCSoundStackSave;

#ifndef _gccsoundstacksave_h
#define _gccsoundstacksave_h

#include "../../../scripting.h"




class GCSoundStackSave
{
private:
    void *m_ptr;

public:
    GCSoundStackSave() {}
    GCSoundStackSave(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetStackName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundStackSave", "m_iszStackName"); }
    void SetStackName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundStackSave", "m_iszStackName", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif