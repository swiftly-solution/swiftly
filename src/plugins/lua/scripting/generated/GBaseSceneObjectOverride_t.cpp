#include "../../../core/scripting/generated/classes/GBaseSceneObjectOverride_t.h"
#include "../core.h"

void SetupLuaClassGBaseSceneObjectOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBaseSceneObjectOverride_t>("BaseSceneObjectOverride_t")
        .addProperty("SceneObjectIndex", &GBaseSceneObjectOverride_t::GetSceneObjectIndex, &GBaseSceneObjectOverride_t::SetSceneObjectIndex)
        .endClass();
}