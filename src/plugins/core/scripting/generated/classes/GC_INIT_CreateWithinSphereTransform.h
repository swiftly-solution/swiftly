class GC_INIT_CreateWithinSphereTransform;

#ifndef _gcc_init_createwithinspheretransform_h
#define _gcc_init_createwithinspheretransform_h

#include "../../../scripting.h"


#include "GCPerParticleFloatInput.h"
#include "GCPerParticleVecInput.h"
#include "GCParticleTransformInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_INIT_CreateWithinSphereTransform
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateWithinSphereTransform() {}
    GC_INIT_CreateWithinSphereTransform(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetRadiusMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fRadiusMin"); }
    void SetRadiusMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fRadiusMin", false, value); }
    GCPerParticleFloatInput GetRadiusMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fRadiusMax"); }
    void SetRadiusMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fRadiusMax", false, value); }
    GCPerParticleVecInput GetDistanceBias() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_vecDistanceBias"); }
    void SetDistanceBias(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_vecDistanceBias", false, value); }
    Vector GetDistanceBiasAbs() const { return GetSchemaValue<Vector>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_vecDistanceBiasAbs"); }
    void SetDistanceBiasAbs(Vector value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_vecDistanceBiasAbs", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_TransformInput", false, value); }
    GCPerParticleFloatInput GetSpeedMin() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fSpeedMin"); }
    void SetSpeedMin(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fSpeedMin", false, value); }
    GCPerParticleFloatInput GetSpeedMax() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fSpeedMax"); }
    void SetSpeedMax(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fSpeedMax", false, value); }
    float GetSpeedRandExp() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fSpeedRandExp"); }
    void SetSpeedRandExp(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_fSpeedRandExp", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_bLocalCoords", false, value); }
    float GetEndCPGrowthTime() const { return GetSchemaValue<float>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_flEndCPGrowthTime"); }
    void SetEndCPGrowthTime(float value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_flEndCPGrowthTime", false, value); }
    GCPerParticleVecInput GetLocalCoordinateSystemSpeedMin() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_LocalCoordinateSystemSpeedMin"); }
    void SetLocalCoordinateSystemSpeedMin(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_LocalCoordinateSystemSpeedMin", false, value); }
    GCPerParticleVecInput GetLocalCoordinateSystemSpeedMax() const { return GetSchemaValue<GCPerParticleVecInput>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_LocalCoordinateSystemSpeedMax"); }
    void SetLocalCoordinateSystemSpeedMax(GCPerParticleVecInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_LocalCoordinateSystemSpeedMax", false, value); }
    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldVelocity() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_nFieldVelocity"); }
    void SetFieldVelocity(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateWithinSphereTransform", "m_nFieldVelocity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif