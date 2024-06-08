class GCCSObserver_ViewModelServices;

#ifndef _gcccsobserver_viewmodelservices_h
#define _gcccsobserver_viewmodelservices_h

#include "../../../scripting.h"




class GCCSObserver_ViewModelServices
{
private:
    void *m_ptr;

public:
    GCCSObserver_ViewModelServices() {}
    GCCSObserver_ViewModelServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif