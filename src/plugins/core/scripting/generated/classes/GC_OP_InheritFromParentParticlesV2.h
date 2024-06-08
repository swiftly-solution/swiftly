class GC_OP_InheritFromParentParticlesV2;

#ifndef _gcc_op_inheritfromparentparticlesv2_h
#define _gcc_op_inheritfromparentparticlesv2_h

#include "../../../scripting.h"

#include "../types/GMissingParentInheritBehavior_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_InheritFromParentParticlesV2
{
private:
    void *m_ptr;

public:
    GC_OP_InheritFromParentParticlesV2() {}
    GC_OP_InheritFromParentParticlesV2(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_flScale", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_nFieldOutput", false, value); }
    int32_t GetIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_nIncrement"); }
    void SetIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_nIncrement", false, value); }
    bool GetRandomDistribution() const { return GetSchemaValue<bool>(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_bRandomDistribution"); }
    void SetRandomDistribution(bool value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_bRandomDistribution", false, value); }
    MissingParentInheritBehavior_t GetMissingParentBehavior() const { return GetSchemaValue<MissingParentInheritBehavior_t>(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_nMissingParentBehavior"); }
    void SetMissingParentBehavior(MissingParentInheritBehavior_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromParentParticlesV2", "m_nMissingParentBehavior", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif