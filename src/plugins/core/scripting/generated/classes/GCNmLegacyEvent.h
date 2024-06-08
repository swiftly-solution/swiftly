class GCNmLegacyEvent;

#ifndef _gccnmlegacyevent_h
#define _gccnmlegacyevent_h

#include "../../../scripting.h"




class GCNmLegacyEvent
{
private:
    void *m_ptr;

public:
    GCNmLegacyEvent() {}
    GCNmLegacyEvent(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif