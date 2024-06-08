#include "../../../core/scripting/generated/classes/GCEnvExplosion.h"
#include "../core.h"

void SetupLuaClassGCEnvExplosion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvExplosion>("CEnvExplosion")
        .addProperty("Magnitude", &GCEnvExplosion::GetMagnitude, &GCEnvExplosion::SetMagnitude)
        .addProperty("PlayerDamage", &GCEnvExplosion::GetPlayerDamage, &GCEnvExplosion::SetPlayerDamage)
        .addProperty("RadiusOverride", &GCEnvExplosion::GetRadiusOverride, &GCEnvExplosion::SetRadiusOverride)
        .addProperty("InnerRadius", &GCEnvExplosion::GetInnerRadius, &GCEnvExplosion::SetInnerRadius)
        .addProperty("SpriteScale", &GCEnvExplosion::GetSpriteScale, &GCEnvExplosion::SetSpriteScale)
        .addProperty("DamageForce", &GCEnvExplosion::GetDamageForce, &GCEnvExplosion::SetDamageForce)
        .addProperty("Inflictor", &GCEnvExplosion::GetInflictor, &GCEnvExplosion::SetInflictor)
        .addProperty("CustomDamageType", &GCEnvExplosion::GetCustomDamageType, &GCEnvExplosion::SetCustomDamageType)
        .addProperty("ExplosionType", &GCEnvExplosion::GetExplosionType, &GCEnvExplosion::SetExplosionType)
        .addProperty("CustomEffectName", &GCEnvExplosion::GetCustomEffectName, &GCEnvExplosion::SetCustomEffectName)
        .addProperty("CustomSoundName", &GCEnvExplosion::GetCustomSoundName, &GCEnvExplosion::SetCustomSoundName)
        .addProperty("ClassIgnore", &GCEnvExplosion::GetClassIgnore, &GCEnvExplosion::SetClassIgnore)
        .addProperty("ClassIgnore2", &GCEnvExplosion::GetClassIgnore2, &GCEnvExplosion::SetClassIgnore2)
        .addProperty("EntityIgnoreName", &GCEnvExplosion::GetEntityIgnoreName, &GCEnvExplosion::SetEntityIgnoreName)
        .addProperty("EntityIgnore", &GCEnvExplosion::GetEntityIgnore, &GCEnvExplosion::SetEntityIgnore)
        .endClass();
}