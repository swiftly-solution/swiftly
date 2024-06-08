#include "../../../core/scripting/generated/classes/GEventSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSimulate_t>("EventSimulate_t")
        .addProperty("LoopState", &GEventSimulate_t::GetLoopState, &GEventSimulate_t::SetLoopState)
        .addProperty("FirstTick", &GEventSimulate_t::GetFirstTick, &GEventSimulate_t::SetFirstTick)
        .addProperty("LastTick", &GEventSimulate_t::GetLastTick, &GEventSimulate_t::SetLastTick)
        .endClass();
}