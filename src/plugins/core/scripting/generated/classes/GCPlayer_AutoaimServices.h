class GCPlayer_AutoaimServices;

#ifndef _gccplayer_autoaimservices_h
#define _gccplayer_autoaimservices_h

#include "../../../scripting.h"




class GCPlayer_AutoaimServices
{
private:
    void *m_ptr;

public:
    GCPlayer_AutoaimServices() {}
    GCPlayer_AutoaimServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif