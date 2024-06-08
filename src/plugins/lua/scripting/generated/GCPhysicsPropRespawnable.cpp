#include "../../../core/scripting/generated/classes/GCPhysicsPropRespawnable.h"
#include "../core.h"

void SetupLuaClassGCPhysicsPropRespawnable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsPropRespawnable>("CPhysicsPropRespawnable")
        .addProperty("OriginalSpawnOrigin", &GCPhysicsPropRespawnable::GetOriginalSpawnOrigin, &GCPhysicsPropRespawnable::SetOriginalSpawnOrigin)
        .addProperty("OriginalSpawnAngles", &GCPhysicsPropRespawnable::GetOriginalSpawnAngles, &GCPhysicsPropRespawnable::SetOriginalSpawnAngles)
        .addProperty("OriginalMins", &GCPhysicsPropRespawnable::GetOriginalMins, &GCPhysicsPropRespawnable::SetOriginalMins)
        .addProperty("OriginalMaxs", &GCPhysicsPropRespawnable::GetOriginalMaxs, &GCPhysicsPropRespawnable::SetOriginalMaxs)
        .addProperty("RespawnDuration", &GCPhysicsPropRespawnable::GetRespawnDuration, &GCPhysicsPropRespawnable::SetRespawnDuration)
        .endClass();
}