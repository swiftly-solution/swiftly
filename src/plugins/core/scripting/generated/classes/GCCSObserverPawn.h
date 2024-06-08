class GCCSObserverPawn;

#ifndef _gcccsobserverpawn_h
#define _gcccsobserverpawn_h

#include "../../../scripting.h"




class GCCSObserverPawn
{
private:
    void *m_ptr;

public:
    GCCSObserverPawn() {}
    GCCSObserverPawn(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif