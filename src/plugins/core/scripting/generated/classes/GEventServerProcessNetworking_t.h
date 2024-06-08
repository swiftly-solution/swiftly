class GEventServerProcessNetworking_t;

#ifndef _gceventserverprocessnetworking_t_h
#define _gceventserverprocessnetworking_t_h

#include "../../../scripting.h"




class GEventServerProcessNetworking_t
{
private:
    void *m_ptr;

public:
    GEventServerProcessNetworking_t() {}
    GEventServerProcessNetworking_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif