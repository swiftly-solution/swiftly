#include "../../../core/scripting/generated/classes/GCSceneEventInfo.h"
#include "../core.h"

void SetupLuaClassGCSceneEventInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneEventInfo>("CSceneEventInfo")
        .addProperty("Layer", &GCSceneEventInfo::GetLayer, &GCSceneEventInfo::SetLayer)
        .addProperty("Priority", &GCSceneEventInfo::GetPriority, &GCSceneEventInfo::SetPriority)
        .addProperty("Weight", &GCSceneEventInfo::GetWeight, &GCSceneEventInfo::SetWeight)
        .addProperty("HasArrived", &GCSceneEventInfo::GetHasArrived, &GCSceneEventInfo::SetHasArrived)
        .addProperty("Type", &GCSceneEventInfo::GetType, &GCSceneEventInfo::SetType)
        .addProperty("IsGesture", &GCSceneEventInfo::GetIsGesture, &GCSceneEventInfo::SetIsGesture)
        .addProperty("ShouldRemove", &GCSceneEventInfo::GetShouldRemove, &GCSceneEventInfo::SetShouldRemove)
        .addProperty("Target", &GCSceneEventInfo::GetTarget, &GCSceneEventInfo::SetTarget)
        .addProperty("SceneEventId", &GCSceneEventInfo::GetSceneEventId, &GCSceneEventInfo::SetSceneEventId)
        .addProperty("ClientSide", &GCSceneEventInfo::GetClientSide, &GCSceneEventInfo::SetClientSide)
        .addProperty("Started", &GCSceneEventInfo::GetStarted, &GCSceneEventInfo::SetStarted)
        .endClass();
}