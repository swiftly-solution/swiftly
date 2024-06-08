class GCParticleInput;

#ifndef _gccparticleinput_h
#define _gccparticleinput_h

#include "../../../scripting.h"




class GCParticleInput
{
private:
    void *m_ptr;

public:
    GCParticleInput() {}
    GCParticleInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif