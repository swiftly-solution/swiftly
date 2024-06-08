class GCParticleVecInput;

#ifndef _gccparticlevecinput_h
#define _gccparticlevecinput_h

#include "../../../scripting.h"

#include "../types/GParticleVecType_t.h"
#include "GParticleAttributeIndex_t.h"
#include "GCParticleFloatInput.h"

class GCParticleVecInput
{
private:
    void *m_ptr;

public:
    GCParticleVecInput() {}
    GCParticleVecInput(void *ptr) : m_ptr(ptr) {}

    ParticleVecType_t GetType() const { return GetSchemaValue<ParticleVecType_t>(m_ptr, "CParticleVecInput", "m_nType"); }
    void SetType(ParticleVecType_t value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_nType", false, value); }
    Vector GetLiteralValue() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vLiteralValue"); }
    void SetLiteralValue(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vLiteralValue", false, value); }
    Color GetLiteralColor() const { return GetSchemaValue<Color>(m_ptr, "CParticleVecInput", "m_LiteralColor"); }
    void SetLiteralColor(Color value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_LiteralColor", false, value); }
    bool GetFollowNamedValue() const { return GetSchemaValue<bool>(m_ptr, "CParticleVecInput", "m_bFollowNamedValue"); }
    void SetFollowNamedValue(bool value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_bFollowNamedValue", false, value); }
    GParticleAttributeIndex_t GetVectorAttribute() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "CParticleVecInput", "m_nVectorAttribute"); }
    void SetVectorAttribute(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_nVectorAttribute", false, value); }
    Vector GetVectorAttributeScale() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vVectorAttributeScale"); }
    void SetVectorAttributeScale(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vVectorAttributeScale", false, value); }
    int32_t GetControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleVecInput", "m_nControlPoint"); }
    void SetControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_nControlPoint", false, value); }
    int32_t GetDeltaControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleVecInput", "m_nDeltaControlPoint"); }
    void SetDeltaControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_nDeltaControlPoint", false, value); }
    Vector GetCPValueScale() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vCPValueScale"); }
    void SetCPValueScale(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vCPValueScale", false, value); }
    Vector GetCPRelativePosition() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vCPRelativePosition"); }
    void SetCPRelativePosition(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vCPRelativePosition", false, value); }
    Vector GetCPRelativeDir() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vCPRelativeDir"); }
    void SetCPRelativeDir(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vCPRelativeDir", false, value); }
    GCParticleFloatInput GetFloatComponentX() const { return GetSchemaValue<GCParticleFloatInput>(m_ptr, "CParticleVecInput", "m_FloatComponentX"); }
    void SetFloatComponentX(GCParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatComponentX", false, value); }
    GCParticleFloatInput GetFloatComponentY() const { return GetSchemaValue<GCParticleFloatInput>(m_ptr, "CParticleVecInput", "m_FloatComponentY"); }
    void SetFloatComponentY(GCParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatComponentY", false, value); }
    GCParticleFloatInput GetFloatComponentZ() const { return GetSchemaValue<GCParticleFloatInput>(m_ptr, "CParticleVecInput", "m_FloatComponentZ"); }
    void SetFloatComponentZ(GCParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatComponentZ", false, value); }
    GCParticleFloatInput GetFloatInterp() const { return GetSchemaValue<GCParticleFloatInput>(m_ptr, "CParticleVecInput", "m_FloatInterp"); }
    void SetFloatInterp(GCParticleFloatInput value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatInterp", false, value); }
    float GetInterpInput0() const { return GetSchemaValue<float>(m_ptr, "CParticleVecInput", "m_flInterpInput0"); }
    void SetInterpInput0(float value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_flInterpInput0", false, value); }
    float GetInterpInput1() const { return GetSchemaValue<float>(m_ptr, "CParticleVecInput", "m_flInterpInput1"); }
    void SetInterpInput1(float value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_flInterpInput1", false, value); }
    Vector GetInterpOutput0() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vInterpOutput0"); }
    void SetInterpOutput0(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vInterpOutput0", false, value); }
    Vector GetInterpOutput1() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vInterpOutput1"); }
    void SetInterpOutput1(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vInterpOutput1", false, value); }
    Vector GetRandomMin() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vRandomMin"); }
    void SetRandomMin(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vRandomMin", false, value); }
    Vector GetRandomMax() const { return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vRandomMax"); }
    void SetRandomMax(Vector value) { SetSchemaValue(m_ptr, "CParticleVecInput", "m_vRandomMax", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif