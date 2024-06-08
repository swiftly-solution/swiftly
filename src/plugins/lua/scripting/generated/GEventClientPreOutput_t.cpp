#include "../../../core/scripting/generated/classes/GEventClientPreOutput_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPreOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPreOutput_t>("EventClientPreOutput_t")
        .addProperty("LoopState", &GEventClientPreOutput_t::GetLoopState, &GEventClientPreOutput_t::SetLoopState)
        .addProperty("RenderTime", &GEventClientPreOutput_t::GetRenderTime, &GEventClientPreOutput_t::SetRenderTime)
        .addProperty("RenderFrameTime", &GEventClientPreOutput_t::GetRenderFrameTime, &GEventClientPreOutput_t::SetRenderFrameTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventClientPreOutput_t::GetRenderFrameTimeUnbounded, &GEventClientPreOutput_t::SetRenderFrameTimeUnbounded)
        .addProperty("RealTime", &GEventClientPreOutput_t::GetRealTime, &GEventClientPreOutput_t::SetRealTime)
        .addProperty("RenderOnly", &GEventClientPreOutput_t::GetRenderOnly, &GEventClientPreOutput_t::SetRenderOnly)
        .endClass();
}