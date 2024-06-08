#include "../../../core/scripting/generated/classes/GEventClientSceneSystemThreadStateChange_t.h"
#include "../core.h"

void SetupLuaClassGEventClientSceneSystemThreadStateChange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientSceneSystemThreadStateChange_t>("EventClientSceneSystemThreadStateChange_t")
        .addProperty("ThreadsActive", &GEventClientSceneSystemThreadStateChange_t::GetThreadsActive, &GEventClientSceneSystemThreadStateChange_t::SetThreadsActive)
        .endClass();
}