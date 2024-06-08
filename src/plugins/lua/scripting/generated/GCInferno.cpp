#include "../../../core/scripting/generated/classes/GCInferno.h"
#include "../core.h"

void SetupLuaClassGCInferno(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInferno>("CInferno")
        .addProperty("FirePositions", &GCInferno::GetFirePositions, &GCInferno::SetFirePositions)
        .addProperty("FireParentPositions", &GCInferno::GetFireParentPositions, &GCInferno::SetFireParentPositions)
        .addProperty("FireIsBurning", &GCInferno::GetFireIsBurning, &GCInferno::SetFireIsBurning)
        .addProperty("BurnNormal", &GCInferno::GetBurnNormal, &GCInferno::SetBurnNormal)
        .addProperty("FireCount", &GCInferno::GetFireCount, &GCInferno::SetFireCount)
        .addProperty("InfernoType", &GCInferno::GetInfernoType, &GCInferno::SetInfernoType)
        .addProperty("FireEffectTickBegin", &GCInferno::GetFireEffectTickBegin, &GCInferno::SetFireEffectTickBegin)
        .addProperty("FireLifetime", &GCInferno::GetFireLifetime, &GCInferno::SetFireLifetime)
        .addProperty("InPostEffectTime", &GCInferno::GetInPostEffectTime, &GCInferno::SetInPostEffectTime)
        .addProperty("FiresExtinguishCount", &GCInferno::GetFiresExtinguishCount, &GCInferno::SetFiresExtinguishCount)
        .addProperty("WasCreatedInSmoke", &GCInferno::GetWasCreatedInSmoke, &GCInferno::SetWasCreatedInSmoke)
        .addProperty("Extent", &GCInferno::GetExtent, &GCInferno::SetExtent)
        .addProperty("DamageTimer", &GCInferno::GetDamageTimer, &GCInferno::SetDamageTimer)
        .addProperty("DamageRampTimer", &GCInferno::GetDamageRampTimer, &GCInferno::SetDamageRampTimer)
        .addProperty("SplashVelocity", &GCInferno::GetSplashVelocity, &GCInferno::SetSplashVelocity)
        .addProperty("InitialSplashVelocity", &GCInferno::GetInitialSplashVelocity, &GCInferno::SetInitialSplashVelocity)
        .addProperty("StartPos", &GCInferno::GetStartPos, &GCInferno::SetStartPos)
        .addProperty("OriginalSpawnLocation", &GCInferno::GetOriginalSpawnLocation, &GCInferno::SetOriginalSpawnLocation)
        .addProperty("ActiveTimer", &GCInferno::GetActiveTimer, &GCInferno::SetActiveTimer)
        .addProperty("FireSpawnOffset", &GCInferno::GetFireSpawnOffset, &GCInferno::SetFireSpawnOffset)
        .addProperty("MaxFlames", &GCInferno::GetMaxFlames, &GCInferno::SetMaxFlames)
        .addProperty("SpreadCount", &GCInferno::GetSpreadCount, &GCInferno::SetSpreadCount)
        .addProperty("BookkeepingTimer", &GCInferno::GetBookkeepingTimer, &GCInferno::SetBookkeepingTimer)
        .addProperty("NextSpreadTimer", &GCInferno::GetNextSpreadTimer, &GCInferno::SetNextSpreadTimer)
        .addProperty("SourceItemDefIndex", &GCInferno::GetSourceItemDefIndex, &GCInferno::SetSourceItemDefIndex)
        .endClass();
}