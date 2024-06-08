class GCItemAssaultSuit;

#ifndef _gccitemassaultsuit_h
#define _gccitemassaultsuit_h

#include "../../../scripting.h"




class GCItemAssaultSuit
{
private:
    void *m_ptr;

public:
    GCItemAssaultSuit() {}
    GCItemAssaultSuit(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif