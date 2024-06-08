class GCVariantDefaultAllocator;

#ifndef _gccvariantdefaultallocator_h
#define _gccvariantdefaultallocator_h

#include "../../../scripting.h"




class GCVariantDefaultAllocator
{
private:
    void *m_ptr;

public:
    GCVariantDefaultAllocator() {}
    GCVariantDefaultAllocator(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif