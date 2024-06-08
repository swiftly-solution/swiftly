#include "../../../core/scripting/generated/classes/GCBaseCSGrenadeProjectile.h"
#include "../core.h"

void SetupLuaClassGCBaseCSGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseCSGrenadeProjectile>("CBaseCSGrenadeProjectile")
        .addProperty("InitialPosition", &GCBaseCSGrenadeProjectile::GetInitialPosition, &GCBaseCSGrenadeProjectile::SetInitialPosition)
        .addProperty("InitialVelocity", &GCBaseCSGrenadeProjectile::GetInitialVelocity, &GCBaseCSGrenadeProjectile::SetInitialVelocity)
        .addProperty("Bounces", &GCBaseCSGrenadeProjectile::GetBounces, &GCBaseCSGrenadeProjectile::SetBounces)
        .addProperty("ExplodeEffectTickBegin", &GCBaseCSGrenadeProjectile::GetExplodeEffectTickBegin, &GCBaseCSGrenadeProjectile::SetExplodeEffectTickBegin)
        .addProperty("ExplodeEffectOrigin", &GCBaseCSGrenadeProjectile::GetExplodeEffectOrigin, &GCBaseCSGrenadeProjectile::SetExplodeEffectOrigin)
        .addProperty("OGSExtraFlags", &GCBaseCSGrenadeProjectile::GetOGSExtraFlags, &GCBaseCSGrenadeProjectile::SetOGSExtraFlags)
        .addProperty("DetonationRecorded", &GCBaseCSGrenadeProjectile::GetDetonationRecorded, &GCBaseCSGrenadeProjectile::SetDetonationRecorded)
        .addProperty("ItemIndex", &GCBaseCSGrenadeProjectile::GetItemIndex, &GCBaseCSGrenadeProjectile::SetItemIndex)
        .addProperty("OriginalSpawnLocation", &GCBaseCSGrenadeProjectile::GetOriginalSpawnLocation, &GCBaseCSGrenadeProjectile::SetOriginalSpawnLocation)
        .addProperty("GrenadeSpin", &GCBaseCSGrenadeProjectile::GetGrenadeSpin, &GCBaseCSGrenadeProjectile::SetGrenadeSpin)
        .addProperty("LastHitSurfaceNormal", &GCBaseCSGrenadeProjectile::GetLastHitSurfaceNormal, &GCBaseCSGrenadeProjectile::SetLastHitSurfaceNormal)
        .addProperty("TicksAtZeroVelocity", &GCBaseCSGrenadeProjectile::GetTicksAtZeroVelocity, &GCBaseCSGrenadeProjectile::SetTicksAtZeroVelocity)
        .addProperty("HasEverHitPlayer", &GCBaseCSGrenadeProjectile::GetHasEverHitPlayer, &GCBaseCSGrenadeProjectile::SetHasEverHitPlayer)
        .addProperty("ClearFromPlayers", &GCBaseCSGrenadeProjectile::GetClearFromPlayers, &GCBaseCSGrenadeProjectile::SetClearFromPlayers)
        .endClass();
}