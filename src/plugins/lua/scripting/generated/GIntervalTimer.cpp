#include "../../../core/scripting/generated/classes/GIntervalTimer.h"
#include "../core.h"

void SetupLuaClassGIntervalTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIntervalTimer>("IntervalTimer")
        .addProperty("WorldGroupId", &GIntervalTimer::GetWorldGroupId, &GIntervalTimer::SetWorldGroupId)
        .endClass();
}