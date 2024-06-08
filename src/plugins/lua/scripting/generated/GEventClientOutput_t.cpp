#include "../../../core/scripting/generated/classes/GEventClientOutput_t.h"
#include "../core.h"

void SetupLuaClassGEventClientOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientOutput_t>("EventClientOutput_t")
        .addProperty("LoopState", &GEventClientOutput_t::GetLoopState, &GEventClientOutput_t::SetLoopState)
        .addProperty("RenderTime", &GEventClientOutput_t::GetRenderTime, &GEventClientOutput_t::SetRenderTime)
        .addProperty("RealTime", &GEventClientOutput_t::GetRealTime, &GEventClientOutput_t::SetRealTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventClientOutput_t::GetRenderFrameTimeUnbounded, &GEventClientOutput_t::SetRenderFrameTimeUnbounded)
        .addProperty("RenderOnly", &GEventClientOutput_t::GetRenderOnly, &GEventClientOutput_t::SetRenderOnly)
        .endClass();
}