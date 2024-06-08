#include "../../../core/scripting/generated/classes/GCNewParticleEffect.h"
#include "../core.h"

void SetupLuaClassGCNewParticleEffect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNewParticleEffect>("CNewParticleEffect")
        .addProperty("Next", &GCNewParticleEffect::GetNext, &GCNewParticleEffect::SetNext)
        .addProperty("Prev", &GCNewParticleEffect::GetPrev, &GCNewParticleEffect::SetPrev)
        .addProperty("Particles", &GCNewParticleEffect::GetParticles, &GCNewParticleEffect::SetParticles)
        .addProperty("DebugName", &GCNewParticleEffect::GetDebugName, &GCNewParticleEffect::SetDebugName)
        .addProperty("SortOrigin", &GCNewParticleEffect::GetSortOrigin, &GCNewParticleEffect::SetSortOrigin)
        .addProperty("Scale", &GCNewParticleEffect::GetScale, &GCNewParticleEffect::SetScale)
        .addProperty("Owner", &GCNewParticleEffect::GetOwner, &GCNewParticleEffect::SetOwner)
        .addProperty("OwningParticleProperty", &GCNewParticleEffect::GetOwningParticleProperty, &GCNewParticleEffect::SetOwningParticleProperty)
        .addProperty("FreezeTransitionStart", &GCNewParticleEffect::GetFreezeTransitionStart, &GCNewParticleEffect::SetFreezeTransitionStart)
        .addProperty("FreezeTransitionDuration", &GCNewParticleEffect::GetFreezeTransitionDuration, &GCNewParticleEffect::SetFreezeTransitionDuration)
        .addProperty("FreezeTransitionOverride", &GCNewParticleEffect::GetFreezeTransitionOverride, &GCNewParticleEffect::SetFreezeTransitionOverride)
        .addProperty("FreezeTransitionActive", &GCNewParticleEffect::GetFreezeTransitionActive, &GCNewParticleEffect::SetFreezeTransitionActive)
        .addProperty("FreezeTargetState", &GCNewParticleEffect::GetFreezeTargetState, &GCNewParticleEffect::SetFreezeTargetState)
        .addProperty("CanFreeze", &GCNewParticleEffect::GetCanFreeze, &GCNewParticleEffect::SetCanFreeze)
        .addProperty("LastMin", &GCNewParticleEffect::GetLastMin, &GCNewParticleEffect::SetLastMin)
        .addProperty("LastMax", &GCNewParticleEffect::GetLastMax, &GCNewParticleEffect::SetLastMax)
        .addProperty("SplitScreenUser", &GCNewParticleEffect::GetSplitScreenUser, &GCNewParticleEffect::SetSplitScreenUser)
        .addProperty("AggregationCenter", &GCNewParticleEffect::GetAggregationCenter, &GCNewParticleEffect::SetAggregationCenter)
        .addProperty("RefCount", &GCNewParticleEffect::GetRefCount, &GCNewParticleEffect::SetRefCount)
        .endClass();
}