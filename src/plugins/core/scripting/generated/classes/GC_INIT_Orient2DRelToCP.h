class GC_INIT_Orient2DRelToCP;

#ifndef _gcc_init_orient2dreltocp_h
#define _gcc_init_orient2dreltocp_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_INIT_Orient2DRelToCP
{
private:
    void *m_ptr;

public:
    GC_INIT_Orient2DRelToCP() {}
    GC_INIT_Orient2DRelToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_Orient2DRelToCP", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_Orient2DRelToCP", "m_nCP", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_Orient2DRelToCP", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_Orient2DRelToCP", "m_nFieldOutput", false, value); }
    float GetRotOffset() const { return GetSchemaValue<float>(m_ptr, "C_INIT_Orient2DRelToCP", "m_flRotOffset"); }
    void SetRotOffset(float value) { SetSchemaValue(m_ptr, "C_INIT_Orient2DRelToCP", "m_flRotOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif