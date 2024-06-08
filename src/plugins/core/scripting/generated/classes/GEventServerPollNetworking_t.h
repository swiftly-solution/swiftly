class GEventServerPollNetworking_t;

#ifndef _gceventserverpollnetworking_t_h
#define _gceventserverpollnetworking_t_h

#include "../../../scripting.h"




class GEventServerPollNetworking_t
{
private:
    void *m_ptr;

public:
    GEventServerPollNetworking_t() {}
    GEventServerPollNetworking_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif