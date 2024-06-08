class GCInfoPlayerStart;

#ifndef _gccinfoplayerstart_h
#define _gccinfoplayerstart_h

#include "../../../scripting.h"




class GCInfoPlayerStart
{
private:
    void *m_ptr;

public:
    GCInfoPlayerStart() {}
    GCInfoPlayerStart(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CInfoPlayerStart", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CInfoPlayerStart", "m_bDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif