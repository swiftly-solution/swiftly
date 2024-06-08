#include "../../../core/scripting/generated/classes/GCBlend2DUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCBlend2DUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlend2DUpdateNode>("CBlend2DUpdateNode")
        .addProperty("Items", &GCBlend2DUpdateNode::GetItems, &GCBlend2DUpdateNode::SetItems)
        .addProperty("Tags", &GCBlend2DUpdateNode::GetTags, &GCBlend2DUpdateNode::SetTags)
        .addProperty("ParamSpans", &GCBlend2DUpdateNode::GetParamSpans, &GCBlend2DUpdateNode::SetParamSpans)
        .addProperty("NodeItemIndices", &GCBlend2DUpdateNode::GetNodeItemIndices, &GCBlend2DUpdateNode::SetNodeItemIndices)
        .addProperty("Damping", &GCBlend2DUpdateNode::GetDamping, &GCBlend2DUpdateNode::SetDamping)
        .addProperty("BlendSourceX", &GCBlend2DUpdateNode::GetBlendSourceX, &GCBlend2DUpdateNode::SetBlendSourceX)
        .addProperty("ParamX", &GCBlend2DUpdateNode::GetParamX, &GCBlend2DUpdateNode::SetParamX)
        .addProperty("BlendSourceY", &GCBlend2DUpdateNode::GetBlendSourceY, &GCBlend2DUpdateNode::SetBlendSourceY)
        .addProperty("ParamY", &GCBlend2DUpdateNode::GetParamY, &GCBlend2DUpdateNode::SetParamY)
        .addProperty("BlendMode", &GCBlend2DUpdateNode::GetBlendMode, &GCBlend2DUpdateNode::SetBlendMode)
        .addProperty("PlaybackSpeed", &GCBlend2DUpdateNode::GetPlaybackSpeed, &GCBlend2DUpdateNode::SetPlaybackSpeed)
        .addProperty("Loop", &GCBlend2DUpdateNode::GetLoop, &GCBlend2DUpdateNode::SetLoop)
        .addProperty("LockBlendOnReset", &GCBlend2DUpdateNode::GetLockBlendOnReset, &GCBlend2DUpdateNode::SetLockBlendOnReset)
        .addProperty("LockWhenWaning", &GCBlend2DUpdateNode::GetLockWhenWaning, &GCBlend2DUpdateNode::SetLockWhenWaning)
        .addProperty("AnimEventsAndTagsOnMostWeightedOnly", &GCBlend2DUpdateNode::GetAnimEventsAndTagsOnMostWeightedOnly, &GCBlend2DUpdateNode::SetAnimEventsAndTagsOnMostWeightedOnly)
        .endClass();
}