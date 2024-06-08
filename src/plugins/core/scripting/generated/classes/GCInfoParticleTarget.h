class GCInfoParticleTarget;

#ifndef _gccinfoparticletarget_h
#define _gccinfoparticletarget_h

#include "../../../scripting.h"




class GCInfoParticleTarget
{
private:
    void *m_ptr;

public:
    GCInfoParticleTarget() {}
    GCInfoParticleTarget(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif