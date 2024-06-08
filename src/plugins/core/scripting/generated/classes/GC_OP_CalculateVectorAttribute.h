class GC_OP_CalculateVectorAttribute;

#ifndef _gcc_op_calculatevectorattribute_h
#define _gcc_op_calculatevectorattribute_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GControlPointReference_t.h"

class GC_OP_CalculateVectorAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_CalculateVectorAttribute() {}
    GC_OP_CalculateVectorAttribute(void *ptr) : m_ptr(ptr) {}

    Vector GetStartValue() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_CalculateVectorAttribute", "m_vStartValue"); }
    void SetStartValue(Vector value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_vStartValue", false, value); }
    GParticleAttributeIndex_t GetFieldInput1() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_CalculateVectorAttribute", "m_nFieldInput1"); }
    void SetFieldInput1(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_nFieldInput1", false, value); }
    float GetInputScale1() const { return GetSchemaValue<float>(m_ptr, "C_OP_CalculateVectorAttribute", "m_flInputScale1"); }
    void SetInputScale1(float value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_flInputScale1", false, value); }
    GParticleAttributeIndex_t GetFieldInput2() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_CalculateVectorAttribute", "m_nFieldInput2"); }
    void SetFieldInput2(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_nFieldInput2", false, value); }
    float GetInputScale2() const { return GetSchemaValue<float>(m_ptr, "C_OP_CalculateVectorAttribute", "m_flInputScale2"); }
    void SetInputScale2(float value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_flInputScale2", false, value); }
    GControlPointReference_t GetControlPointInput1() const { return GetSchemaValue<GControlPointReference_t>(m_ptr, "C_OP_CalculateVectorAttribute", "m_nControlPointInput1"); }
    void SetControlPointInput1(GControlPointReference_t value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_nControlPointInput1", false, value); }
    float GetControlPointScale1() const { return GetSchemaValue<float>(m_ptr, "C_OP_CalculateVectorAttribute", "m_flControlPointScale1"); }
    void SetControlPointScale1(float value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_flControlPointScale1", false, value); }
    GControlPointReference_t GetControlPointInput2() const { return GetSchemaValue<GControlPointReference_t>(m_ptr, "C_OP_CalculateVectorAttribute", "m_nControlPointInput2"); }
    void SetControlPointInput2(GControlPointReference_t value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_nControlPointInput2", false, value); }
    float GetControlPointScale2() const { return GetSchemaValue<float>(m_ptr, "C_OP_CalculateVectorAttribute", "m_flControlPointScale2"); }
    void SetControlPointScale2(float value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_flControlPointScale2", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_CalculateVectorAttribute", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_nFieldOutput", false, value); }
    Vector GetFinalOutputScale() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_CalculateVectorAttribute", "m_vFinalOutputScale"); }
    void SetFinalOutputScale(Vector value) { SetSchemaValue(m_ptr, "C_OP_CalculateVectorAttribute", "m_vFinalOutputScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif