class GCMelee;

#ifndef _gccmelee_h
#define _gccmelee_h

#include "../../../scripting.h"




class GCMelee
{
private:
    void *m_ptr;

public:
    GCMelee() {}
    GCMelee(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif