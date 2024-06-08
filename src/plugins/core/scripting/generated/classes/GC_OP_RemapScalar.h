class GC_OP_RemapScalar;

#ifndef _gcc_op_remapscalar_h
#define _gcc_op_remapscalar_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapScalar() {}
    GC_OP_RemapScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapScalar", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_flOutputMax", false, value); }
    bool GetOldCode() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapScalar", "m_bOldCode"); }
    void SetOldCode(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapScalar", "m_bOldCode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif