class GCPlayer_ViewModelServices;

#ifndef _gccplayer_viewmodelservices_h
#define _gccplayer_viewmodelservices_h

#include "../../../scripting.h"




class GCPlayer_ViewModelServices
{
private:
    void *m_ptr;

public:
    GCPlayer_ViewModelServices() {}
    GCPlayer_ViewModelServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif