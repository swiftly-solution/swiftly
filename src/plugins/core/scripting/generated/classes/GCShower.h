class GCShower;

#ifndef _gccshower_h
#define _gccshower_h

#include "../../../scripting.h"




class GCShower
{
private:
    void *m_ptr;

public:
    GCShower() {}
    GCShower(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif