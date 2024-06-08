#include "../../../core/scripting/generated/classes/GHitReactFixedSettings_t.h"
#include "../core.h"

void SetupLuaClassGHitReactFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GHitReactFixedSettings_t>("HitReactFixedSettings_t")
        .addProperty("WeightListIndex", &GHitReactFixedSettings_t::GetWeightListIndex, &GHitReactFixedSettings_t::SetWeightListIndex)
        .addProperty("EffectedBoneCount", &GHitReactFixedSettings_t::GetEffectedBoneCount, &GHitReactFixedSettings_t::SetEffectedBoneCount)
        .addProperty("MaxImpactForce", &GHitReactFixedSettings_t::GetMaxImpactForce, &GHitReactFixedSettings_t::SetMaxImpactForce)
        .addProperty("MinImpactForce", &GHitReactFixedSettings_t::GetMinImpactForce, &GHitReactFixedSettings_t::SetMinImpactForce)
        .addProperty("WhipImpactScale", &GHitReactFixedSettings_t::GetWhipImpactScale, &GHitReactFixedSettings_t::SetWhipImpactScale)
        .addProperty("CounterRotationScale", &GHitReactFixedSettings_t::GetCounterRotationScale, &GHitReactFixedSettings_t::SetCounterRotationScale)
        .addProperty("DistanceFadeScale", &GHitReactFixedSettings_t::GetDistanceFadeScale, &GHitReactFixedSettings_t::SetDistanceFadeScale)
        .addProperty("PropagationScale", &GHitReactFixedSettings_t::GetPropagationScale, &GHitReactFixedSettings_t::SetPropagationScale)
        .addProperty("WhipDelay", &GHitReactFixedSettings_t::GetWhipDelay, &GHitReactFixedSettings_t::SetWhipDelay)
        .addProperty("SpringStrength", &GHitReactFixedSettings_t::GetSpringStrength, &GHitReactFixedSettings_t::SetSpringStrength)
        .addProperty("WhipSpringStrength", &GHitReactFixedSettings_t::GetWhipSpringStrength, &GHitReactFixedSettings_t::SetWhipSpringStrength)
        .addProperty("MaxAngleRadians", &GHitReactFixedSettings_t::GetMaxAngleRadians, &GHitReactFixedSettings_t::SetMaxAngleRadians)
        .addProperty("HipBoneIndex", &GHitReactFixedSettings_t::GetHipBoneIndex, &GHitReactFixedSettings_t::SetHipBoneIndex)
        .addProperty("HipBoneTranslationScale", &GHitReactFixedSettings_t::GetHipBoneTranslationScale, &GHitReactFixedSettings_t::SetHipBoneTranslationScale)
        .addProperty("HipDipSpringStrength", &GHitReactFixedSettings_t::GetHipDipSpringStrength, &GHitReactFixedSettings_t::SetHipDipSpringStrength)
        .addProperty("HipDipImpactScale", &GHitReactFixedSettings_t::GetHipDipImpactScale, &GHitReactFixedSettings_t::SetHipDipImpactScale)
        .addProperty("HipDipDelay", &GHitReactFixedSettings_t::GetHipDipDelay, &GHitReactFixedSettings_t::SetHipDipDelay)
        .endClass();
}