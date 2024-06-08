#include "../../../core/scripting/generated/classes/GEventFrameBoundary_t.h"
#include "../core.h"

void SetupLuaClassGEventFrameBoundary_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventFrameBoundary_t>("EventFrameBoundary_t")
        .addProperty("FrameTime", &GEventFrameBoundary_t::GetFrameTime, &GEventFrameBoundary_t::SetFrameTime)
        .endClass();
}