class GCBasePlayerVData;

#ifndef _gccbaseplayervdata_h
#define _gccbaseplayervdata_h

#include "../../../scripting.h"


#include "GCSkillFloat.h"

class GCBasePlayerVData
{
private:
    void *m_ptr;

public:
    GCBasePlayerVData() {}
    GCBasePlayerVData(void *ptr) : m_ptr(ptr) {}

    GCSkillFloat GetHeadDamageMultiplier() const { return GetSchemaValue<GCSkillFloat>(m_ptr, "CBasePlayerVData", "m_flHeadDamageMultiplier"); }
    void SetHeadDamageMultiplier(GCSkillFloat value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flHeadDamageMultiplier", false, value); }
    GCSkillFloat GetChestDamageMultiplier() const { return GetSchemaValue<GCSkillFloat>(m_ptr, "CBasePlayerVData", "m_flChestDamageMultiplier"); }
    void SetChestDamageMultiplier(GCSkillFloat value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flChestDamageMultiplier", false, value); }
    GCSkillFloat GetStomachDamageMultiplier() const { return GetSchemaValue<GCSkillFloat>(m_ptr, "CBasePlayerVData", "m_flStomachDamageMultiplier"); }
    void SetStomachDamageMultiplier(GCSkillFloat value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flStomachDamageMultiplier", false, value); }
    GCSkillFloat GetArmDamageMultiplier() const { return GetSchemaValue<GCSkillFloat>(m_ptr, "CBasePlayerVData", "m_flArmDamageMultiplier"); }
    void SetArmDamageMultiplier(GCSkillFloat value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flArmDamageMultiplier", false, value); }
    GCSkillFloat GetLegDamageMultiplier() const { return GetSchemaValue<GCSkillFloat>(m_ptr, "CBasePlayerVData", "m_flLegDamageMultiplier"); }
    void SetLegDamageMultiplier(GCSkillFloat value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flLegDamageMultiplier", false, value); }
    float GetHoldBreathTime() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flHoldBreathTime"); }
    void SetHoldBreathTime(float value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flHoldBreathTime", false, value); }
    float GetDrowningDamageInterval() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flDrowningDamageInterval"); }
    void SetDrowningDamageInterval(float value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flDrowningDamageInterval", false, value); }
    int32_t GetDrowningDamageInitial() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerVData", "m_nDrowningDamageInitial"); }
    void SetDrowningDamageInitial(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_nDrowningDamageInitial", false, value); }
    int32_t GetDrowningDamageMax() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerVData", "m_nDrowningDamageMax"); }
    void SetDrowningDamageMax(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_nDrowningDamageMax", false, value); }
    int32_t GetWaterSpeed() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerVData", "m_nWaterSpeed"); }
    void SetWaterSpeed(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_nWaterSpeed", false, value); }
    float GetUseRange() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flUseRange"); }
    void SetUseRange(float value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flUseRange", false, value); }
    float GetUseAngleTolerance() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flUseAngleTolerance"); }
    void SetUseAngleTolerance(float value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flUseAngleTolerance", false, value); }
    float GetCrouchTime() const { return GetSchemaValue<float>(m_ptr, "CBasePlayerVData", "m_flCrouchTime"); }
    void SetCrouchTime(float value) { SetSchemaValue(m_ptr, "CBasePlayerVData", "m_flCrouchTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif