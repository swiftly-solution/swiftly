class GEventServerSimulate_t;

#ifndef _gceventserversimulate_t_h
#define _gceventserversimulate_t_h

#include "../../../scripting.h"




class GEventServerSimulate_t
{
private:
    void *m_ptr;

public:
    GEventServerSimulate_t() {}
    GEventServerSimulate_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif