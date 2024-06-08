#include "../../../core/scripting/generated/classes/GCBaseGrenade.h"
#include "../core.h"

void SetupLuaClassGCBaseGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseGrenade>("CBaseGrenade")
        .addProperty("OnPlayerPickup", &GCBaseGrenade::GetOnPlayerPickup, &GCBaseGrenade::SetOnPlayerPickup)
        .addProperty("OnExplode", &GCBaseGrenade::GetOnExplode, &GCBaseGrenade::SetOnExplode)
        .addProperty("HasWarnedAI", &GCBaseGrenade::GetHasWarnedAI, &GCBaseGrenade::SetHasWarnedAI)
        .addProperty("IsSmokeGrenade", &GCBaseGrenade::GetIsSmokeGrenade, &GCBaseGrenade::SetIsSmokeGrenade)
        .addProperty("IsLive", &GCBaseGrenade::GetIsLive, &GCBaseGrenade::SetIsLive)
        .addProperty("DmgRadius", &GCBaseGrenade::GetDmgRadius, &GCBaseGrenade::SetDmgRadius)
        .addProperty("WarnAITime", &GCBaseGrenade::GetWarnAITime, &GCBaseGrenade::SetWarnAITime)
        .addProperty("Damage", &GCBaseGrenade::GetDamage, &GCBaseGrenade::SetDamage)
        .addProperty("BounceSound", &GCBaseGrenade::GetBounceSound, &GCBaseGrenade::SetBounceSound)
        .addProperty("ExplosionSound", &GCBaseGrenade::GetExplosionSound, &GCBaseGrenade::SetExplosionSound)
        .addProperty("Thrower", &GCBaseGrenade::GetThrower, &GCBaseGrenade::SetThrower)
        .addProperty("OriginalThrower", &GCBaseGrenade::GetOriginalThrower, &GCBaseGrenade::SetOriginalThrower)
        .endClass();
}