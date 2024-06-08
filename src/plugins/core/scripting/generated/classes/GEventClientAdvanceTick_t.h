class GEventClientAdvanceTick_t;

#ifndef _gceventclientadvancetick_t_h
#define _gceventclientadvancetick_t_h

#include "../../../scripting.h"




class GEventClientAdvanceTick_t
{
private:
    void *m_ptr;

public:
    GEventClientAdvanceTick_t() {}
    GEventClientAdvanceTick_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif