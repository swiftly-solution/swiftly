class GCPlayer_ItemServices;

#ifndef _gccplayer_itemservices_h
#define _gccplayer_itemservices_h

#include "../../../scripting.h"




class GCPlayer_ItemServices
{
private:
    void *m_ptr;

public:
    GCPlayer_ItemServices() {}
    GCPlayer_ItemServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif