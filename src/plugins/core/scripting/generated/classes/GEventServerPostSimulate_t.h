class GEventServerPostSimulate_t;

#ifndef _gceventserverpostsimulate_t_h
#define _gceventserverpostsimulate_t_h

#include "../../../scripting.h"




class GEventServerPostSimulate_t
{
private:
    void *m_ptr;

public:
    GEventServerPostSimulate_t() {}
    GEventServerPostSimulate_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif