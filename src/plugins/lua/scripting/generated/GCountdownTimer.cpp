#include "../../../core/scripting/generated/classes/GCountdownTimer.h"
#include "../core.h"

void SetupLuaClassGCountdownTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCountdownTimer>("CountdownTimer")
        .addProperty("Duration", &GCountdownTimer::GetDuration, &GCountdownTimer::SetDuration)
        .addProperty("Timescale", &GCountdownTimer::GetTimescale, &GCountdownTimer::SetTimescale)
        .addProperty("WorldGroupId", &GCountdownTimer::GetWorldGroupId, &GCountdownTimer::SetWorldGroupId)
        .endClass();
}