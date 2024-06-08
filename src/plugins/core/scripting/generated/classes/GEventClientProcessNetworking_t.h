class GEventClientProcessNetworking_t;

#ifndef _gceventclientprocessnetworking_t_h
#define _gceventclientprocessnetworking_t_h

#include "../../../scripting.h"




class GEventClientProcessNetworking_t
{
private:
    void *m_ptr;

public:
    GEventClientProcessNetworking_t() {}
    GEventClientProcessNetworking_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif