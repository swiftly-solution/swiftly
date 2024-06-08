class GCPlayer_WaterServices;

#ifndef _gccplayer_waterservices_h
#define _gccplayer_waterservices_h

#include "../../../scripting.h"




class GCPlayer_WaterServices
{
private:
    void *m_ptr;

public:
    GCPlayer_WaterServices() {}
    GCPlayer_WaterServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif