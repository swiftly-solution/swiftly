class GCTriggerOnce;

#ifndef _gcctriggeronce_h
#define _gcctriggeronce_h

#include "../../../scripting.h"




class GCTriggerOnce
{
private:
    void *m_ptr;

public:
    GCTriggerOnce() {}
    GCTriggerOnce(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif