class GC_INIT_PositionPlaceOnGround;

#ifndef _gcc_init_positionplaceonground_h
#define _gcc_init_positionplaceonground_h

#include "../../../scripting.h"

#include "../types/GParticleTraceSet_t.h"
#include "../types/GParticleTraceMissBehavior_t.h"
#include "GCPerParticleFloatInput.h"

class GC_INIT_PositionPlaceOnGround
{
private:
    void *m_ptr;

public:
    GC_INIT_PositionPlaceOnGround() {}
    GC_INIT_PositionPlaceOnGround(void *ptr) : m_ptr(ptr) {}

    GCPerParticleFloatInput GetOffset() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_flOffset"); }
    void SetOffset(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_flOffset", false, value); }
    GCPerParticleFloatInput GetMaxTraceLength() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_flMaxTraceLength"); }
    void SetMaxTraceLength(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_flMaxTraceLength", false, value); }
    std::string GetCollisionGroupName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_CollisionGroupName"); }
    void SetCollisionGroupName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_CollisionGroupName", false, value); }
    ParticleTraceSet_t GetTraceSet() const { return GetSchemaValue<ParticleTraceSet_t>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nTraceSet"); }
    void SetTraceSet(ParticleTraceSet_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nTraceSet", false, value); }
    ParticleTraceMissBehavior_t GetTraceMissBehavior() const { return GetSchemaValue<ParticleTraceMissBehavior_t>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nTraceMissBehavior"); }
    void SetTraceMissBehavior(ParticleTraceMissBehavior_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nTraceMissBehavior", false, value); }
    bool GetIncludeWater() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bIncludeWater"); }
    void SetIncludeWater(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bIncludeWater", false, value); }
    bool GetSetNormal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bSetNormal"); }
    void SetSetNormal(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bSetNormal", false, value); }
    bool GetSetPXYZOnly() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bSetPXYZOnly"); }
    void SetSetPXYZOnly(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bSetPXYZOnly", false, value); }
    bool GetTraceAlongNormal() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bTraceAlongNormal"); }
    void SetTraceAlongNormal(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bTraceAlongNormal", false, value); }
    bool GetOffsetonColOnly() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bOffsetonColOnly"); }
    void SetOffsetonColOnly(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_bOffsetonColOnly", false, value); }
    float GetOffsetByRadiusFactor() const { return GetSchemaValue<float>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_flOffsetByRadiusFactor"); }
    void SetOffsetByRadiusFactor(float value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_flOffsetByRadiusFactor", false, value); }
    int32_t GetPreserveOffsetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nPreserveOffsetCP"); }
    void SetPreserveOffsetCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nPreserveOffsetCP", false, value); }
    int32_t GetIgnoreCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nIgnoreCP"); }
    void SetIgnoreCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionPlaceOnGround", "m_nIgnoreCP", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif