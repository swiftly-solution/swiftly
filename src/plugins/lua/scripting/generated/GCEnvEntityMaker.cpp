#include "../../../core/scripting/generated/classes/GCEnvEntityMaker.h"
#include "../core.h"

void SetupLuaClassGCEnvEntityMaker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvEntityMaker>("CEnvEntityMaker")
        .addProperty("EntityMins", &GCEnvEntityMaker::GetEntityMins, &GCEnvEntityMaker::SetEntityMins)
        .addProperty("EntityMaxs", &GCEnvEntityMaker::GetEntityMaxs, &GCEnvEntityMaker::SetEntityMaxs)
        .addProperty("CurrentInstance", &GCEnvEntityMaker::GetCurrentInstance, &GCEnvEntityMaker::SetCurrentInstance)
        .addProperty("CurrentBlocker", &GCEnvEntityMaker::GetCurrentBlocker, &GCEnvEntityMaker::SetCurrentBlocker)
        .addProperty("BlockerOrigin", &GCEnvEntityMaker::GetBlockerOrigin, &GCEnvEntityMaker::SetBlockerOrigin)
        .addProperty("PostSpawnDirection", &GCEnvEntityMaker::GetPostSpawnDirection, &GCEnvEntityMaker::SetPostSpawnDirection)
        .addProperty("PostSpawnDirectionVariance", &GCEnvEntityMaker::GetPostSpawnDirectionVariance, &GCEnvEntityMaker::SetPostSpawnDirectionVariance)
        .addProperty("PostSpawnSpeed", &GCEnvEntityMaker::GetPostSpawnSpeed, &GCEnvEntityMaker::SetPostSpawnSpeed)
        .addProperty("PostSpawnUseAngles", &GCEnvEntityMaker::GetPostSpawnUseAngles, &GCEnvEntityMaker::SetPostSpawnUseAngles)
        .addProperty("Template", &GCEnvEntityMaker::GetTemplate, &GCEnvEntityMaker::SetTemplate)
        .addProperty("OutputOnSpawned", &GCEnvEntityMaker::GetOutputOnSpawned, &GCEnvEntityMaker::SetOutputOnSpawned)
        .addProperty("OutputOnFailedSpawn", &GCEnvEntityMaker::GetOutputOnFailedSpawn, &GCEnvEntityMaker::SetOutputOnFailedSpawn)
        .endClass();
}