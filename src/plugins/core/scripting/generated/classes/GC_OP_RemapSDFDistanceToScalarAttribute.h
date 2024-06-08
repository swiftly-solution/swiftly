class GC_OP_RemapSDFDistanceToScalarAttribute;

#ifndef _gcc_op_remapsdfdistancetoscalarattribute_h
#define _gcc_op_remapsdfdistancetoscalarattribute_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_RemapSDFDistanceToScalarAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_RemapSDFDistanceToScalarAttribute() {}
    GC_OP_RemapSDFDistanceToScalarAttribute(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetVectorFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_nVectorFieldInput"); }
    void SetVectorFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_nVectorFieldInput", false, value); }
    GCParticleCollectionFloatInput GetMinDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flMinDistance"); }
    void SetMinDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flMinDistance", false, value); }
    GCParticleCollectionFloatInput GetMaxDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flMaxDistance"); }
    void SetMaxDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flMaxDistance", false, value); }
    GCParticleCollectionFloatInput GetValueBelowMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueBelowMin"); }
    void SetValueBelowMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueBelowMin", false, value); }
    GCParticleCollectionFloatInput GetValueAtMin() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueAtMin"); }
    void SetValueAtMin(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueAtMin", false, value); }
    GCParticleCollectionFloatInput GetValueAtMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueAtMax"); }
    void SetValueAtMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueAtMax", false, value); }
    GCParticleCollectionFloatInput GetValueAboveMax() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueAboveMax"); }
    void SetValueAboveMax(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToScalarAttribute", "m_flValueAboveMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif