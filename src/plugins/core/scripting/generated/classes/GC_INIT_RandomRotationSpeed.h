class GC_INIT_RandomRotationSpeed;

#ifndef _gcc_init_randomrotationspeed_h
#define _gcc_init_randomrotationspeed_h

#include "../../../scripting.h"




class GC_INIT_RandomRotationSpeed
{
private:
    void *m_ptr;

public:
    GC_INIT_RandomRotationSpeed() {}
    GC_INIT_RandomRotationSpeed(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif