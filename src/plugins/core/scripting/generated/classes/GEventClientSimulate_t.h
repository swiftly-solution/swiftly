class GEventClientSimulate_t;

#ifndef _gceventclientsimulate_t_h
#define _gceventclientsimulate_t_h

#include "../../../scripting.h"




class GEventClientSimulate_t
{
private:
    void *m_ptr;

public:
    GEventClientSimulate_t() {}
    GEventClientSimulate_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif