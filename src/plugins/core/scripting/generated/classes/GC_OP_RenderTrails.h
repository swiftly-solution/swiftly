class GC_OP_RenderTrails;

#ifndef _gcc_op_rendertrails_h
#define _gcc_op_rendertrails_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_RenderTrails
{
private:
    void *m_ptr;

public:
    GC_OP_RenderTrails() {}
    GC_OP_RenderTrails(void *ptr) : m_ptr(ptr) {}

    bool GetEnableFadingAndClamping() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderTrails", "m_bEnableFadingAndClamping"); }
    void SetEnableFadingAndClamping(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_bEnableFadingAndClamping", false, value); }
    float GetStartFadeDot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flStartFadeDot"); }
    void SetStartFadeDot(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flStartFadeDot", false, value); }
    float GetEndFadeDot() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flEndFadeDot"); }
    void SetEndFadeDot(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flEndFadeDot", false, value); }
    GParticleAttributeIndex_t GetPrevPntSource() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTrails", "m_nPrevPntSource"); }
    void SetPrevPntSource(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_nPrevPntSource", false, value); }
    float GetMaxLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flMaxLength"); }
    void SetMaxLength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flMaxLength", false, value); }
    float GetMinLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flMinLength"); }
    void SetMinLength(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flMinLength", false, value); }
    bool GetIgnoreDT() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderTrails", "m_bIgnoreDT"); }
    void SetIgnoreDT(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_bIgnoreDT", false, value); }
    float GetConstrainRadiusToLengthRatio() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flConstrainRadiusToLengthRatio"); }
    void SetConstrainRadiusToLengthRatio(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flConstrainRadiusToLengthRatio", false, value); }
    float GetLengthScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flLengthScale"); }
    void SetLengthScale(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flLengthScale", false, value); }
    float GetLengthFadeInTime() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flLengthFadeInTime"); }
    void SetLengthFadeInTime(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flLengthFadeInTime", false, value); }
    GCPerParticleFloatInput GetRadiusHeadTaper() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderTrails", "m_flRadiusHeadTaper"); }
    void SetRadiusHeadTaper(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flRadiusHeadTaper", false, value); }
    GCPerParticleFloatInput GetHeadAlphaScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderTrails", "m_flHeadAlphaScale"); }
    void SetHeadAlphaScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flHeadAlphaScale", false, value); }
    GCPerParticleFloatInput GetRadiusTaper() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderTrails", "m_flRadiusTaper"); }
    void SetRadiusTaper(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flRadiusTaper", false, value); }
    GCPerParticleFloatInput GetTailAlphaScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderTrails", "m_flTailAlphaScale"); }
    void SetTailAlphaScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flTailAlphaScale", false, value); }
    GParticleAttributeIndex_t GetHorizCropField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTrails", "m_nHorizCropField"); }
    void SetHorizCropField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_nHorizCropField", false, value); }
    GParticleAttributeIndex_t GetVertCropField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_RenderTrails", "m_nVertCropField"); }
    void SetVertCropField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_nVertCropField", false, value); }
    float GetForwardShift() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderTrails", "m_flForwardShift"); }
    void SetForwardShift(float value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_flForwardShift", false, value); }
    bool GetFlipUVBasedOnPitchYaw() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RenderTrails", "m_bFlipUVBasedOnPitchYaw"); }
    void SetFlipUVBasedOnPitchYaw(bool value) { SetSchemaValue(m_ptr, "C_OP_RenderTrails", "m_bFlipUVBasedOnPitchYaw", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif