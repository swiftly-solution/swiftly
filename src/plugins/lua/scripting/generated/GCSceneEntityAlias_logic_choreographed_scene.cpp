#include "../../../core/scripting/generated/classes/GCSceneEntityAlias_logic_choreographed_scene.h"
#include "../core.h"

void SetupLuaClassGCSceneEntityAlias_logic_choreographed_scene(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneEntityAlias_logic_choreographed_scene>("CSceneEntityAlias_logic_choreographed_scene")

        .endClass();
}