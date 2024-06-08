class GEventClientPostSimulate_t;

#ifndef _gceventclientpostsimulate_t_h
#define _gceventclientpostsimulate_t_h

#include "../../../scripting.h"




class GEventClientPostSimulate_t
{
private:
    void *m_ptr;

public:
    GEventClientPostSimulate_t() {}
    GEventClientPostSimulate_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif