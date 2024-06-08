class GCCSObserver_ObserverServices;

#ifndef _gcccsobserver_observerservices_h
#define _gcccsobserver_observerservices_h

#include "../../../scripting.h"




class GCCSObserver_ObserverServices
{
private:
    void *m_ptr;

public:
    GCCSObserver_ObserverServices() {}
    GCCSObserver_ObserverServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif