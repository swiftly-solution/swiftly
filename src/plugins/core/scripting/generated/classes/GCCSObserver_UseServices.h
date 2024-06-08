class GCCSObserver_UseServices;

#ifndef _gcccsobserver_useservices_h
#define _gcccsobserver_useservices_h

#include "../../../scripting.h"




class GCCSObserver_UseServices
{
private:
    void *m_ptr;

public:
    GCCSObserver_UseServices() {}
    GCCSObserver_UseServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif