#include "../../../core/scripting/generated/classes/GCBtActionMoveTo.h"
#include "../core.h"

void SetupLuaClassGCBtActionMoveTo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionMoveTo>("CBtActionMoveTo")
        .addProperty("DestinationInputKey", &GCBtActionMoveTo::GetDestinationInputKey, &GCBtActionMoveTo::SetDestinationInputKey)
        .addProperty("HidingSpotInputKey", &GCBtActionMoveTo::GetHidingSpotInputKey, &GCBtActionMoveTo::SetHidingSpotInputKey)
        .addProperty("ThreatInputKey", &GCBtActionMoveTo::GetThreatInputKey, &GCBtActionMoveTo::SetThreatInputKey)
        .addProperty("Destination", &GCBtActionMoveTo::GetDestination, &GCBtActionMoveTo::SetDestination)
        .addProperty("AutoLookAdjust", &GCBtActionMoveTo::GetAutoLookAdjust, &GCBtActionMoveTo::SetAutoLookAdjust)
        .addProperty("ComputePath", &GCBtActionMoveTo::GetComputePath, &GCBtActionMoveTo::SetComputePath)
        .addProperty("DamagingAreasPenaltyCost", &GCBtActionMoveTo::GetDamagingAreasPenaltyCost, &GCBtActionMoveTo::SetDamagingAreasPenaltyCost)
        .addProperty("CheckApproximateCornersTimer", &GCBtActionMoveTo::GetCheckApproximateCornersTimer, &GCBtActionMoveTo::SetCheckApproximateCornersTimer)
        .addProperty("CheckHighPriorityItem", &GCBtActionMoveTo::GetCheckHighPriorityItem, &GCBtActionMoveTo::SetCheckHighPriorityItem)
        .addProperty("RepathTimer", &GCBtActionMoveTo::GetRepathTimer, &GCBtActionMoveTo::SetRepathTimer)
        .addProperty("ArrivalEpsilon", &GCBtActionMoveTo::GetArrivalEpsilon, &GCBtActionMoveTo::SetArrivalEpsilon)
        .addProperty("AdditionalArrivalEpsilon2D", &GCBtActionMoveTo::GetAdditionalArrivalEpsilon2D, &GCBtActionMoveTo::SetAdditionalArrivalEpsilon2D)
        .addProperty("HidingSpotCheckDistanceThreshold", &GCBtActionMoveTo::GetHidingSpotCheckDistanceThreshold, &GCBtActionMoveTo::SetHidingSpotCheckDistanceThreshold)
        .addProperty("NearestAreaDistanceThreshold", &GCBtActionMoveTo::GetNearestAreaDistanceThreshold, &GCBtActionMoveTo::SetNearestAreaDistanceThreshold)
        .endClass();
}