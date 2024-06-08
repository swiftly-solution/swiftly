class GCParticleCollectionBindingInstance;

#ifndef _gccparticlecollectionbindinginstance_h
#define _gccparticlecollectionbindinginstance_h

#include "../../../scripting.h"




class GCParticleCollectionBindingInstance
{
private:
    void *m_ptr;

public:
    GCParticleCollectionBindingInstance() {}
    GCParticleCollectionBindingInstance(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif