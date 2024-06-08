class GCCSPlayer_DamageReactServices;

#ifndef _gcccsplayer_damagereactservices_h
#define _gcccsplayer_damagereactservices_h

#include "../../../scripting.h"




class GCCSPlayer_DamageReactServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_DamageReactServices() {}
    GCCSPlayer_DamageReactServices(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif