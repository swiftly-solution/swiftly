class GEventServerPostAdvanceTick_t;

#ifndef _gceventserverpostadvancetick_t_h
#define _gceventserverpostadvancetick_t_h

#include "../../../scripting.h"




class GEventServerPostAdvanceTick_t
{
private:
    void *m_ptr;

public:
    GEventServerPostAdvanceTick_t() {}
    GEventServerPostAdvanceTick_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif