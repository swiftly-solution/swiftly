class GC_OP_CollideWithParentParticles;

#ifndef _gcc_op_collidewithparentparticles_h
#define _gcc_op_collidewithparentparticles_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_OP_CollideWithParentParticles
{
private:
    void *m_ptr;

public:
    GC_OP_CollideWithParentParticles() {}
    GC_OP_CollideWithParentParticles(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetParentRadiusScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CollideWithParentParticles", "m_flParentRadiusScale"); }
    void SetParentRadiusScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CollideWithParentParticles", "m_flParentRadiusScale", false, value); }
    GCPerParticleFloatInput GetRadiusScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CollideWithParentParticles", "m_flRadiusScale"); }
    void SetRadiusScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CollideWithParentParticles", "m_flRadiusScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif