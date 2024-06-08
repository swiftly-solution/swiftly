#include "../../../core/scripting/generated/classes/GCSimTimer.h"
#include "../core.h"

void SetupLuaClassGCSimTimer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSimTimer>("CSimTimer")
        .addProperty("Interval", &GCSimTimer::GetInterval, &GCSimTimer::SetInterval)
        .endClass();
}