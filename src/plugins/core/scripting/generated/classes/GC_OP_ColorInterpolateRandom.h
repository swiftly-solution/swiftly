class GC_OP_ColorInterpolateRandom;

#ifndef _gcc_op_colorinterpolaterandom_h
#define _gcc_op_colorinterpolaterandom_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_ColorInterpolateRandom
{
private:
    void *m_ptr;

public:
    GC_OP_ColorInterpolateRandom() {}
    GC_OP_ColorInterpolateRandom(void *ptr) : m_ptr(ptr) {}

    Color GetColorFadeMin() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ColorInterpolateRandom", "m_ColorFadeMin"); }
    void SetColorFadeMin(Color value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolateRandom", "m_ColorFadeMin", false, value); }
    Color GetColorFadeMax() const { return GetSchemaValue<Color>(m_ptr, "C_OP_ColorInterpolateRandom", "m_ColorFadeMax"); }
    void SetColorFadeMax(Color value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolateRandom", "m_ColorFadeMax", false, value); }
    float GetFadeStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_ColorInterpolateRandom", "m_flFadeStartTime"); }
    void SetFadeStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolateRandom", "m_flFadeStartTime", false, value); }
    float GetFadeEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_ColorInterpolateRandom", "m_flFadeEndTime"); }
    void SetFadeEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolateRandom", "m_flFadeEndTime", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ColorInterpolateRandom", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolateRandom", "m_nFieldOutput", false, value); }
    bool GetEaseInOut() const { return GetSchemaValue<bool>(m_ptr, "C_OP_ColorInterpolateRandom", "m_bEaseInOut"); }
    void SetEaseInOut(bool value) { SetSchemaValue(m_ptr, "C_OP_ColorInterpolateRandom", "m_bEaseInOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif