class GCBreachCharge;

#ifndef _gccbreachcharge_h
#define _gccbreachcharge_h

#include "../../../scripting.h"




class GCBreachCharge
{
private:
    void *m_ptr;

public:
    GCBreachCharge() {}
    GCBreachCharge(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif