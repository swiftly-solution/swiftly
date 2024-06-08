class GIParticleCollection;

#ifndef _gciparticlecollection_h
#define _gciparticlecollection_h

#include "../../../scripting.h"




class GIParticleCollection
{
private:
    void *m_ptr;

public:
    GIParticleCollection() {}
    GIParticleCollection(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif