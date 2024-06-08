class GCSingleplayRules;

#ifndef _gccsingleplayrules_h
#define _gccsingleplayrules_h

#include "../../../scripting.h"




class GCSingleplayRules
{
private:
    void *m_ptr;

public:
    GCSingleplayRules() {}
    GCSingleplayRules(void *ptr) : m_ptr(ptr) {}

    bool GetSinglePlayerGameEnding() const { return GetSchemaValue<bool>(m_ptr, "CSingleplayRules", "m_bSinglePlayerGameEnding"); }
    void SetSinglePlayerGameEnding(bool value) { SetSchemaValue(m_ptr, "CSingleplayRules", "m_bSinglePlayerGameEnding", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif