#include "../../../core/scripting/generated/classes/GCCSPlayerResource.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerResource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerResource>("CCSPlayerResource")
        .addProperty("HostageAlive", &GCCSPlayerResource::GetHostageAlive, &GCCSPlayerResource::SetHostageAlive)
        .addProperty("IsHostageFollowingSomeone", &GCCSPlayerResource::GetIsHostageFollowingSomeone, &GCCSPlayerResource::SetIsHostageFollowingSomeone)
        .addProperty("HostageEntityIDs", &GCCSPlayerResource::GetHostageEntityIDs, &GCCSPlayerResource::SetHostageEntityIDs)
        .addProperty("BombsiteCenterA", &GCCSPlayerResource::GetBombsiteCenterA, &GCCSPlayerResource::SetBombsiteCenterA)
        .addProperty("BombsiteCenterB", &GCCSPlayerResource::GetBombsiteCenterB, &GCCSPlayerResource::SetBombsiteCenterB)
        .addProperty("HostageRescueX", &GCCSPlayerResource::GetHostageRescueX, &GCCSPlayerResource::SetHostageRescueX)
        .addProperty("HostageRescueY", &GCCSPlayerResource::GetHostageRescueY, &GCCSPlayerResource::SetHostageRescueY)
        .addProperty("HostageRescueZ", &GCCSPlayerResource::GetHostageRescueZ, &GCCSPlayerResource::SetHostageRescueZ)
        .addProperty("EndMatchNextMapAllVoted", &GCCSPlayerResource::GetEndMatchNextMapAllVoted, &GCCSPlayerResource::SetEndMatchNextMapAllVoted)
        .addProperty("FoundGoalPositions", &GCCSPlayerResource::GetFoundGoalPositions, &GCCSPlayerResource::SetFoundGoalPositions)
        .endClass();
}