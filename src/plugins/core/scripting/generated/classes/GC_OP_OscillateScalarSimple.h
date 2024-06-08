class GC_OP_OscillateScalarSimple;

#ifndef _gcc_op_oscillatescalarsimple_h
#define _gcc_op_oscillatescalarsimple_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_OscillateScalarSimple
{
private:
    void *m_ptr;

public:
    GC_OP_OscillateScalarSimple() {}
    GC_OP_OscillateScalarSimple(void *ptr) : m_ptr(ptr) {}

    float GetRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalarSimple", "m_Rate"); }
    void SetRate(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalarSimple", "m_Rate", false, value); }
    float GetFrequency() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalarSimple", "m_Frequency"); }
    void SetFrequency(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalarSimple", "m_Frequency", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_OscillateScalarSimple", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalarSimple", "m_nField", false, value); }
    float GetOscMult() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalarSimple", "m_flOscMult"); }
    void SetOscMult(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalarSimple", "m_flOscMult", false, value); }
    float GetOscAdd() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateScalarSimple", "m_flOscAdd"); }
    void SetOscAdd(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateScalarSimple", "m_flOscAdd", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif