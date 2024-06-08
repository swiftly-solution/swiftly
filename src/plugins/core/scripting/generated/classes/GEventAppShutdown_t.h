class GEventAppShutdown_t;

#ifndef _gceventappshutdown_t_h
#define _gceventappshutdown_t_h

#include "../../../scripting.h"




class GEventAppShutdown_t
{
private:
    void *m_ptr;

public:
    GEventAppShutdown_t() {}
    GEventAppShutdown_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetDummy0() const { return GetSchemaValue<int32_t>(m_ptr, "EventAppShutdown_t", "m_nDummy0"); }
    void SetDummy0(int32_t value) { SetSchemaValue(m_ptr, "EventAppShutdown_t", "m_nDummy0", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif