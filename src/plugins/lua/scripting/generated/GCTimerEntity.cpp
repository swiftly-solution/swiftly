#include "../../../core/scripting/generated/classes/GCTimerEntity.h"
#include "../core.h"

void SetupLuaClassGCTimerEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTimerEntity>("CTimerEntity")
        .addProperty("OnTimer", &GCTimerEntity::GetOnTimer, &GCTimerEntity::SetOnTimer)
        .addProperty("OnTimerHigh", &GCTimerEntity::GetOnTimerHigh, &GCTimerEntity::SetOnTimerHigh)
        .addProperty("OnTimerLow", &GCTimerEntity::GetOnTimerLow, &GCTimerEntity::SetOnTimerLow)
        .addProperty("Disabled", &GCTimerEntity::GetDisabled, &GCTimerEntity::SetDisabled)
        .addProperty("InitialDelay", &GCTimerEntity::GetInitialDelay, &GCTimerEntity::SetInitialDelay)
        .addProperty("RefireTime", &GCTimerEntity::GetRefireTime, &GCTimerEntity::SetRefireTime)
        .addProperty("UpDownState", &GCTimerEntity::GetUpDownState, &GCTimerEntity::SetUpDownState)
        .addProperty("UseRandomTime", &GCTimerEntity::GetUseRandomTime, &GCTimerEntity::SetUseRandomTime)
        .addProperty("PauseAfterFiring", &GCTimerEntity::GetPauseAfterFiring, &GCTimerEntity::SetPauseAfterFiring)
        .addProperty("LowerRandomBound", &GCTimerEntity::GetLowerRandomBound, &GCTimerEntity::SetLowerRandomBound)
        .addProperty("UpperRandomBound", &GCTimerEntity::GetUpperRandomBound, &GCTimerEntity::SetUpperRandomBound)
        .addProperty("RemainingTime", &GCTimerEntity::GetRemainingTime, &GCTimerEntity::SetRemainingTime)
        .addProperty("Paused", &GCTimerEntity::GetPaused, &GCTimerEntity::SetPaused)
        .endClass();
}