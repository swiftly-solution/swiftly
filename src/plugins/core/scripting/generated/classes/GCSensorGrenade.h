class GCSensorGrenade;

#ifndef _gccsensorgrenade_h
#define _gccsensorgrenade_h

#include "../../../scripting.h"




class GCSensorGrenade
{
private:
    void *m_ptr;

public:
    GCSensorGrenade() {}
    GCSensorGrenade(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif