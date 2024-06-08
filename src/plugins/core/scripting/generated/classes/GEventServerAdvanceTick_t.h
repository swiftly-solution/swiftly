class GEventServerAdvanceTick_t;

#ifndef _gceventserveradvancetick_t_h
#define _gceventserveradvancetick_t_h

#include "../../../scripting.h"




class GEventServerAdvanceTick_t
{
private:
    void *m_ptr;

public:
    GEventServerAdvanceTick_t() {}
    GEventServerAdvanceTick_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif