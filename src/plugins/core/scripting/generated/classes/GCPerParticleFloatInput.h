class GCPerParticleFloatInput;

#ifndef _gccperparticlefloatinput_h
#define _gccperparticlefloatinput_h

#include "../../../scripting.h"




class GCPerParticleFloatInput
{
private:
    void *m_ptr;

public:
    GCPerParticleFloatInput() {}
    GCPerParticleFloatInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif