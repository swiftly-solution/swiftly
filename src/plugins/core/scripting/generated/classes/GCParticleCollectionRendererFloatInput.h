class GCParticleCollectionRendererFloatInput;

#ifndef _gccparticlecollectionrendererfloatinput_h
#define _gccparticlecollectionrendererfloatinput_h

#include "../../../scripting.h"




class GCParticleCollectionRendererFloatInput
{
private:
    void *m_ptr;

public:
    GCParticleCollectionRendererFloatInput() {}
    GCParticleCollectionRendererFloatInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif