class GCParticleFloatInput;

#ifndef _gccparticlefloatinput_h
#define _gccparticlefloatinput_h

#include "../../../scripting.h"

#include "../types/GParticleFloatType_t.h"
#include "../types/GParticleFloatMapType_t.h"
#include "../types/GParticleFloatRandomMode_t.h"
#include "../types/GPFNoiseTurbulence_t.h"
#include "../types/GPFNoiseType_t.h"
#include "../types/GPFNoiseModifier_t.h"
#include "../types/GParticleFloatInputMode_t.h"
#include "../types/GParticleFloatBiasType_t.h"
#include "GParticleAttributeIndex_t.h"

class GCParticleFloatInput
{
private:
    void *m_ptr;

public:
    GCParticleFloatInput() {}
    GCParticleFloatInput(void *ptr) : m_ptr(ptr) {}

    ParticleFloatType_t GetType() const { return GetSchemaValue<ParticleFloatType_t>(m_ptr, "CParticleFloatInput", "m_nType"); }
    void SetType(ParticleFloatType_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nType", false, value); }
    ParticleFloatMapType_t GetMapType() const { return GetSchemaValue<ParticleFloatMapType_t>(m_ptr, "CParticleFloatInput", "m_nMapType"); }
    void SetMapType(ParticleFloatMapType_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nMapType", false, value); }
    float GetLiteralValue() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLiteralValue"); }
    void SetLiteralValue(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLiteralValue", false, value); }
    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nControlPoint", false, value); }
    GParticleAttributeIndex_t GetScalarAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CParticleFloatInput", "m_nScalarAttribute"); }
    void SetScalarAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nScalarAttribute", false, value); }
    GParticleAttributeIndex_t GetVectorAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CParticleFloatInput", "m_nVectorAttribute"); }
    void SetVectorAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nVectorAttribute", false, value); }
    int32_t GetVectorComponent() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nVectorComponent"); }
    void SetVectorComponent(int32_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nVectorComponent", false, value); }
    float GetRandomMin() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flRandomMin"); }
    void SetRandomMin(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flRandomMin", false, value); }
    float GetRandomMax() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flRandomMax"); }
    void SetRandomMax(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flRandomMax", false, value); }
    bool GetHasRandomSignFlip() const { return GetSchemaValue<bool>(m_ptr, "CParticleFloatInput", "m_bHasRandomSignFlip"); }
    void SetHasRandomSignFlip(bool value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_bHasRandomSignFlip", false, value); }
    int32_t GetRandomSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nRandomSeed"); }
    void SetRandomSeed(int32_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nRandomSeed", false, value); }
    ParticleFloatRandomMode_t GetRandomMode() const { return GetSchemaValue<ParticleFloatRandomMode_t>(m_ptr, "CParticleFloatInput", "m_nRandomMode"); }
    void SetRandomMode(ParticleFloatRandomMode_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nRandomMode", false, value); }
    float GetLOD0() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD0"); }
    void SetLOD0(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD0", false, value); }
    float GetLOD1() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD1"); }
    void SetLOD1(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD1", false, value); }
    float GetLOD2() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD2"); }
    void SetLOD2(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD2", false, value); }
    float GetLOD3() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD3"); }
    void SetLOD3(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD3", false, value); }
    GParticleAttributeIndex_t GetNoiseInputVectorAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CParticleFloatInput", "m_nNoiseInputVectorAttribute"); }
    void SetNoiseInputVectorAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseInputVectorAttribute", false, value); }
    float GetNoiseOutputMin() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMin"); }
    void SetNoiseOutputMin(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMin", false, value); }
    float GetNoiseOutputMax() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMax"); }
    void SetNoiseOutputMax(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMax", false, value); }
    float GetNoiseScale() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseScale"); }
    void SetNoiseScale(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseScale", false, value); }
    Vector GetNoiseOffsetRate() const { return GetSchemaValue<Vector>(m_ptr, "CParticleFloatInput", "m_vecNoiseOffsetRate"); }
    void SetNoiseOffsetRate(Vector value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_vecNoiseOffsetRate", false, value); }
    float GetNoiseOffset() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseOffset"); }
    void SetNoiseOffset(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseOffset", false, value); }
    int32_t GetNoiseOctaves() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nNoiseOctaves"); }
    void SetNoiseOctaves(int32_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseOctaves", false, value); }
    PFNoiseTurbulence_t GetNoiseTurbulence() const { return GetSchemaValue<PFNoiseTurbulence_t>(m_ptr, "CParticleFloatInput", "m_nNoiseTurbulence"); }
    void SetNoiseTurbulence(PFNoiseTurbulence_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseTurbulence", false, value); }
    PFNoiseType_t GetNoiseType() const { return GetSchemaValue<PFNoiseType_t>(m_ptr, "CParticleFloatInput", "m_nNoiseType"); }
    void SetNoiseType(PFNoiseType_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseType", false, value); }
    PFNoiseModifier_t GetNoiseModifier() const { return GetSchemaValue<PFNoiseModifier_t>(m_ptr, "CParticleFloatInput", "m_nNoiseModifier"); }
    void SetNoiseModifier(PFNoiseModifier_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseModifier", false, value); }
    float GetNoiseTurbulenceScale() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceScale"); }
    void SetNoiseTurbulenceScale(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceScale", false, value); }
    float GetNoiseTurbulenceMix() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceMix"); }
    void SetNoiseTurbulenceMix(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceMix", false, value); }
    float GetNoiseImgPreviewScale() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseImgPreviewScale"); }
    void SetNoiseImgPreviewScale(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseImgPreviewScale", false, value); }
    bool GetNoiseImgPreviewLive() const { return GetSchemaValue<bool>(m_ptr, "CParticleFloatInput", "m_bNoiseImgPreviewLive"); }
    void SetNoiseImgPreviewLive(bool value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_bNoiseImgPreviewLive", false, value); }
    float GetNoCameraFallback() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoCameraFallback"); }
    void SetNoCameraFallback(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoCameraFallback", false, value); }
    bool GetUseBoundsCenter() const { return GetSchemaValue<bool>(m_ptr, "CParticleFloatInput", "m_bUseBoundsCenter"); }
    void SetUseBoundsCenter(bool value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_bUseBoundsCenter", false, value); }
    ParticleFloatInputMode_t GetInputMode() const { return GetSchemaValue<ParticleFloatInputMode_t>(m_ptr, "CParticleFloatInput", "m_nInputMode"); }
    void SetInputMode(ParticleFloatInputMode_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nInputMode", false, value); }
    float GetMultFactor() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flMultFactor"); }
    void SetMultFactor(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flMultFactor", false, value); }
    float GetInput0() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flInput0"); }
    void SetInput0(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flInput0", false, value); }
    float GetInput1() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flInput1"); }
    void SetInput1(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flInput1", false, value); }
    float GetOutput0() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flOutput0"); }
    void SetOutput0(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flOutput0", false, value); }
    float GetOutput1() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flOutput1"); }
    void SetOutput1(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flOutput1", false, value); }
    float GetNotchedRangeMin() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMin"); }
    void SetNotchedRangeMin(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMin", false, value); }
    float GetNotchedRangeMax() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMax"); }
    void SetNotchedRangeMax(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMax", false, value); }
    float GetNotchedOutputOutside() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedOutputOutside"); }
    void SetNotchedOutputOutside(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedOutputOutside", false, value); }
    float GetNotchedOutputInside() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedOutputInside"); }
    void SetNotchedOutputInside(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedOutputInside", false, value); }
    ParticleFloatBiasType_t GetBiasType() const { return GetSchemaValue<ParticleFloatBiasType_t>(m_ptr, "CParticleFloatInput", "m_nBiasType"); }
    void SetBiasType(ParticleFloatBiasType_t value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nBiasType", false, value); }
    float GetBiasParameter() const { return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flBiasParameter"); }
    void SetBiasParameter(float value) { SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flBiasParameter", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif