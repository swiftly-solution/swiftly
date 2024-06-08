class GC_INIT_RemapParticleCountToNamedModelMeshGroupScalar;

#ifndef _gcc_init_remapparticlecounttonamedmodelmeshgroupscalar_h
#define _gcc_init_remapparticlecounttonamedmodelmeshgroupscalar_h

#include "../../../scripting.h"




class GC_INIT_RemapParticleCountToNamedModelMeshGroupScalar
{
private:
    void *m_ptr;

public:
    GC_INIT_RemapParticleCountToNamedModelMeshGroupScalar() {}
    GC_INIT_RemapParticleCountToNamedModelMeshGroupScalar(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif