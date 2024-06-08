class GCStaticPoseCacheBuilder;

#ifndef _gccstaticposecachebuilder_h
#define _gccstaticposecachebuilder_h

#include "../../../scripting.h"




class GCStaticPoseCacheBuilder
{
private:
    void *m_ptr;

public:
    GCStaticPoseCacheBuilder() {}
    GCStaticPoseCacheBuilder(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif