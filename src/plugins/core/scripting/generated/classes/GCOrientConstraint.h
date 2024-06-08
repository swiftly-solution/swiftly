class GCOrientConstraint;

#ifndef _gccorientconstraint_h
#define _gccorientconstraint_h

#include "../../../scripting.h"




class GCOrientConstraint
{
private:
    void *m_ptr;

public:
    GCOrientConstraint() {}
    GCOrientConstraint(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif