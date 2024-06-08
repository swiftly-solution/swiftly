class GC_OP_LerpToInitialPosition;

#ifndef _gcc_op_lerptoinitialposition_h
#define _gcc_op_lerptoinitialposition_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_LerpToInitialPosition
{
private:
    void *m_ptr;

public:
    GC_OP_LerpToInitialPosition() {}
    GC_OP_LerpToInitialPosition(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_LerpToInitialPosition", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_OP_LerpToInitialPosition", "m_nControlPointNumber", false, value); }
    GCPerParticleFloatInput GetInterpolation() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_LerpToInitialPosition", "m_flInterpolation"); }
    void SetInterpolation(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LerpToInitialPosition", "m_flInterpolation", false, value); }
    GParticleAttributeIndex_t GetCacheField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_LerpToInitialPosition", "m_nCacheField"); }
    void SetCacheField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_LerpToInitialPosition", "m_nCacheField", false, value); }
    GCParticleCollectionFloatInput GetScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_LerpToInitialPosition", "m_flScale"); }
    void SetScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_LerpToInitialPosition", "m_flScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif