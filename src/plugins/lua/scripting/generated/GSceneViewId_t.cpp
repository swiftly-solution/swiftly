#include "../../../core/scripting/generated/classes/GSceneViewId_t.h"
#include "../core.h"

void SetupLuaClassGSceneViewId_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSceneViewId_t>("SceneViewId_t")
        .addProperty("ViewId", &GSceneViewId_t::GetViewId, &GSceneViewId_t::SetViewId)
        .addProperty("FrameCount", &GSceneViewId_t::GetFrameCount, &GSceneViewId_t::SetFrameCount)
        .endClass();
}