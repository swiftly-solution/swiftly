#include "../../../core/scripting/generated/classes/GCFootAdjustmentUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFootAdjustmentUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootAdjustmentUpdateNode>("CFootAdjustmentUpdateNode")
        .addProperty("BasePoseCacheHandle", &GCFootAdjustmentUpdateNode::GetBasePoseCacheHandle, &GCFootAdjustmentUpdateNode::SetBasePoseCacheHandle)
        .addProperty("FacingTarget", &GCFootAdjustmentUpdateNode::GetFacingTarget, &GCFootAdjustmentUpdateNode::SetFacingTarget)
        .addProperty("TurnTimeMin", &GCFootAdjustmentUpdateNode::GetTurnTimeMin, &GCFootAdjustmentUpdateNode::SetTurnTimeMin)
        .addProperty("TurnTimeMax", &GCFootAdjustmentUpdateNode::GetTurnTimeMax, &GCFootAdjustmentUpdateNode::SetTurnTimeMax)
        .addProperty("StepHeightMax", &GCFootAdjustmentUpdateNode::GetStepHeightMax, &GCFootAdjustmentUpdateNode::SetStepHeightMax)
        .addProperty("StepHeightMaxAngle", &GCFootAdjustmentUpdateNode::GetStepHeightMaxAngle, &GCFootAdjustmentUpdateNode::SetStepHeightMaxAngle)
        .addProperty("ResetChild", &GCFootAdjustmentUpdateNode::GetResetChild, &GCFootAdjustmentUpdateNode::SetResetChild)
        .addProperty("AnimationDriven", &GCFootAdjustmentUpdateNode::GetAnimationDriven, &GCFootAdjustmentUpdateNode::SetAnimationDriven)
        .endClass();
}