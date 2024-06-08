class GC_OP_ColorInterpolate;

#ifndef _gcc_op_colorinterpolate_h
#define _gcc_op_colorinterpolate_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_ColorInterpolate
{
private:
    void *m_ptr;

public:
    GC_OP_ColorInterpolate() {}
    GC_OP_ColorInterpolate(void *ptr) : m_ptr(ptr) {}

    Color GetColorFade() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ColorInterpolate", "m_ColorFade"); }
    void SetColorFade(Color value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolate", "m_ColorFade", false, value); }
    float GetFadeStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_ColorInterpolate", "m_flFadeStartTime"); }
    void SetFadeStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolate", "m_flFadeStartTime", false, value); }
    float GetFadeEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_ColorInterpolate", "m_flFadeEndTime"); }
    void SetFadeEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolate", "m_flFadeEndTime", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ColorInterpolate", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolate", "m_nFieldOutput", false, value); }
    bool GetEaseInOut() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ColorInterpolate", "m_bEaseInOut"); }
    void SetEaseInOut(bool value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolate", "m_bEaseInOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif