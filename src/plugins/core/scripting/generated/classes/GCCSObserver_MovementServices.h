class GCCSObserver_MovementServices;

#ifndef _gcccsobserver_movementservices_h
#define _gcccsobserver_movementservices_h

#include "../../../scripting.h"




class GCCSObserver_MovementServices
{
private:
    void *m_ptr;

public:
    GCCSObserver_MovementServices() {}
    GCCSObserver_MovementServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif