#include "../../../core/scripting/generated/classes/GCNmTransitionNode.h"
#include "../core.h"

void SetupLuaClassGCNmTransitionNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTransitionNode>("CNmTransitionNode")
        .addProperty("TargetCNmStateNodeIdx", &GCNmTransitionNode::GetTargetCNmStateNodeIdx, &GCNmTransitionNode::SetTargetCNmStateNodeIdx)
        .addProperty("DurationOverrideNodeIdx", &GCNmTransitionNode::GetDurationOverrideNodeIdx, &GCNmTransitionNode::SetDurationOverrideNodeIdx)
        .addProperty("SyncEventOffsetOverrideNodeIdx", &GCNmTransitionNode::GetSyncEventOffsetOverrideNodeIdx, &GCNmTransitionNode::SetSyncEventOffsetOverrideNodeIdx)
        .addProperty("StartBoneMaskNodeIdx", &GCNmTransitionNode::GetStartBoneMaskNodeIdx, &GCNmTransitionNode::SetStartBoneMaskNodeIdx)
        .addProperty("Duration", &GCNmTransitionNode::GetDuration, &GCNmTransitionNode::SetDuration)
        .addProperty("BoneMaskBlendInTimePercentage", &GCNmTransitionNode::GetBoneMaskBlendInTimePercentage, &GCNmTransitionNode::SetBoneMaskBlendInTimePercentage)
        .addProperty("SyncEventOffset", &GCNmTransitionNode::GetSyncEventOffset, &GCNmTransitionNode::SetSyncEventOffset)
        .addProperty("TransitionOptions", &GCNmTransitionNode::GetTransitionOptions, &GCNmTransitionNode::SetTransitionOptions)
        .addProperty("TargetSyncIDNodeIdx", &GCNmTransitionNode::GetTargetSyncIDNodeIdx, &GCNmTransitionNode::SetTargetSyncIDNodeIdx)
        .addProperty("BlendWeightEasing", &GCNmTransitionNode::GetBlendWeightEasing, &GCNmTransitionNode::SetBlendWeightEasing)
        .addProperty("RootMotionBlend", &GCNmTransitionNode::GetRootMotionBlend, &GCNmTransitionNode::SetRootMotionBlend)
        .endClass();
}