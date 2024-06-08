class GC_OP_InheritFromParentParticles;

#ifndef _gcc_op_inheritfromparentparticles_h
#define _gcc_op_inheritfromparentparticles_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_InheritFromParentParticles
{
private:
    void *m_ptr;

public:
    GC_OP_InheritFromParentParticles() {}
    GC_OP_InheritFromParentParticles(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_InheritFromParentParticles", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticles", "m_flScale", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_InheritFromParentParticles", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticles", "m_nFieldOutput", false, value); }
    int32_t GetIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_InheritFromParentParticles", "m_nIncrement"); }
    void SetIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticles", "m_nIncrement", false, value); }
    bool GetRandomDistribution() const { return GetSchemaValue<bool>(m_ptr, "C_OP_InheritFromParentParticles", "m_bRandomDistribution"); }
    void SetRandomDistribution(bool value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticles", "m_bRandomDistribution", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif