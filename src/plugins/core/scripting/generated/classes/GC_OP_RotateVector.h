class GC_OP_RotateVector;

#ifndef _gcc_op_rotatevector_h
#define _gcc_op_rotatevector_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_RotateVector
{
private:
    void *m_ptr;

public:
    GC_OP_RotateVector() {}
    GC_OP_RotateVector(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RotateVector", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_nFieldOutput", false, value); }
    Vector GetRotAxisMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RotateVector", "m_vecRotAxisMin"); }
    void SetRotAxisMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_vecRotAxisMin", false, value); }
    Vector GetRotAxisMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RotateVector", "m_vecRotAxisMax"); }
    void SetRotAxisMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_vecRotAxisMax", false, value); }
    float GetRotRateMin() const { return GetSchemaValue<float>(m_ptr, "C_OP_RotateVector", "m_flRotRateMin"); }
    void SetRotRateMin(float value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_flRotRateMin", false, value); }
    float GetRotRateMax() const { return GetSchemaValue<float>(m_ptr, "C_OP_RotateVector", "m_flRotRateMax"); }
    void SetRotRateMax(float value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_flRotRateMax", false, value); }
    bool GetNormalize() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RotateVector", "m_bNormalize"); }
    void SetNormalize(bool value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_bNormalize", false, value); }
    GCPerParticleFloatInput GetScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RotateVector", "m_flScale"); }
    void SetScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RotateVector", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif