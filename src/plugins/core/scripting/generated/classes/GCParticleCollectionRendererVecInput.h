class GCParticleCollectionRendererVecInput;

#ifndef _gccparticlecollectionrenderervecinput_h
#define _gccparticlecollectionrenderervecinput_h

#include "../../../scripting.h"




class GCParticleCollectionRendererVecInput
{
private:
    void *m_ptr;

public:
    GCParticleCollectionRendererVecInput() {}
    GCParticleCollectionRendererVecInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif