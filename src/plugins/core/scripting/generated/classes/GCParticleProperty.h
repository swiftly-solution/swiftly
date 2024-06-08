class GCParticleProperty;

#ifndef _gccparticleproperty_h
#define _gccparticleproperty_h

#include "../../../scripting.h"




class GCParticleProperty
{
private:
    void *m_ptr;

public:
    GCParticleProperty() {}
    GCParticleProperty(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif