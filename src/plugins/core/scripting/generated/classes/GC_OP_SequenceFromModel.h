class GC_OP_SequenceFromModel;

#ifndef _gcc_op_sequencefrommodel_h
#define _gcc_op_sequencefrommodel_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_SequenceFromModel
{
private:
    void *m_ptr;

public:
    GC_OP_SequenceFromModel() {}
    GC_OP_SequenceFromModel(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SequenceFromModel", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_nControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SequenceFromModel", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldOutputAnim() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SequenceFromModel", "m_nFieldOutputAnim"); }
    void SetFieldOutputAnim(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_nFieldOutputAnim", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_SequenceFromModel", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_SequenceFromModel", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_SequenceFromModel", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_SequenceFromModel", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_SequenceFromModel", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_SequenceFromModel", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif