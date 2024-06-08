#include "../../../core/scripting/generated/classes/GCFollowPathUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFollowPathUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFollowPathUpdateNode>("CFollowPathUpdateNode")
        .addProperty("BlendOutTime", &GCFollowPathUpdateNode::GetBlendOutTime, &GCFollowPathUpdateNode::SetBlendOutTime)
        .addProperty("BlockNonPathMovement", &GCFollowPathUpdateNode::GetBlockNonPathMovement, &GCFollowPathUpdateNode::SetBlockNonPathMovement)
        .addProperty("StopFeetAtGoal", &GCFollowPathUpdateNode::GetStopFeetAtGoal, &GCFollowPathUpdateNode::SetStopFeetAtGoal)
        .addProperty("ScaleSpeed", &GCFollowPathUpdateNode::GetScaleSpeed, &GCFollowPathUpdateNode::SetScaleSpeed)
        .addProperty("Scale", &GCFollowPathUpdateNode::GetScale, &GCFollowPathUpdateNode::SetScale)
        .addProperty("MinAngle", &GCFollowPathUpdateNode::GetMinAngle, &GCFollowPathUpdateNode::SetMinAngle)
        .addProperty("MaxAngle", &GCFollowPathUpdateNode::GetMaxAngle, &GCFollowPathUpdateNode::SetMaxAngle)
        .addProperty("SpeedScaleBlending", &GCFollowPathUpdateNode::GetSpeedScaleBlending, &GCFollowPathUpdateNode::SetSpeedScaleBlending)
        .addProperty("TurnDamping", &GCFollowPathUpdateNode::GetTurnDamping, &GCFollowPathUpdateNode::SetTurnDamping)
        .addProperty("FacingTarget", &GCFollowPathUpdateNode::GetFacingTarget, &GCFollowPathUpdateNode::SetFacingTarget)
        .addProperty("Param", &GCFollowPathUpdateNode::GetParam, &GCFollowPathUpdateNode::SetParam)
        .addProperty("TurnToFaceOffset", &GCFollowPathUpdateNode::GetTurnToFaceOffset, &GCFollowPathUpdateNode::SetTurnToFaceOffset)
        .addProperty("TurnToFace", &GCFollowPathUpdateNode::GetTurnToFace, &GCFollowPathUpdateNode::SetTurnToFace)
        .endClass();
}