class GC_INIT_CreateOnModelAtHeight;

#ifndef _gcc_init_createonmodelatheight_h
#define _gcc_init_createonmodelatheight_h

#include "../../../scripting.h"

#include "../types/GParticleHitboxBiasType_t.h"
#include "GCParticleCollectionFloatInput.h"

class GC_INIT_CreateOnModelAtHeight
{
private:
    void *m_ptr;

public:
    GC_INIT_CreateOnModelAtHeight() {}
    GC_INIT_CreateOnModelAtHeight(void *ptr) : m_ptr(ptr) {}

    bool GetUseBones() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bUseBones"); }
    void SetUseBones(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bUseBones", false, value); }
    bool GetForceZ() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bForceZ"); }
    void SetForceZ(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bForceZ", false, value); }
    int32_t GetControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_nControlPointNumber"); }
    void SetControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_nControlPointNumber", false, value); }
    int32_t GetHeightCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_nHeightCP"); }
    void SetHeightCP(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_nHeightCP", false, value); }
    bool GetUseWaterHeight() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bUseWaterHeight"); }
    void SetUseWaterHeight(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bUseWaterHeight", false, value); }
    GCParticleCollectionFloatInput GetDesiredHeight() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_flDesiredHeight"); }
    void SetDesiredHeight(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_flDesiredHeight", false, value); }
    ParticleHitboxBiasType_t GetBiasType() const { return GetSchemaValue<ParticleHitboxBiasType_t>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_nBiasType"); }
    void SetBiasType(ParticleHitboxBiasType_t value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_nBiasType", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bLocalCoords", false, value); }
    bool GetPreferMovingBoxes() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bPreferMovingBoxes"); }
    void SetPreferMovingBoxes(bool value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_bPreferMovingBoxes", false, value); }
    std::string GetHitboxSetName() const { return GetSchemaValue<char*>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_HitboxSetName"); }
    void SetHitboxSetName(std::string value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_HitboxSetName", false, value); }
    GCParticleCollectionFloatInput GetHitboxVelocityScale() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_flHitboxVelocityScale"); }
    void SetHitboxVelocityScale(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_flHitboxVelocityScale", false, value); }
    GCParticleCollectionFloatInput GetMaxBoneVelocity() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_flMaxBoneVelocity"); }
    void SetMaxBoneVelocity(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_INIT_CreateOnModelAtHeight", "m_flMaxBoneVelocity", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif