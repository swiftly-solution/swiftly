class GC_INIT_CreateInEpitrochoid;

#ifndef _gcc_init_createinepitrochoid_h
#define _gcc_init_createinepitrochoid_h

#include "../../../scripting.h"


#include "GCParticleTransformInput.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_CreateInEpitrochoid
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateInEpitrochoid() {}
    GC_INIT_CreateInEpitrochoid(void *ptr) : m_ptr(ptr) {}

    int32_t GetComponent1() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_nComponent1"); }
    void SetComponent1(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_nComponent1", false, value); }
    int32_t GetComponent2() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_nComponent2"); }
    void SetComponent2(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_nComponent2", false, value); }
    GCParticleTransformInput GetTransformInput() const { return GetSchemaValue<GCParticleTransformInput>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_TransformInput"); }
    void SetTransformInput(GCParticleTransformInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_TransformInput", false, value); }
    GCPerParticleFloatInput GetParticleDensity() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flParticleDensity"); }
    void SetParticleDensity(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flParticleDensity", false, value); }
    GCPerParticleFloatInput GetOffset() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flOffset"); }
    void SetOffset(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flOffset", false, value); }
    GCPerParticleFloatInput GetRadius1() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flRadius1"); }
    void SetRadius1(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flRadius1", false, value); }
    GCPerParticleFloatInput GetRadius2() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flRadius2"); }
    void SetRadius2(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_flRadius2", false, value); }
    bool GetUseCount() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_bUseCount"); }
    void SetUseCount(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_bUseCount", false, value); }
    bool GetUseLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_bUseLocalCoords"); }
    void SetUseLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_bUseLocalCoords", false, value); }
    bool GetOffsetExistingPos() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateInEpitrochoid", "m_bOffsetExistingPos"); }
    void SetOffsetExistingPos(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateInEpitrochoid", "m_bOffsetExistingPos", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif