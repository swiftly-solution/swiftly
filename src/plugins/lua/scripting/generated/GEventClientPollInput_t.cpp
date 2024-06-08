#include "../../../core/scripting/generated/classes/GEventClientPollInput_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPollInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPollInput_t>("EventClientPollInput_t")
        .addProperty("LoopState", &GEventClientPollInput_t::GetLoopState, &GEventClientPollInput_t::SetLoopState)
        .addProperty("RealTime", &GEventClientPollInput_t::GetRealTime, &GEventClientPollInput_t::SetRealTime)
        .endClass();
}