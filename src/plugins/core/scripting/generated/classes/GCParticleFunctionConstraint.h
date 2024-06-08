class GCParticleFunctionConstraint;

#ifndef _gccparticlefunctionconstraint_h
#define _gccparticlefunctionconstraint_h

#include "../../../scripting.h"




class GCParticleFunctionConstraint
{
private:
    void *m_ptr;

public:
    GCParticleFunctionConstraint() {}
    GCParticleFunctionConstraint(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif