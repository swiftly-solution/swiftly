#include "../../../core/scripting/generated/classes/GSceneEventId_t.h"
#include "../core.h"

void SetupLuaClassGSceneEventId_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSceneEventId_t>("SceneEventId_t")
        .addProperty("Value", &GSceneEventId_t::GetValue, &GSceneEventId_t::SetValue)
        .endClass();
}