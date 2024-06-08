class GCHandleDummy;

#ifndef _gcchandledummy_h
#define _gcchandledummy_h

#include "../../../scripting.h"




class GCHandleDummy
{
private:
    void *m_ptr;

public:
    GCHandleDummy() {}
    GCHandleDummy(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif