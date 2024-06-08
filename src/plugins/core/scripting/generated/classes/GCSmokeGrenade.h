class GCSmokeGrenade;

#ifndef _gccsmokegrenade_h
#define _gccsmokegrenade_h

#include "../../../scripting.h"




class GCSmokeGrenade
{
private:
    void *m_ptr;

public:
    GCSmokeGrenade() {}
    GCSmokeGrenade(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif