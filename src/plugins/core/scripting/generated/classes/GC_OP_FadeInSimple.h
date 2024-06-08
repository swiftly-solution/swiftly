class GC_OP_FadeInSimple;

#ifndef _gcc_op_fadeinsimple_h
#define _gcc_op_fadeinsimple_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_FadeInSimple
{
private:
    void *m_ptr;

public:
    GC_OP_FadeInSimple() {}
    GC_OP_FadeInSimple(void *ptr) : m_ptr(ptr) {}

    float GetFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeInSimple", "m_flFadeInTime"); }
    void SetFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeInSimple", "m_flFadeInTime", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_FadeInSimple", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_FadeInSimple", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif