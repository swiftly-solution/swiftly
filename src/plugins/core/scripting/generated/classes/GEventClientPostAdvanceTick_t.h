class GEventClientPostAdvanceTick_t;

#ifndef _gceventclientpostadvancetick_t_h
#define _gceventclientpostadvancetick_t_h

#include "../../../scripting.h"




class GEventClientPostAdvanceTick_t
{
private:
    void *m_ptr;

public:
    GEventClientPostAdvanceTick_t() {}
    GEventClientPostAdvanceTick_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif