class GEventClientPauseSimulate_t;

#ifndef _gceventclientpausesimulate_t_h
#define _gceventclientpausesimulate_t_h

#include "../../../scripting.h"




class GEventClientPauseSimulate_t
{
private:
    void *m_ptr;

public:
    GEventClientPauseSimulate_t() {}
    GEventClientPauseSimulate_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif