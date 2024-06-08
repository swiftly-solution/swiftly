#include "../../../core/scripting/generated/classes/GCMoverUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCMoverUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMoverUpdateNode>("CMoverUpdateNode")
        .addProperty("Damping", &GCMoverUpdateNode::GetDamping, &GCMoverUpdateNode::SetDamping)
        .addProperty("FacingTarget", &GCMoverUpdateNode::GetFacingTarget, &GCMoverUpdateNode::SetFacingTarget)
        .addProperty("MoveVecParam", &GCMoverUpdateNode::GetMoveVecParam, &GCMoverUpdateNode::SetMoveVecParam)
        .addProperty("MoveHeadingParam", &GCMoverUpdateNode::GetMoveHeadingParam, &GCMoverUpdateNode::SetMoveHeadingParam)
        .addProperty("TurnToFaceParam", &GCMoverUpdateNode::GetTurnToFaceParam, &GCMoverUpdateNode::SetTurnToFaceParam)
        .addProperty("TurnToFaceOffset", &GCMoverUpdateNode::GetTurnToFaceOffset, &GCMoverUpdateNode::SetTurnToFaceOffset)
        .addProperty("TurnToFaceLimit", &GCMoverUpdateNode::GetTurnToFaceLimit, &GCMoverUpdateNode::SetTurnToFaceLimit)
        .addProperty("Additive", &GCMoverUpdateNode::GetAdditive, &GCMoverUpdateNode::SetAdditive)
        .addProperty("ApplyMovement", &GCMoverUpdateNode::GetApplyMovement, &GCMoverUpdateNode::SetApplyMovement)
        .addProperty("OrientMovement", &GCMoverUpdateNode::GetOrientMovement, &GCMoverUpdateNode::SetOrientMovement)
        .addProperty("ApplyRotation", &GCMoverUpdateNode::GetApplyRotation, &GCMoverUpdateNode::SetApplyRotation)
        .addProperty("LimitOnly", &GCMoverUpdateNode::GetLimitOnly, &GCMoverUpdateNode::SetLimitOnly)
        .endClass();
}