class GC_OP_OscillateVectorSimple;

#ifndef _gcc_op_oscillatevectorsimple_h
#define _gcc_op_oscillatevectorsimple_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_OscillateVectorSimple
{
private:
    void *m_ptr;

public:
    GC_OP_OscillateVectorSimple() {}
    GC_OP_OscillateVectorSimple(void *ptr) : m_ptr(ptr) {}

    Vector GetRate() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_OscillateVectorSimple", "m_Rate"); }
    void SetRate(Vector value) { SetSchemaValue(m_ptr, "C_OP_OscillateVectorSimple", "m_Rate", false, value); }
    Vector GetFrequency() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_OscillateVectorSimple", "m_Frequency"); }
    void SetFrequency(Vector value) { SetSchemaValue(m_ptr, "C_OP_OscillateVectorSimple", "m_Frequency", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_OscillateVectorSimple", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_OscillateVectorSimple", "m_nField", false, value); }
    float GetOscMult() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateVectorSimple", "m_flOscMult"); }
    void SetOscMult(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateVectorSimple", "m_flOscMult", false, value); }
    float GetOscAdd() const { return GetSchemaValue<float>(m_ptr, "C_OP_OscillateVectorSimple", "m_flOscAdd"); }
    void SetOscAdd(float value) { SetSchemaValue(m_ptr, "C_OP_OscillateVectorSimple", "m_flOscAdd", false, value); }
    bool GetOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_OscillateVectorSimple", "m_bOffset"); }
    void SetOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_OscillateVectorSimple", "m_bOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif