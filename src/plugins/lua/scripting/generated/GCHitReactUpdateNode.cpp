#include "../../../core/scripting/generated/classes/GCHitReactUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCHitReactUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitReactUpdateNode>("CHitReactUpdateNode")
        .addProperty("OpFixedSettings", &GCHitReactUpdateNode::GetOpFixedSettings, &GCHitReactUpdateNode::SetOpFixedSettings)
        .addProperty("TriggerParam", &GCHitReactUpdateNode::GetTriggerParam, &GCHitReactUpdateNode::SetTriggerParam)
        .addProperty("HitBoneParam", &GCHitReactUpdateNode::GetHitBoneParam, &GCHitReactUpdateNode::SetHitBoneParam)
        .addProperty("HitOffsetParam", &GCHitReactUpdateNode::GetHitOffsetParam, &GCHitReactUpdateNode::SetHitOffsetParam)
        .addProperty("HitDirectionParam", &GCHitReactUpdateNode::GetHitDirectionParam, &GCHitReactUpdateNode::SetHitDirectionParam)
        .addProperty("HitStrengthParam", &GCHitReactUpdateNode::GetHitStrengthParam, &GCHitReactUpdateNode::SetHitStrengthParam)
        .addProperty("MinDelayBetweenHits", &GCHitReactUpdateNode::GetMinDelayBetweenHits, &GCHitReactUpdateNode::SetMinDelayBetweenHits)
        .addProperty("ResetChild", &GCHitReactUpdateNode::GetResetChild, &GCHitReactUpdateNode::SetResetChild)
        .endClass();
}