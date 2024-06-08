class GCPointConstraint;

#ifndef _gccpointconstraint_h
#define _gccpointconstraint_h

#include "../../../scripting.h"




class GCPointConstraint
{
private:
    void *m_ptr;

public:
    GCPointConstraint() {}
    GCPointConstraint(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif