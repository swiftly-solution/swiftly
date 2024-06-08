class GCParticleFunctionForce;

#ifndef _gccparticlefunctionforce_h
#define _gccparticlefunctionforce_h

#include "../../../scripting.h"




class GCParticleFunctionForce
{
private:
    void *m_ptr;

public:
    GCParticleFunctionForce() {}
    GCParticleFunctionForce(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif