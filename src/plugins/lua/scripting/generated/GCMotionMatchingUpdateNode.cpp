#include "../../../core/scripting/generated/classes/GCMotionMatchingUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCMotionMatchingUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionMatchingUpdateNode>("CMotionMatchingUpdateNode")
        .addProperty("DataSet", &GCMotionMatchingUpdateNode::GetDataSet, &GCMotionMatchingUpdateNode::SetDataSet)
        .addProperty("Weights", &GCMotionMatchingUpdateNode::GetWeights, &GCMotionMatchingUpdateNode::SetWeights)
        .addProperty("SearchEveryTick", &GCMotionMatchingUpdateNode::GetSearchEveryTick, &GCMotionMatchingUpdateNode::SetSearchEveryTick)
        .addProperty("SearchInterval", &GCMotionMatchingUpdateNode::GetSearchInterval, &GCMotionMatchingUpdateNode::SetSearchInterval)
        .addProperty("SearchWhenClipEnds", &GCMotionMatchingUpdateNode::GetSearchWhenClipEnds, &GCMotionMatchingUpdateNode::SetSearchWhenClipEnds)
        .addProperty("SearchWhenGoalChanges", &GCMotionMatchingUpdateNode::GetSearchWhenGoalChanges, &GCMotionMatchingUpdateNode::SetSearchWhenGoalChanges)
        .addProperty("BlendCurve", &GCMotionMatchingUpdateNode::GetBlendCurve, &GCMotionMatchingUpdateNode::SetBlendCurve)
        .addProperty("SampleRate", &GCMotionMatchingUpdateNode::GetSampleRate, &GCMotionMatchingUpdateNode::SetSampleRate)
        .addProperty("BlendTime", &GCMotionMatchingUpdateNode::GetBlendTime, &GCMotionMatchingUpdateNode::SetBlendTime)
        .addProperty("LockClipWhenWaning", &GCMotionMatchingUpdateNode::GetLockClipWhenWaning, &GCMotionMatchingUpdateNode::SetLockClipWhenWaning)
        .addProperty("SelectionThreshold", &GCMotionMatchingUpdateNode::GetSelectionThreshold, &GCMotionMatchingUpdateNode::SetSelectionThreshold)
        .addProperty("ReselectionTimeWindow", &GCMotionMatchingUpdateNode::GetReselectionTimeWindow, &GCMotionMatchingUpdateNode::SetReselectionTimeWindow)
        .addProperty("EnableRotationCorrection", &GCMotionMatchingUpdateNode::GetEnableRotationCorrection, &GCMotionMatchingUpdateNode::SetEnableRotationCorrection)
        .addProperty("GoalAssist", &GCMotionMatchingUpdateNode::GetGoalAssist, &GCMotionMatchingUpdateNode::SetGoalAssist)
        .addProperty("GoalAssistDistance", &GCMotionMatchingUpdateNode::GetGoalAssistDistance, &GCMotionMatchingUpdateNode::SetGoalAssistDistance)
        .addProperty("GoalAssistTolerance", &GCMotionMatchingUpdateNode::GetGoalAssistTolerance, &GCMotionMatchingUpdateNode::SetGoalAssistTolerance)
        .addProperty("DistanceScale_Damping", &GCMotionMatchingUpdateNode::GetDistanceScale_Damping, &GCMotionMatchingUpdateNode::SetDistanceScale_Damping)
        .addProperty("DistanceScale_OuterRadius", &GCMotionMatchingUpdateNode::GetDistanceScale_OuterRadius, &GCMotionMatchingUpdateNode::SetDistanceScale_OuterRadius)
        .addProperty("DistanceScale_InnerRadius", &GCMotionMatchingUpdateNode::GetDistanceScale_InnerRadius, &GCMotionMatchingUpdateNode::SetDistanceScale_InnerRadius)
        .addProperty("DistanceScale_MaxScale", &GCMotionMatchingUpdateNode::GetDistanceScale_MaxScale, &GCMotionMatchingUpdateNode::SetDistanceScale_MaxScale)
        .addProperty("DistanceScale_MinScale", &GCMotionMatchingUpdateNode::GetDistanceScale_MinScale, &GCMotionMatchingUpdateNode::SetDistanceScale_MinScale)
        .addProperty("EnableDistanceScaling", &GCMotionMatchingUpdateNode::GetEnableDistanceScaling, &GCMotionMatchingUpdateNode::SetEnableDistanceScaling)
        .endClass();
}