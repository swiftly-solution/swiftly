#include "../../../core/scripting/generated/classes/GEventClientProcessGameInput_t.h"
#include "../core.h"

void SetupLuaClassGEventClientProcessGameInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientProcessGameInput_t>("EventClientProcessGameInput_t")
        .addProperty("LoopState", &GEventClientProcessGameInput_t::GetLoopState, &GEventClientProcessGameInput_t::SetLoopState)
        .addProperty("RealTime", &GEventClientProcessGameInput_t::GetRealTime, &GEventClientProcessGameInput_t::SetRealTime)
        .addProperty("FrameTime", &GEventClientProcessGameInput_t::GetFrameTime, &GEventClientProcessGameInput_t::SetFrameTime)
        .endClass();
}