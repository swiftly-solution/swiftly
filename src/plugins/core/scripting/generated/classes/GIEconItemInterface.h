class GIEconItemInterface;

#ifndef _gcieconiteminterface_h
#define _gcieconiteminterface_h

#include "../../../scripting.h"




class GIEconItemInterface
{
private:
    void *m_ptr;

public:
    GIEconItemInterface() {}
    GIEconItemInterface(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif