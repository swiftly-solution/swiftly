#include "../../../core/scripting/generated/classes/GEventClientProcessInput_t.h"
#include "../core.h"

void SetupLuaClassGEventClientProcessInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientProcessInput_t>("EventClientProcessInput_t")
        .addProperty("LoopState", &GEventClientProcessInput_t::GetLoopState, &GEventClientProcessInput_t::SetLoopState)
        .addProperty("RealTime", &GEventClientProcessInput_t::GetRealTime, &GEventClientProcessInput_t::SetRealTime)
        .addProperty("TickInterval", &GEventClientProcessInput_t::GetTickInterval, &GEventClientProcessInput_t::SetTickInterval)
        .addProperty("TickStartTime", &GEventClientProcessInput_t::GetTickStartTime, &GEventClientProcessInput_t::SetTickStartTime)
        .endClass();
}