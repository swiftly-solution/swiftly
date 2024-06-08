#include "../../../core/scripting/generated/classes/GCLookComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCLookComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLookComponentUpdater>("CLookComponentUpdater")
        .addProperty("LookHeading", &GCLookComponentUpdater::GetLookHeading, &GCLookComponentUpdater::SetLookHeading)
        .addProperty("LookHeadingVelocity", &GCLookComponentUpdater::GetLookHeadingVelocity, &GCLookComponentUpdater::SetLookHeadingVelocity)
        .addProperty("LookPitch", &GCLookComponentUpdater::GetLookPitch, &GCLookComponentUpdater::SetLookPitch)
        .addProperty("LookDistance", &GCLookComponentUpdater::GetLookDistance, &GCLookComponentUpdater::SetLookDistance)
        .addProperty("LookDirection", &GCLookComponentUpdater::GetLookDirection, &GCLookComponentUpdater::SetLookDirection)
        .addProperty("LookTarget", &GCLookComponentUpdater::GetLookTarget, &GCLookComponentUpdater::SetLookTarget)
        .addProperty("LookTargetWorldSpace", &GCLookComponentUpdater::GetLookTargetWorldSpace, &GCLookComponentUpdater::SetLookTargetWorldSpace)
        .addProperty("NetworkLookTarget", &GCLookComponentUpdater::GetNetworkLookTarget, &GCLookComponentUpdater::SetNetworkLookTarget)
        .endClass();
}