#include "../../../core/scripting/generated/classes/GCDynamicProp.h"
#include "../core.h"

void SetupLuaClassGCDynamicProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicProp>("CDynamicProp")
        .addProperty("CreateNavObstacle", &GCDynamicProp::GetCreateNavObstacle, &GCDynamicProp::SetCreateNavObstacle)
        .addProperty("UseHitboxesForRenderBox", &GCDynamicProp::GetUseHitboxesForRenderBox, &GCDynamicProp::SetUseHitboxesForRenderBox)
        .addProperty("UseAnimGraph", &GCDynamicProp::GetUseAnimGraph, &GCDynamicProp::SetUseAnimGraph)
        .addProperty("OutputAnimBegun", &GCDynamicProp::GetOutputAnimBegun, &GCDynamicProp::SetOutputAnimBegun)
        .addProperty("OutputAnimOver", &GCDynamicProp::GetOutputAnimOver, &GCDynamicProp::SetOutputAnimOver)
        .addProperty("OutputAnimLoopCycleOver", &GCDynamicProp::GetOutputAnimLoopCycleOver, &GCDynamicProp::SetOutputAnimLoopCycleOver)
        .addProperty("OnAnimReachedStart", &GCDynamicProp::GetOnAnimReachedStart, &GCDynamicProp::SetOnAnimReachedStart)
        .addProperty("OnAnimReachedEnd", &GCDynamicProp::GetOnAnimReachedEnd, &GCDynamicProp::SetOnAnimReachedEnd)
        .addProperty("IdleAnim", &GCDynamicProp::GetIdleAnim, &GCDynamicProp::SetIdleAnim)
        .addProperty("IdleAnimLoopMode", &GCDynamicProp::GetIdleAnimLoopMode, &GCDynamicProp::SetIdleAnimLoopMode)
        .addProperty("RandomizeCycle", &GCDynamicProp::GetRandomizeCycle, &GCDynamicProp::SetRandomizeCycle)
        .addProperty("StartDisabled", &GCDynamicProp::GetStartDisabled, &GCDynamicProp::SetStartDisabled)
        .addProperty("FiredStartEndOutput", &GCDynamicProp::GetFiredStartEndOutput, &GCDynamicProp::SetFiredStartEndOutput)
        .addProperty("ForceNpcExclude", &GCDynamicProp::GetForceNpcExclude, &GCDynamicProp::SetForceNpcExclude)
        .addProperty("CreateNonSolid", &GCDynamicProp::GetCreateNonSolid, &GCDynamicProp::SetCreateNonSolid)
        .addProperty("IsOverrideProp", &GCDynamicProp::GetIsOverrideProp, &GCDynamicProp::SetIsOverrideProp)
        .addProperty("InitialGlowState", &GCDynamicProp::GetInitialGlowState, &GCDynamicProp::SetInitialGlowState)
        .addProperty("GlowRange", &GCDynamicProp::GetGlowRange, &GCDynamicProp::SetGlowRange)
        .addProperty("GlowRangeMin", &GCDynamicProp::GetGlowRangeMin, &GCDynamicProp::SetGlowRangeMin)
        .addProperty("GlowColor", &GCDynamicProp::GetGlowColor, &GCDynamicProp::SetGlowColor)
        .addProperty("GlowTeam", &GCDynamicProp::GetGlowTeam, &GCDynamicProp::SetGlowTeam)
        .endClass();
}