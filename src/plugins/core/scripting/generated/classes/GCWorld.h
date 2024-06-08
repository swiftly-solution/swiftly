class GCWorld;

#ifndef _gccworld_h
#define _gccworld_h

#include "../../../scripting.h"




class GCWorld
{
private:
    void *m_ptr;

public:
    GCWorld() {}
    GCWorld(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif