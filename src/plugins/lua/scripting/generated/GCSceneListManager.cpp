#include "../../../core/scripting/generated/classes/GCSceneListManager.h"
#include "../core.h"

void SetupLuaClassGCSceneListManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneListManager>("CSceneListManager")
        .addProperty("Scenes", &GCSceneListManager::GetScenes, &GCSceneListManager::SetScenes)
        .addProperty("Scenes1", &GCSceneListManager::GetScenes1, &GCSceneListManager::SetScenes1)
        .endClass();
}