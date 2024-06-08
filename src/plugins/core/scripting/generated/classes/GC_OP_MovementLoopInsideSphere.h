class GC_OP_MovementLoopInsideSphere;

#ifndef _gcc_op_movementloopinsidesphere_h
#define _gcc_op_movementloopinsidesphere_h

#include "../../../scripting.h"


#include "GCParticleCollectionFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_MovementLoopInsideSphere
{
private:
    void *m_ptr;

public:
    GC_OP_MovementLoopInsideSphere() {}
    GC_OP_MovementLoopInsideSphere(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementLoopInsideSphere", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementLoopInsideSphere", "m_nCP", false, value); }
    GCParticleCollectionFloatInput GetDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_MovementLoopInsideSphere", "m_flDistance"); }
    void SetDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementLoopInsideSphere", "m_flDistance", false, value); }
    GParticleAttributeIndex_t GetDistSqrAttr() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_MovementLoopInsideSphere", "m_nDistSqrAttr"); }
    void SetDistSqrAttr(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_MovementLoopInsideSphere", "m_nDistSqrAttr", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif