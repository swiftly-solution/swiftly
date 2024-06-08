class GCFilterLOS;

#ifndef _gccfilterlos_h
#define _gccfilterlos_h

#include "../../../scripting.h"




class GCFilterLOS
{
private:
    void *m_ptr;

public:
    GCFilterLOS() {}
    GCFilterLOS(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif