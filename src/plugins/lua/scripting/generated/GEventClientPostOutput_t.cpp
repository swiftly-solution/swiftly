#include "../../../core/scripting/generated/classes/GEventClientPostOutput_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPostOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPostOutput_t>("EventClientPostOutput_t")
        .addProperty("LoopState", &GEventClientPostOutput_t::GetLoopState, &GEventClientPostOutput_t::SetLoopState)
        .addProperty("RenderTime", &GEventClientPostOutput_t::GetRenderTime, &GEventClientPostOutput_t::SetRenderTime)
        .addProperty("RenderFrameTime", &GEventClientPostOutput_t::GetRenderFrameTime, &GEventClientPostOutput_t::SetRenderFrameTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventClientPostOutput_t::GetRenderFrameTimeUnbounded, &GEventClientPostOutput_t::SetRenderFrameTimeUnbounded)
        .addProperty("RenderOnly", &GEventClientPostOutput_t::GetRenderOnly, &GEventClientPostOutput_t::SetRenderOnly)
        .endClass();
}