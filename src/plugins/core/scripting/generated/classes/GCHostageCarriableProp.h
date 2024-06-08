class GCHostageCarriableProp;

#ifndef _gcchostagecarriableprop_h
#define _gcchostagecarriableprop_h

#include "../../../scripting.h"




class GCHostageCarriableProp
{
private:
    void *m_ptr;

public:
    GCHostageCarriableProp() {}
    GCHostageCarriableProp(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif