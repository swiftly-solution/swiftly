class GC_OP_ColorAdjustHSL;

#ifndef _gcc_op_coloradjusthsl_h
#define _gcc_op_coloradjusthsl_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"

class GC_OP_ColorAdjustHSL
{
private:
    void *m_ptr;

public:
    GC_OP_ColorAdjustHSL() {}
    GC_OP_ColorAdjustHSL(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetHueAdjust() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ColorAdjustHSL", "m_flHueAdjust"); }
    void SetHueAdjust(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ColorAdjustHSL", "m_flHueAdjust", false, value); }
    GCPerParticleFloatInput GetSaturationAdjust() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ColorAdjustHSL", "m_flSaturationAdjust"); }
    void SetSaturationAdjust(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ColorAdjustHSL", "m_flSaturationAdjust", false, value); }
    GCPerParticleFloatInput GetLightnessAdjust() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_ColorAdjustHSL", "m_flLightnessAdjust"); }
    void SetLightnessAdjust(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_ColorAdjustHSL", "m_flLightnessAdjust", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif