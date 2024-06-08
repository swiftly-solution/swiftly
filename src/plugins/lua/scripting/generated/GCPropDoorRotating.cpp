#include "../../../core/scripting/generated/classes/GCPropDoorRotating.h"
#include "../core.h"

void SetupLuaClassGCPropDoorRotating(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPropDoorRotating>("CPropDoorRotating")
        .addProperty("Axis", &GCPropDoorRotating::GetAxis, &GCPropDoorRotating::SetAxis)
        .addProperty("Distance", &GCPropDoorRotating::GetDistance, &GCPropDoorRotating::SetDistance)
        .addProperty("SpawnPosition", &GCPropDoorRotating::GetSpawnPosition, &GCPropDoorRotating::SetSpawnPosition)
        .addProperty("OpenDirection", &GCPropDoorRotating::GetOpenDirection, &GCPropDoorRotating::SetOpenDirection)
        .addProperty("CurrentOpenDirection", &GCPropDoorRotating::GetCurrentOpenDirection, &GCPropDoorRotating::SetCurrentOpenDirection)
        .addProperty("AjarAngle", &GCPropDoorRotating::GetAjarAngle, &GCPropDoorRotating::SetAjarAngle)
        .addProperty("RotationAjarDeprecated", &GCPropDoorRotating::GetRotationAjarDeprecated, &GCPropDoorRotating::SetRotationAjarDeprecated)
        .addProperty("RotationClosed", &GCPropDoorRotating::GetRotationClosed, &GCPropDoorRotating::SetRotationClosed)
        .addProperty("RotationOpenForward", &GCPropDoorRotating::GetRotationOpenForward, &GCPropDoorRotating::SetRotationOpenForward)
        .addProperty("RotationOpenBack", &GCPropDoorRotating::GetRotationOpenBack, &GCPropDoorRotating::SetRotationOpenBack)
        .addProperty("Goal", &GCPropDoorRotating::GetGoal, &GCPropDoorRotating::SetGoal)
        .addProperty("ForwardBoundsMin", &GCPropDoorRotating::GetForwardBoundsMin, &GCPropDoorRotating::SetForwardBoundsMin)
        .addProperty("ForwardBoundsMax", &GCPropDoorRotating::GetForwardBoundsMax, &GCPropDoorRotating::SetForwardBoundsMax)
        .addProperty("BackBoundsMin", &GCPropDoorRotating::GetBackBoundsMin, &GCPropDoorRotating::SetBackBoundsMin)
        .addProperty("BackBoundsMax", &GCPropDoorRotating::GetBackBoundsMax, &GCPropDoorRotating::SetBackBoundsMax)
        .addProperty("AjarDoorShouldntAlwaysOpen", &GCPropDoorRotating::GetAjarDoorShouldntAlwaysOpen, &GCPropDoorRotating::SetAjarDoorShouldntAlwaysOpen)
        .addProperty("EntityBlocker", &GCPropDoorRotating::GetEntityBlocker, &GCPropDoorRotating::SetEntityBlocker)
        .endClass();
}