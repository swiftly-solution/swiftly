#include "../../../core/scripting/generated/classes/GEngineLoopState_t.h"
#include "../core.h"

void SetupLuaClassGEngineLoopState_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEngineLoopState_t>("EngineLoopState_t")
        .addProperty("PlatWindowWidth", &GEngineLoopState_t::GetPlatWindowWidth, &GEngineLoopState_t::SetPlatWindowWidth)
        .addProperty("PlatWindowHeight", &GEngineLoopState_t::GetPlatWindowHeight, &GEngineLoopState_t::SetPlatWindowHeight)
        .addProperty("RenderWidth", &GEngineLoopState_t::GetRenderWidth, &GEngineLoopState_t::SetRenderWidth)
        .addProperty("RenderHeight", &GEngineLoopState_t::GetRenderHeight, &GEngineLoopState_t::SetRenderHeight)
        .endClass();
}