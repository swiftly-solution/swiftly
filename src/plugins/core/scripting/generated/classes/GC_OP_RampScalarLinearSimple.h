class GC_OP_RampScalarLinearSimple;

#ifndef _gcc_op_rampscalarlinearsimple_h
#define _gcc_op_rampscalarlinearsimple_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RampScalarLinearSimple
{
private:
    void *m_ptr;

public:
    GC_OP_RampScalarLinearSimple() {}
    GC_OP_RampScalarLinearSimple(void *ptr) : m_ptr(ptr) {}

    float GetRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarLinearSimple", "m_Rate"); }
    void SetRate(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarLinearSimple", "m_Rate", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarLinearSimple", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarLinearSimple", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RampScalarLinearSimple", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_RampScalarLinearSimple", "m_flEndTime", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RampScalarLinearSimple", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RampScalarLinearSimple", "m_nField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif