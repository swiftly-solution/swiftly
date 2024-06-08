#include "../../../core/scripting/generated/classes/GEventSimpleLoopFrameUpdate_t.h"
#include "../core.h"

void SetupLuaClassGEventSimpleLoopFrameUpdate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSimpleLoopFrameUpdate_t>("EventSimpleLoopFrameUpdate_t")
        .addProperty("LoopState", &GEventSimpleLoopFrameUpdate_t::GetLoopState, &GEventSimpleLoopFrameUpdate_t::SetLoopState)
        .addProperty("RealTime", &GEventSimpleLoopFrameUpdate_t::GetRealTime, &GEventSimpleLoopFrameUpdate_t::SetRealTime)
        .addProperty("FrameTime", &GEventSimpleLoopFrameUpdate_t::GetFrameTime, &GEventSimpleLoopFrameUpdate_t::SetFrameTime)
        .endClass();
}