class GCParticleFunctionOperator;

#ifndef _gccparticlefunctionoperator_h
#define _gccparticlefunctionoperator_h

#include "../../../scripting.h"




class GCParticleFunctionOperator
{
private:
    void *m_ptr;

public:
    GCParticleFunctionOperator() {}
    GCParticleFunctionOperator(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif