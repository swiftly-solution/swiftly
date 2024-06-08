class GC_OP_Orient2DRelToCP;

#ifndef _gcc_op_orient2dreltocp_h
#define _gcc_op_orient2dreltocp_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_Orient2DRelToCP
{
private:
    void *m_ptr;

public:
    GC_OP_Orient2DRelToCP() {}
    GC_OP_Orient2DRelToCP(void *ptr) : m_ptr(ptr) {}

    float GetRotOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_Orient2DRelToCP", "m_flRotOffset"); }
    void SetRotOffset(float value) { SetSchemaValue(m_ptr, "C_OP_Orient2DRelToCP", "m_flRotOffset", false, value); }
    float GetSpinStrength() const { return GetSchemaValue<float>(m_ptr, "C_OP_Orient2DRelToCP", "m_flSpinStrength"); }
    void SetSpinStrength(float value) { SetSchemaValue(m_ptr, "C_OP_Orient2DRelToCP", "m_flSpinStrength", false, value); }
    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_Orient2DRelToCP", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_Orient2DRelToCP", "m_nCP", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_Orient2DRelToCP", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_Orient2DRelToCP", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif