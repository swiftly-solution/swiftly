class GCPlayer_UseServices;

#ifndef _gccplayer_useservices_h
#define _gccplayer_useservices_h

#include "../../../scripting.h"




class GCPlayer_UseServices
{
private:
    void *m_ptr;

public:
    GCPlayer_UseServices() {}
    GCPlayer_UseServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif