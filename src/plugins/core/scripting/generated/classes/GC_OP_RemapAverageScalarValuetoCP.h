class GC_OP_RemapAverageScalarValuetoCP;

#ifndef _gcc_op_remapaveragescalarvaluetocp_h
#define _gcc_op_remapaveragescalarvaluetocp_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_RemapAverageScalarValuetoCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapAverageScalarValuetoCP() {}
    GC_OP_RemapAverageScalarValuetoCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetOutControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_nOutControlPointNumber"); }
    void SetOutControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_nOutControlPointNumber", false, value); }
    int32_t GetOutVectorField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_nOutVectorField"); }
    void SetOutVectorField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_nOutVectorField", false, value); }
    GParticleAttributeIndex_t GetField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_nField"); }
    void SetField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_nField", false, value); }
    float GetInputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flInputMin"); }
    void SetInputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flInputMin", false, value); }
    float GetInputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flInputMax"); }
    void SetInputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flInputMax", false, value); }
    float GetOutputMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flOutputMin"); }
    void SetOutputMin(float value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flOutputMin", false, value); }
    float GetOutputMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flOutputMax"); }
    void SetOutputMax(float value) { SetSchemaValue(m_ptr, "C_OP_RemapAverageScalarValuetoCP", "m_flOutputMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif