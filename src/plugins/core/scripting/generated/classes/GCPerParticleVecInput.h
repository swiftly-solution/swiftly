class GCPerParticleVecInput;

#ifndef _gccperparticlevecinput_h
#define _gccperparticlevecinput_h

#include "../../../scripting.h"




class GCPerParticleVecInput
{
private:
    void *m_ptr;

public:
    GCPerParticleVecInput() {}
    GCPerParticleVecInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif