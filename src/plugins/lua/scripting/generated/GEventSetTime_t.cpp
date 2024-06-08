#include "../../../core/scripting/generated/classes/GEventSetTime_t.h"
#include "../core.h"

void SetupLuaClassGEventSetTime_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSetTime_t>("EventSetTime_t")
        .addProperty("LoopState", &GEventSetTime_t::GetLoopState, &GEventSetTime_t::SetLoopState)
        .addProperty("ClientOutputFrames", &GEventSetTime_t::GetClientOutputFrames, &GEventSetTime_t::SetClientOutputFrames)
        .addProperty("RealTime", &GEventSetTime_t::GetRealTime, &GEventSetTime_t::SetRealTime)
        .addProperty("RenderTime", &GEventSetTime_t::GetRenderTime, &GEventSetTime_t::SetRenderTime)
        .addProperty("RenderFrameTime", &GEventSetTime_t::GetRenderFrameTime, &GEventSetTime_t::SetRenderFrameTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventSetTime_t::GetRenderFrameTimeUnbounded, &GEventSetTime_t::SetRenderFrameTimeUnbounded)
        .addProperty("RenderFrameTimeUnscaled", &GEventSetTime_t::GetRenderFrameTimeUnscaled, &GEventSetTime_t::SetRenderFrameTimeUnscaled)
        .addProperty("TickRemainder", &GEventSetTime_t::GetTickRemainder, &GEventSetTime_t::SetTickRemainder)
        .endClass();
}