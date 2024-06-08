class GC_OP_CollideWithSelf;

#ifndef _gcc_op_collidewithself_h
#define _gcc_op_collidewithself_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_OP_CollideWithSelf
{
private:
    void *m_ptr;

public:
    GC_OP_CollideWithSelf() {}
    GC_OP_CollideWithSelf(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetRadiusScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CollideWithSelf", "m_flRadiusScale"); }
    void SetRadiusScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CollideWithSelf", "m_flRadiusScale", false, value); }
    GCPerParticleFloatInput GetMinimumSpeed() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_CollideWithSelf", "m_flMinimumSpeed"); }
    void SetMinimumSpeed(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_CollideWithSelf", "m_flMinimumSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif