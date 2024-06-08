class GC_OP_RenderOmni2Light;

#ifndef _gcc_op_renderomni2light_h
#define _gcc_op_renderomni2light_h

#include "../../../scripting.h"

#include "../types/GParticleOmni2LightTypeChoiceList_t.h"
#include "../types/GParticleColorBlendType_t.h"
#include "../types/GParticleLightUnitChoiceList_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_RenderOmni2Light
{
private:
    void *m_ptr;

public:
    GC_OP_RenderOmni2Light() {}
    GC_OP_RenderOmni2Light(void *ptr) : m_ptr(ptr) {}

    ParticleOmni2LightTypeChoiceList_t GetLightType() const { return GetSchemaValue<ParticleOmni2LightTypeChoiceList_t>(m_ptr, "C_OP_RenderOmni2Light", "m_nLightType"); }
    void SetLightType(ParticleOmni2LightTypeChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_nLightType", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderOmni2Light", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_nColorBlendType", false, value); }
    ParticleLightUnitChoiceList_t GetBrightnessUnit() const { return GetSchemaValue<ParticleLightUnitChoiceList_t>(m_ptr, "C_OP_RenderOmni2Light", "m_nBrightnessUnit"); }
    void SetBrightnessUnit(ParticleLightUnitChoiceList_t value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_nBrightnessUnit", false, value); }
    GCPerParticleFloatInput GetBrightnessLumens() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flBrightnessLumens"); }
    void SetBrightnessLumens(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flBrightnessLumens", false, value); }
    GCPerParticleFloatInput GetBrightnessCandelas() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flBrightnessCandelas"); }
    void SetBrightnessCandelas(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flBrightnessCandelas", false, value); }
    bool GetCastShadows() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderOmni2Light", "m_bCastShadows"); }
    void SetCastShadows(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_bCastShadows", false, value); }
    GCPerParticleFloatInput GetLuminaireRadius() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flLuminaireRadius"); }
    void SetLuminaireRadius(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flLuminaireRadius", false, value); }
    GCPerParticleFloatInput GetSkirt() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flSkirt"); }
    void SetSkirt(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flSkirt", false, value); }
    GCPerParticleFloatInput GetRange() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flRange"); }
    void SetRange(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flRange", false, value); }
    GCPerParticleFloatInput GetInnerConeAngle() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flInnerConeAngle"); }
    void SetInnerConeAngle(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flInnerConeAngle", false, value); }
    GCPerParticleFloatInput GetOuterConeAngle() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderOmni2Light", "m_flOuterConeAngle"); }
    void SetOuterConeAngle(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_flOuterConeAngle", false, value); }
    bool GetSphericalCookie() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderOmni2Light", "m_bSphericalCookie"); }
    void SetSphericalCookie(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderOmni2Light", "m_bSphericalCookie", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif