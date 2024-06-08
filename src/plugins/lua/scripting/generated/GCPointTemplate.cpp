#include "../../../core/scripting/generated/classes/GCPointTemplate.h"
#include "../core.h"

void SetupLuaClassGCPointTemplate(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointTemplate>("CPointTemplate")
        .addProperty("WorldName", &GCPointTemplate::GetWorldName, &GCPointTemplate::SetWorldName)
        .addProperty("Source2EntityLumpName", &GCPointTemplate::GetSource2EntityLumpName, &GCPointTemplate::SetSource2EntityLumpName)
        .addProperty("EntityFilterName", &GCPointTemplate::GetEntityFilterName, &GCPointTemplate::SetEntityFilterName)
        .addProperty("TimeoutInterval", &GCPointTemplate::GetTimeoutInterval, &GCPointTemplate::SetTimeoutInterval)
        .addProperty("AsynchronouslySpawnEntities", &GCPointTemplate::GetAsynchronouslySpawnEntities, &GCPointTemplate::SetAsynchronouslySpawnEntities)
        .addProperty("OutputOnSpawned", &GCPointTemplate::GetOutputOnSpawned, &GCPointTemplate::SetOutputOnSpawned)
        .addProperty("ClientOnlyEntityBehavior", &GCPointTemplate::GetClientOnlyEntityBehavior, &GCPointTemplate::SetClientOnlyEntityBehavior)
        .addProperty("OwnerSpawnGroupType", &GCPointTemplate::GetOwnerSpawnGroupType, &GCPointTemplate::SetOwnerSpawnGroupType)
        .addProperty("CreatedSpawnGroupHandles", &GCPointTemplate::GetCreatedSpawnGroupHandles, &GCPointTemplate::SetCreatedSpawnGroupHandles)
        .addProperty("SpawnedEntityHandles", &GCPointTemplate::GetSpawnedEntityHandles, &GCPointTemplate::SetSpawnedEntityHandles)
        .endClass();
}