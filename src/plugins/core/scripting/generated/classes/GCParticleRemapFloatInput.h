class GCParticleRemapFloatInput;

#ifndef _gccparticleremapfloatinput_h
#define _gccparticleremapfloatinput_h

#include "../../../scripting.h"




class GCParticleRemapFloatInput
{
private:
    void *m_ptr;

public:
    GCParticleRemapFloatInput() {}
    GCParticleRemapFloatInput(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif