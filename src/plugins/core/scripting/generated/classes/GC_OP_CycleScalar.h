class GC_OP_CycleScalar;

#ifndef _gcc_op_cyclescalar_h
#define _gcc_op_cyclescalar_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_CycleScalar
{
private:
    void *m_ptr;

public:
    GC_OP_CycleScalar() {}
    GC_OP_CycleScalar(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetDestField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_CycleScalar", "m_nDestField"); }
    void SetDestField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_nDestField", false, value); }
    float GetStartValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_CycleScalar", "m_flStartValue"); }
    void SetStartValue(float value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_flStartValue", false, value); }
    float GetEndValue() const { return GetSchemaValue<float>(m_ptr, "C_OP_CycleScalar", "m_flEndValue"); }
    void SetEndValue(float value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_flEndValue", false, value); }
    float GetCycleTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_CycleScalar", "m_flCycleTime"); }
    void SetCycleTime(float value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_flCycleTime", false, value); }
    bool GetDoNotRepeatCycle() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CycleScalar", "m_bDoNotRepeatCycle"); }
    void SetDoNotRepeatCycle(bool value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_bDoNotRepeatCycle", false, value); }
    bool GetSynchronizeParticles() const { return GetSchemaValue<bool>(m_ptr, "C_OP_CycleScalar", "m_bSynchronizeParticles"); }
    void SetSynchronizeParticles(bool value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_bSynchronizeParticles", false, value); }
    int32_t GetCPScale() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CycleScalar", "m_nCPScale"); }
    void SetCPScale(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_nCPScale", false, value); }
    int32_t GetCPFieldMin() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CycleScalar", "m_nCPFieldMin"); }
    void SetCPFieldMin(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_nCPFieldMin", false, value); }
    int32_t GetCPFieldMax() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_CycleScalar", "m_nCPFieldMax"); }
    void SetCPFieldMax(int32_t value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_nCPFieldMax", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_CycleScalar", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_CycleScalar", "m_nSetMethod", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif