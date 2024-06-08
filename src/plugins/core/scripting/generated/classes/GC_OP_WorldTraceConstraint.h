class GC_OP_WorldTraceConstraint;

#ifndef _gcc_op_worldtraceconstraint_h
#define _gcc_op_worldtraceconstraint_h

#include "../../../scripting.h"

#include "../types/GParticleCollisionMode_t.h"
#include "../types/GParticleTraceSet_t.h"
#include "GCPerParticleFloatInput.h"
#include "GParticleAttributeIndex_t.h"

class GC_OP_WorldTraceConstraint
{
private:
    void *m_ptr;

public:
    GC_OP_WorldTraceConstraint() {}
    GC_OP_WorldTraceConstraint(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nCP", false, value); }
    Vector GetCpOffset() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_WorldTraceConstraint", "m_vecCpOffset"); }
    void SetCpOffset(Vector value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_vecCpOffset", false, value); }
    ParticleCollisionMode_t GetCollisionMode() const { return GetSchemaValue<ParticleCollisionMode_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nCollisionMode"); }
    void SetCollisionMode(ParticleCollisionMode_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nCollisionMode", false, value); }
    ParticleCollisionMode_t GetCollisionModeMin() const { return GetSchemaValue<ParticleCollisionMode_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nCollisionModeMin"); }
    void SetCollisionModeMin(ParticleCollisionMode_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nCollisionModeMin", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nTraceSet", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_WorldTraceConstraint", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_CollisionGroupName", false, value); }
    bool GetWorldOnly() const { return GetSchemaValue<bool>(m_ptr, "C_OP_WorldTraceConstraint", "m_bWorldOnly"); }
    void SetWorldOnly(bool value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_bWorldOnly", false, value); }
    bool GetBrushOnly() const { return GetSchemaValue<bool>(m_ptr, "C_OP_WorldTraceConstraint", "m_bBrushOnly"); }
    void SetBrushOnly(bool value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_bBrushOnly", false, value); }
    bool GetIncludeWater() const { return GetSchemaValue<bool>(m_ptr, "C_OP_WorldTraceConstraint", "m_bIncludeWater"); }
    void SetIncludeWater(bool value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_bIncludeWater", false, value); }
    int32_t GetIgnoreCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nIgnoreCP"); }
    void SetIgnoreCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nIgnoreCP", false, value); }
    float GetCpMovementTolerance() const { return GetSchemaValue<float>(m_ptr, "C_OP_WorldTraceConstraint", "m_flCpMovementTolerance"); }
    void SetCpMovementTolerance(float value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flCpMovementTolerance", false, value); }
    float GetRetestRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_WorldTraceConstraint", "m_flRetestRate"); }
    void SetRetestRate(float value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flRetestRate", false, value); }
    float GetTraceTolerance() const { return GetSchemaValue<float>(m_ptr, "C_OP_WorldTraceConstraint", "m_flTraceTolerance"); }
    void SetTraceTolerance(float value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flTraceTolerance", false, value); }
    float GetCollisionConfirmationSpeed() const { return GetSchemaValue<float>(m_ptr, "C_OP_WorldTraceConstraint", "m_flCollisionConfirmationSpeed"); }
    void SetCollisionConfirmationSpeed(float value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flCollisionConfirmationSpeed", false, value); }
    float GetMaxTracesPerFrame() const { return GetSchemaValue<float>(m_ptr, "C_OP_WorldTraceConstraint", "m_nMaxTracesPerFrame"); }
    void SetMaxTracesPerFrame(float value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nMaxTracesPerFrame", false, value); }
    GCPerParticleFloatInput GetRadiusScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_WorldTraceConstraint", "m_flRadiusScale"); }
    void SetRadiusScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flRadiusScale", false, value); }
    GCPerParticleFloatInput GetBounceAmount() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_WorldTraceConstraint", "m_flBounceAmount"); }
    void SetBounceAmount(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flBounceAmount", false, value); }
    GCPerParticleFloatInput GetSlideAmount() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_WorldTraceConstraint", "m_flSlideAmount"); }
    void SetSlideAmount(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flSlideAmount", false, value); }
    GCPerParticleFloatInput GetRandomDirScale() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_WorldTraceConstraint", "m_flRandomDirScale"); }
    void SetRandomDirScale(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flRandomDirScale", false, value); }
    bool GetDecayBounce() const { return GetSchemaValue<bool>(m_ptr, "C_OP_WorldTraceConstraint", "m_bDecayBounce"); }
    void SetDecayBounce(bool value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_bDecayBounce", false, value); }
    bool GetKillonContact() const { return GetSchemaValue<bool>(m_ptr, "C_OP_WorldTraceConstraint", "m_bKillonContact"); }
    void SetKillonContact(bool value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_bKillonContact", false, value); }
    float GetMinSpeed() const { return GetSchemaValue<float>(m_ptr, "C_OP_WorldTraceConstraint", "m_flMinSpeed"); }
    void SetMinSpeed(float value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flMinSpeed", false, value); }
    bool GetSetNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_WorldTraceConstraint", "m_bSetNormal"); }
    void SetSetNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_bSetNormal", false, value); }
    GParticleAttributeIndex_t GetStickOnCollisionField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nStickOnCollisionField"); }
    void SetStickOnCollisionField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nStickOnCollisionField", false, value); }
    GCPerParticleFloatInput GetStopSpeed() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_WorldTraceConstraint", "m_flStopSpeed"); }
    void SetStopSpeed(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_flStopSpeed", false, value); }
    GParticleAttributeIndex_t GetEntityStickDataField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nEntityStickDataField"); }
    void SetEntityStickDataField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nEntityStickDataField", false, value); }
    GParticleAttributeIndex_t GetEntityStickNormalField() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_WorldTraceConstraint", "m_nEntityStickNormalField"); }
    void SetEntityStickNormalField(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_WorldTraceConstraint", "m_nEntityStickNormalField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif