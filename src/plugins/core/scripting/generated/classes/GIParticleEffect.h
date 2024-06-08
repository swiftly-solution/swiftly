class GIParticleEffect;

#ifndef _gciparticleeffect_h
#define _gciparticleeffect_h

#include "../../../scripting.h"




class GIParticleEffect
{
private:
    void *m_ptr;

public:
    GIParticleEffect() {}
    GIParticleEffect(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif