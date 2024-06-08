#include "../../../core/scripting/generated/classes/GCInfoWorldLayer.h"
#include "../core.h"

void SetupLuaClassGCInfoWorldLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoWorldLayer>("CInfoWorldLayer")
        .addProperty("OutputOnEntitiesSpawned", &GCInfoWorldLayer::GetOutputOnEntitiesSpawned, &GCInfoWorldLayer::SetOutputOnEntitiesSpawned)
        .addProperty("WorldName", &GCInfoWorldLayer::GetWorldName, &GCInfoWorldLayer::SetWorldName)
        .addProperty("LayerName", &GCInfoWorldLayer::GetLayerName, &GCInfoWorldLayer::SetLayerName)
        .addProperty("WorldLayerVisible", &GCInfoWorldLayer::GetWorldLayerVisible, &GCInfoWorldLayer::SetWorldLayerVisible)
        .addProperty("EntitiesSpawned", &GCInfoWorldLayer::GetEntitiesSpawned, &GCInfoWorldLayer::SetEntitiesSpawned)
        .addProperty("CreateAsChildSpawnGroup", &GCInfoWorldLayer::GetCreateAsChildSpawnGroup, &GCInfoWorldLayer::SetCreateAsChildSpawnGroup)
        .addProperty("LayerSpawnGroup", &GCInfoWorldLayer::GetLayerSpawnGroup, &GCInfoWorldLayer::SetLayerSpawnGroup)
        .endClass();
}