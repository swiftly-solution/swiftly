class GCInfoTargetServerOnly;

#ifndef _gccinfotargetserveronly_h
#define _gccinfotargetserveronly_h

#include "../../../scripting.h"




class GCInfoTargetServerOnly
{
private:
    void *m_ptr;

public:
    GCInfoTargetServerOnly() {}
    GCInfoTargetServerOnly(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif