class GCParentConstraint;

#ifndef _gccparentconstraint_h
#define _gccparentconstraint_h

#include "../../../scripting.h"




class GCParentConstraint
{
private:
    void *m_ptr;

public:
    GCParentConstraint() {}
    GCParentConstraint(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif