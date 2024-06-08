class GCPathParticleRopeAlias_path_particle_rope_clientside;

#ifndef _gccpathparticleropealias_path_particle_rope_clientside_h
#define _gccpathparticleropealias_path_particle_rope_clientside_h

#include "../../../scripting.h"




class GCPathParticleRopeAlias_path_particle_rope_clientside
{
private:
    void *m_ptr;

public:
    GCPathParticleRopeAlias_path_particle_rope_clientside() {}
    GCPathParticleRopeAlias_path_particle_rope_clientside(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif