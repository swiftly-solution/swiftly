#include "../../../core/scripting/generated/classes/GEventClientFrameSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventClientFrameSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientFrameSimulate_t>("EventClientFrameSimulate_t")
        .addProperty("LoopState", &GEventClientFrameSimulate_t::GetLoopState, &GEventClientFrameSimulate_t::SetLoopState)
        .addProperty("RealTime", &GEventClientFrameSimulate_t::GetRealTime, &GEventClientFrameSimulate_t::SetRealTime)
        .addProperty("FrameTime", &GEventClientFrameSimulate_t::GetFrameTime, &GEventClientFrameSimulate_t::SetFrameTime)
        .addProperty("WhenScheduleSendTickPacket", &GEventClientFrameSimulate_t::GetWhenScheduleSendTickPacket, &GEventClientFrameSimulate_t::SetWhenScheduleSendTickPacket)
        .endClass();
}