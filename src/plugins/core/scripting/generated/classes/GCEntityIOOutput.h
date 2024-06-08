class GCEntityIOOutput;

#ifndef _gccentityiooutput_h
#define _gccentityiooutput_h

#include "../../../scripting.h"




class GCEntityIOOutput
{
private:
    void *m_ptr;

public:
    GCEntityIOOutput() {}
    GCEntityIOOutput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif