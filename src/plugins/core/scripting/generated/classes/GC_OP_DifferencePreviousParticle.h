class GC_OP_DifferencePreviousParticle;

#ifndef _gcc_op_differencepreviousparticle_h
#define _gcc_op_differencepreviousparticle_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_DifferencePreviousParticle
{
private:
    void *m_ptr;

public:
    GC_OP_DifferencePreviousParticle() {}
    GC_OP_DifferencePreviousParticle(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_DifferencePreviousParticle", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_nFieldInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_DifferencePreviousParticle", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_nFieldOutput", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_DifferencePreviousParticle", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_DifferencePreviousParticle", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_DifferencePreviousParticle", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_DifferencePreviousParticle", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_DifferencePreviousParticle", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_nSetMethod", false, value); }
    bool GetActiveRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DifferencePreviousParticle", "m_bActiveRange"); }
    void SetActiveRange(bool value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_bActiveRange", false, value); }
    bool GetSetPreviousParticle() const { return GetSchemaValue<bool>(m_ptr, "C_OP_DifferencePreviousParticle", "m_bSetPreviousParticle"); }
    void SetSetPreviousParticle(bool value) { SetSchemaValue(m_ptr, "C_OP_DifferencePreviousParticle", "m_bSetPreviousParticle", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif