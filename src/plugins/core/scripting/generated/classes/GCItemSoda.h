class GCItemSoda;

#ifndef _gccitemsoda_h
#define _gccitemsoda_h

#include "../../../scripting.h"




class GCItemSoda
{
private:
    void *m_ptr;

public:
    GCItemSoda() {}
    GCItemSoda(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif