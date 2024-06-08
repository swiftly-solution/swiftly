class GCServerRagdollTrigger;

#ifndef _gccserverragdolltrigger_h
#define _gccserverragdolltrigger_h

#include "../../../scripting.h"




class GCServerRagdollTrigger
{
private:
    void *m_ptr;

public:
    GCServerRagdollTrigger() {}
    GCServerRagdollTrigger(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif