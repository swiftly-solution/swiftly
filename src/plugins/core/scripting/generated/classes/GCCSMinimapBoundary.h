class GCCSMinimapBoundary;

#ifndef _gcccsminimapboundary_h
#define _gcccsminimapboundary_h

#include "../../../scripting.h"




class GCCSMinimapBoundary
{
private:
    void *m_ptr;

public:
    GCCSMinimapBoundary() {}
    GCCSMinimapBoundary(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif