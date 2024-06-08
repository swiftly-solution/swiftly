class GC_OP_MovementPlaceOnGround;

#ifndef _gcc_op_movementplaceonground_h
#define _gcc_op_movementplaceonground_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "../types/GParticleTraceMissBehavior_t.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_MovementPlaceOnGround
{
private:
    void *m_ptr;

public:
    GC_OP_MovementPlaceOnGround() {}
    GC_OP_MovementPlaceOnGround(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetOffset() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_MovementPlaceOnGround", "m_flOffset"); }
    void SetOffset(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_flOffset", false, value); }
    float GetMaxTraceLength() const { return GetSchemaValue<float>(m_ptr, "C_OP_MovementPlaceOnGround", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(float value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_flMaxTraceLength", false, value); }
    float GetTolerance() const { return GetSchemaValue<float>(m_ptr, "C_OP_MovementPlaceOnGround", "m_flTolerance"); }
    void SetTolerance(float value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_flTolerance", false, value); }
    float GetTraceOffset() const { return GetSchemaValue<float>(m_ptr, "C_OP_MovementPlaceOnGround", "m_flTraceOffset"); }
    void SetTraceOffset(float value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_flTraceOffset", false, value); }
    float GetLerpRate() const { return GetSchemaValue<float>(m_ptr, "C_OP_MovementPlaceOnGround", "m_flLerpRate"); }
    void SetLerpRate(float value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_flLerpRate", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_OP_MovementPlaceOnGround", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nTraceSet", false, value); }
    int32_t GetRefCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nRefCP1"); }
    void SetRefCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nRefCP1", false, value); }
    int32_t GetRefCP2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nRefCP2"); }
    void SetRefCP2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nRefCP2", false, value); }
    int32_t GetLerpCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nLerpCP"); }
    void SetLerpCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nLerpCP", false, value); }
    ParticleTraceMissBehavior_t GetTraceMissBehavior() const { return GetSchemaValue<ParticleTraceMissBehavior_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nTraceMissBehavior"); }
    void SetTraceMissBehavior(ParticleTraceMissBehavior_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nTraceMissBehavior", false, value); }
    bool GetIncludeShotHull() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementPlaceOnGround", "m_bIncludeShotHull"); }
    void SetIncludeShotHull(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_bIncludeShotHull", false, value); }
    bool GetIncludeWater() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementPlaceOnGround", "m_bIncludeWater"); }
    void SetIncludeWater(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_bIncludeWater", false, value); }
    bool GetSetNormal() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementPlaceOnGround", "m_bSetNormal"); }
    void SetSetNormal(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_bSetNormal", false, value); }
    bool GetScaleOffset() const { return GetSchemaValue<bool>(m_ptr, "C_OP_MovementPlaceOnGround", "m_bScaleOffset"); }
    void SetScaleOffset(bool value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_bScaleOffset", false, value); }
    int32_t GetPreserveOffsetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nPreserveOffsetCP"); }
    void SetPreserveOffsetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nPreserveOffsetCP", false, value); }
    int32_t GetIgnoreCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_MovementPlaceOnGround", "m_nIgnoreCP"); }
    void SetIgnoreCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_MovementPlaceOnGround", "m_nIgnoreCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif