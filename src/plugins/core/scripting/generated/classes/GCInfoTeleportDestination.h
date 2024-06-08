class GCInfoTeleportDestination;

#ifndef _gccinfoteleportdestination_h
#define _gccinfoteleportdestination_h

#include "../../../scripting.h"




class GCInfoTeleportDestination
{
private:
    void *m_ptr;

public:
    GCInfoTeleportDestination() {}
    GCInfoTeleportDestination(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif