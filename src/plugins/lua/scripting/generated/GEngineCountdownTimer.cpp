#include "../../../core/scripting/generated/classes/GEngineCountdownTimer.h"
#include "../core.h"

void SetupLuaClassGEngineCountdownTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEngineCountdownTimer>("EngineCountdownTimer")
        .addProperty("Duration", &GEngineCountdownTimer::GetDuration, &GEngineCountdownTimer::SetDuration)
        .addProperty("Timestamp", &GEngineCountdownTimer::GetTimestamp, &GEngineCountdownTimer::SetTimestamp)
        .addProperty("Timescale", &GEngineCountdownTimer::GetTimescale, &GEngineCountdownTimer::SetTimescale)
        .endClass();
}