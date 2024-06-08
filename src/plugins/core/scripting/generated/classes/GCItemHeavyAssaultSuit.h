class GCItemHeavyAssaultSuit;

#ifndef _gccitemheavyassaultsuit_h
#define _gccitemheavyassaultsuit_h

#include "../../../scripting.h"




class GCItemHeavyAssaultSuit
{
private:
    void *m_ptr;

public:
    GCItemHeavyAssaultSuit() {}
    GCItemHeavyAssaultSuit(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif