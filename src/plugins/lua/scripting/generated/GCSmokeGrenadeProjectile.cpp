#include "../../../core/scripting/generated/classes/GCSmokeGrenadeProjectile.h"
#include "../core.h"

void SetupLuaClassGCSmokeGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSmokeGrenadeProjectile>("CSmokeGrenadeProjectile")
        .addProperty("SmokeEffectTickBegin", &GCSmokeGrenadeProjectile::GetSmokeEffectTickBegin, &GCSmokeGrenadeProjectile::SetSmokeEffectTickBegin)
        .addProperty("DidSmokeEffect", &GCSmokeGrenadeProjectile::GetDidSmokeEffect, &GCSmokeGrenadeProjectile::SetDidSmokeEffect)
        .addProperty("RandomSeed", &GCSmokeGrenadeProjectile::GetRandomSeed, &GCSmokeGrenadeProjectile::SetRandomSeed)
        .addProperty("SmokeColor", &GCSmokeGrenadeProjectile::GetSmokeColor, &GCSmokeGrenadeProjectile::SetSmokeColor)
        .addProperty("SmokeDetonationPos", &GCSmokeGrenadeProjectile::GetSmokeDetonationPos, &GCSmokeGrenadeProjectile::SetSmokeDetonationPos)
        .addProperty("VoxelFrameData", &GCSmokeGrenadeProjectile::GetVoxelFrameData, &GCSmokeGrenadeProjectile::SetVoxelFrameData)
        .endClass();
}