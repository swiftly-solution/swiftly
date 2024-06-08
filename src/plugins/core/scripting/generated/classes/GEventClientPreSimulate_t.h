class GEventClientPreSimulate_t;

#ifndef _gceventclientpresimulate_t_h
#define _gceventclientpresimulate_t_h

#include "../../../scripting.h"




class GEventClientPreSimulate_t
{
private:
    void *m_ptr;

public:
    GEventClientPreSimulate_t() {}
    GEventClientPreSimulate_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif