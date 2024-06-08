class GC_OP_FadeOutSimple;

#ifndef _gcc_op_fadeoutsimple_h
#define _gcc_op_fadeoutsimple_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_FadeOutSimple
{
private:
    void *m_ptr;

public:
    GC_OP_FadeOutSimple() {}
    GC_OP_FadeOutSimple(void *ptr) : m_ptr(ptr) {}

    float GetFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_FadeOutSimple", "m_flFadeOutTime"); }
    void SetFadeOutTime(float value) { SetSchemaValue(m_ptr, "C_OP_FadeOutSimple", "m_flFadeOutTime", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_FadeOutSimple", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_FadeOutSimple", "m_nFieldOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif