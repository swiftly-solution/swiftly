class GC_INIT_RemapParticleCountToNamedModelSequenceScalar;

#ifndef _gcc_init_remapparticlecounttonamedmodelsequencescalar_h
#define _gcc_init_remapparticlecounttonamedmodelsequencescalar_h

#include "../../../scripting.h"




class GC_INIT_RemapParticleCountToNamedModelSequenceScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapParticleCountToNamedModelSequenceScalar() {}
    GC_INIT_RemapParticleCountToNamedModelSequenceScalar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif