class GCPlayer_FlashlightServices;

#ifndef _gccplayer_flashlightservices_h
#define _gccplayer_flashlightservices_h

#include "../../../scripting.h"




class GCPlayer_FlashlightServices
{
private:
    void *m_ptr;

public:
    GCPlayer_FlashlightServices() {}
    GCPlayer_FlashlightServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif