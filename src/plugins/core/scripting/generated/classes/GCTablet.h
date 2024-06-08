class GCTablet;

#ifndef _gcctablet_h
#define _gcctablet_h

#include "../../../scripting.h"




class GCTablet
{
private:
    void *m_ptr;

public:
    GCTablet() {}
    GCTablet(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif