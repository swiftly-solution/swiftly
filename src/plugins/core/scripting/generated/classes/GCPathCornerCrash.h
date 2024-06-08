class GCPathCornerCrash;

#ifndef _gccpathcornercrash_h
#define _gccpathcornercrash_h

#include "../../../scripting.h"




class GCPathCornerCrash
{
private:
    void *m_ptr;

public:
    GCPathCornerCrash() {}
    GCPathCornerCrash(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif