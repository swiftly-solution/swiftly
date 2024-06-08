class GEventModInitialized_t;

#ifndef _gceventmodinitialized_t_h
#define _gceventmodinitialized_t_h

#include "../../../scripting.h"




class GEventModInitialized_t
{
private:
    void *m_ptr;

public:
    GEventModInitialized_t() {}
    GEventModInitialized_t(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif