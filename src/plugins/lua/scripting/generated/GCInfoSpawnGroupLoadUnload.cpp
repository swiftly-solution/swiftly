#include "../../../core/scripting/generated/classes/GCInfoSpawnGroupLoadUnload.h"
#include "../core.h"

void SetupLuaClassGCInfoSpawnGroupLoadUnload(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoSpawnGroupLoadUnload>("CInfoSpawnGroupLoadUnload")
        .addProperty("OnSpawnGroupLoadStarted", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupLoadStarted, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupLoadStarted)
        .addProperty("OnSpawnGroupLoadFinished", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupLoadFinished, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupLoadFinished)
        .addProperty("OnSpawnGroupUnloadStarted", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupUnloadStarted, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupUnloadStarted)
        .addProperty("OnSpawnGroupUnloadFinished", &GCInfoSpawnGroupLoadUnload::GetOnSpawnGroupUnloadFinished, &GCInfoSpawnGroupLoadUnload::SetOnSpawnGroupUnloadFinished)
        .addProperty("SpawnGroupName", &GCInfoSpawnGroupLoadUnload::GetSpawnGroupName, &GCInfoSpawnGroupLoadUnload::SetSpawnGroupName)
        .addProperty("SpawnGroupFilterName", &GCInfoSpawnGroupLoadUnload::GetSpawnGroupFilterName, &GCInfoSpawnGroupLoadUnload::SetSpawnGroupFilterName)
        .addProperty("LandmarkName", &GCInfoSpawnGroupLoadUnload::GetLandmarkName, &GCInfoSpawnGroupLoadUnload::SetLandmarkName)
        .addProperty("FixedSpawnGroupName", &GCInfoSpawnGroupLoadUnload::GetFixedSpawnGroupName, &GCInfoSpawnGroupLoadUnload::SetFixedSpawnGroupName)
        .addProperty("TimeoutInterval", &GCInfoSpawnGroupLoadUnload::GetTimeoutInterval, &GCInfoSpawnGroupLoadUnload::SetTimeoutInterval)
        .addProperty("StreamingStarted", &GCInfoSpawnGroupLoadUnload::GetStreamingStarted, &GCInfoSpawnGroupLoadUnload::SetStreamingStarted)
        .addProperty("UnloadingStarted", &GCInfoSpawnGroupLoadUnload::GetUnloadingStarted, &GCInfoSpawnGroupLoadUnload::SetUnloadingStarted)
        .endClass();
}