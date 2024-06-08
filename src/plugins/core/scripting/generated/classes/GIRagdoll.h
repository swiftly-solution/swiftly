class GIRagdoll;

#ifndef _gciragdoll_h
#define _gciragdoll_h

#include "../../../scripting.h"




class GIRagdoll
{
private:
    void *m_ptr;

public:
    GIRagdoll() {}
    GIRagdoll(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif