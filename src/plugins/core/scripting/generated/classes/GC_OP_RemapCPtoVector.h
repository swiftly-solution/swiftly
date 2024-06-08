class GC_OP_RemapCPtoVector;

#ifndef _gcc_op_remapcptovector_h
#define _gcc_op_remapcptovector_h

#include "../../../scripting.h"

#include "../types/GParticleSetMethod_t.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapCPtoVector
{
private:
    void *m_ptr;

public:
    GC_OP_RemapCPtoVector() {}
    GC_OP_RemapCPtoVector(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPInput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoVector", "m_nCPInput"); }
    void SetCPInput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_nCPInput", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapCPtoVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_nFieldOutput", false, value); }
    int32_t GetLocalSpaceCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapCPtoVector", "m_nLocalSpaceCP"); }
    void SetLocalSpaceCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_nLocalSpaceCP", false, value); }
    Vector GetInputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapCPtoVector", "m_vInputMin"); }
    void SetInputMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_vInputMin", false, value); }
    Vector GetInputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapCPtoVector", "m_vInputMax"); }
    void SetInputMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_vInputMax", false, value); }
    Vector GetOutputMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapCPtoVector", "m_vOutputMin"); }
    void SetOutputMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_vOutputMin", false, value); }
    Vector GetOutputMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapCPtoVector", "m_vOutputMax"); }
    void SetOutputMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_vOutputMax", false, value); }
    float GetStartTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoVector", "m_flStartTime"); }
    void SetStartTime(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_flStartTime", false, value); }
    float GetEndTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoVector", "m_flEndTime"); }
    void SetEndTime(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_flEndTime", false, value); }
    float GetInterpRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapCPtoVector", "m_flInterpRate"); }
    void SetInterpRate(float value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_flInterpRate", false, value); }
    ParticleSetMethod_t GetSetMethod() const { return GetSchemaValue<ParticleSetMethod_t>(m_ptr, "C_OP_RemapCPtoVector", "m_nSetMethod"); }
    void SetSetMethod(ParticleSetMethod_t value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_nSetMethod", false, value); }
    bool GetOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapCPtoVector", "m_bOffset"); }
    void SetOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_bOffset", false, value); }
    bool GetAccelerate() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapCPtoVector", "m_bAccelerate"); }
    void SetAccelerate(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapCPtoVector", "m_bAccelerate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif