class GC_INIT_InitialSequenceFromModel;

#ifndef _gcc_init_initialsequencefrommodel_h
#define _gcc_init_initialsequencefrommodel_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_InitialSequenceFromModel
{
private:
    void *m_ptr;

public:
    GC_INIT_InitialSequenceFromModel() {}
    GC_INIT_InitialSequenceFromModel(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nControlPointNumber", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldOutputAnim() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nFieldOutputAnim"); }
    void SetFieldOutputAnim(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nFieldOutputAnim", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_flOutputMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_INIT_InitialSequenceFromModel", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif