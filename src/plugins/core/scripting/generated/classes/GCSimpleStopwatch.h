class GCSimpleStopwatch;

#ifndef _gccsimplestopwatch_h
#define _gccsimplestopwatch_h

#include "../../../scripting.h"




class GCSimpleStopwatch
{
private:
    void *m_ptr;

public:
    GCSimpleStopwatch() {}
    GCSimpleStopwatch(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif