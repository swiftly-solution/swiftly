class GC_INIT_RemapParticleCountToNamedModelBodyPartScalar;

#ifndef _gcc_init_remapparticlecounttonamedmodelbodypartscalar_h
#define _gcc_init_remapparticlecounttonamedmodelbodypartscalar_h

#include "../../../scripting.h"




class GC_INIT_RemapParticleCountToNamedModelBodyPartScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapParticleCountToNamedModelBodyPartScalar() {}
    GC_INIT_RemapParticleCountToNamedModelBodyPartScalar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif