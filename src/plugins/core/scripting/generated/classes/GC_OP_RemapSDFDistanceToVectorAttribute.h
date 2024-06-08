class GC_OP_RemapSDFDistanceToVectorAttribute;

#ifndef _gcc_op_remapsdfdistancetovectorattribute_h
#define _gcc_op_remapsdfdistancetovectorattribute_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_OP_RemapSDFDistanceToVectorAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_RemapSDFDistanceToVectorAttribute() {}
    GC_OP_RemapSDFDistanceToVectorAttribute(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetVectorFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_nVectorFieldOutput"); }
    void SetVectorFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_nVectorFieldOutput", false, value); }
    GParticleAttributeIndex_t GetVectorFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_nVectorFieldInput"); }
    void SetVectorFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_nVectorFieldInput", false, value); }
    GCParticleCollectionFloatInput GetMinDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_flMinDistance"); }
    void SetMinDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_flMinDistance", false, value); }
    GCParticleCollectionFloatInput GetMaxDistance() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_flMaxDistance"); }
    void SetMaxDistance(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_flMaxDistance", false, value); }
    Vector GetValueBelowMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueBelowMin"); }
    void SetValueBelowMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueBelowMin", false, value); }
    Vector GetValueAtMin() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueAtMin"); }
    void SetValueAtMin(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueAtMin", false, value); }
    Vector GetValueAtMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueAtMax"); }
    void SetValueAtMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueAtMax", false, value); }
    Vector GetValueAboveMax() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueAboveMax"); }
    void SetValueAboveMax(Vector value) { SetSchemaValue(m_ptr, "C_OP_RemapSDFDistanceToVectorAttribute", "m_vValueAboveMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif