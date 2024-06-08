class GC_OP_ReinitializeScalarEndCap;

#ifndef _gcc_op_reinitializescalarendcap_h
#define _gcc_op_reinitializescalarendcap_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_ReinitializeScalarEndCap
{
private:
    void *m_ptr;

public:
    GC_OP_ReinitializeScalarEndCap() {}
    GC_OP_ReinitializeScalarEndCap(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_ReinitializeScalarEndCap", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_ReinitializeScalarEndCap", "m_nFieldOutput", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_ReinitializeScalarEndCap", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_ReinitializeScalarEndCap", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_ReinitializeScalarEndCap", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_ReinitializeScalarEndCap", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif