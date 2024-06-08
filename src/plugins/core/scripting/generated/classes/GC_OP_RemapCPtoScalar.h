class GC_OP_RemapCPtoScalar;

#ifndef _gcc_op_remapcptoscalar_h
#define _gcc_op_remapcptoscalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapCPtoScalar
{
private:
    void *m_ptr;

public:
    GC_OP_RemapCPtoScalar() {}
    GC_OP_RemapCPtoScalar(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPInput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoScalar", "m_nCPInput"); }
    void SetCPInput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_nCPInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapCPtoScalar", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_nFieldOutput", false, value); }
    int32_t GetField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoScalar", "m_nField"); }
    void SetField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_nField", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flOutputMax", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flEndTime", false, value); }
    float GetInterpRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoScalar", "m_flInterpRate"); }
    void SetInterpRate(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_flInterpRate", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapCPtoScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoScalar", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif