#include "../../../core/scripting/generated/classes/GCBasePlayerVData.h"
#include "../core.h"

void SetupLuaClassGCBasePlayerVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerVData>("CBasePlayerVData")
        .addProperty("HeadDamageMultiplier", &GCBasePlayerVData::GetHeadDamageMultiplier, &GCBasePlayerVData::SetHeadDamageMultiplier)
        .addProperty("ChestDamageMultiplier", &GCBasePlayerVData::GetChestDamageMultiplier, &GCBasePlayerVData::SetChestDamageMultiplier)
        .addProperty("StomachDamageMultiplier", &GCBasePlayerVData::GetStomachDamageMultiplier, &GCBasePlayerVData::SetStomachDamageMultiplier)
        .addProperty("ArmDamageMultiplier", &GCBasePlayerVData::GetArmDamageMultiplier, &GCBasePlayerVData::SetArmDamageMultiplier)
        .addProperty("LegDamageMultiplier", &GCBasePlayerVData::GetLegDamageMultiplier, &GCBasePlayerVData::SetLegDamageMultiplier)
        .addProperty("HoldBreathTime", &GCBasePlayerVData::GetHoldBreathTime, &GCBasePlayerVData::SetHoldBreathTime)
        .addProperty("DrowningDamageInterval", &GCBasePlayerVData::GetDrowningDamageInterval, &GCBasePlayerVData::SetDrowningDamageInterval)
        .addProperty("DrowningDamageInitial", &GCBasePlayerVData::GetDrowningDamageInitial, &GCBasePlayerVData::SetDrowningDamageInitial)
        .addProperty("DrowningDamageMax", &GCBasePlayerVData::GetDrowningDamageMax, &GCBasePlayerVData::SetDrowningDamageMax)
        .addProperty("WaterSpeed", &GCBasePlayerVData::GetWaterSpeed, &GCBasePlayerVData::SetWaterSpeed)
        .addProperty("UseRange", &GCBasePlayerVData::GetUseRange, &GCBasePlayerVData::SetUseRange)
        .addProperty("UseAngleTolerance", &GCBasePlayerVData::GetUseAngleTolerance, &GCBasePlayerVData::SetUseAngleTolerance)
        .addProperty("CrouchTime", &GCBasePlayerVData::GetCrouchTime, &GCBasePlayerVData::SetCrouchTime)
        .endClass();
}