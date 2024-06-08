class GCParticleCollectionFloatInput;

#ifndef _gccparticlecollectionfloatinput_h
#define _gccparticlecollectionfloatinput_h

#include "../../../scripting.h"




class GCParticleCollectionFloatInput
{
private:
    void *m_ptr;

public:
    GCParticleCollectionFloatInput() {}
    GCParticleCollectionFloatInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif