#include "../../../core/scripting/generated/classes/GCMolotovProjectile.h"
#include "../core.h"

void SetupLuaClassGCMolotovProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMolotovProjectile>("CMolotovProjectile")
        .addProperty("IsIncGrenade", &GCMolotovProjectile::GetIsIncGrenade, &GCMolotovProjectile::SetIsIncGrenade)
        .addProperty("Detonated", &GCMolotovProjectile::GetDetonated, &GCMolotovProjectile::SetDetonated)
        .addProperty("StillTimer", &GCMolotovProjectile::GetStillTimer, &GCMolotovProjectile::SetStillTimer)
        .addProperty("HasBouncedOffPlayer", &GCMolotovProjectile::GetHasBouncedOffPlayer, &GCMolotovProjectile::SetHasBouncedOffPlayer)
        .endClass();
}