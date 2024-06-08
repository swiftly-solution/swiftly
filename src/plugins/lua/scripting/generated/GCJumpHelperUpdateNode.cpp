#include "../../../core/scripting/generated/classes/GCJumpHelperUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCJumpHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCJumpHelperUpdateNode>("CJumpHelperUpdateNode")
        .addProperty("TargetParam", &GCJumpHelperUpdateNode::GetTargetParam, &GCJumpHelperUpdateNode::SetTargetParam)
        .addProperty("OriginalJumpMovement", &GCJumpHelperUpdateNode::GetOriginalJumpMovement, &GCJumpHelperUpdateNode::SetOriginalJumpMovement)
        .addProperty("OriginalJumpDuration", &GCJumpHelperUpdateNode::GetOriginalJumpDuration, &GCJumpHelperUpdateNode::SetOriginalJumpDuration)
        .addProperty("JumpStartCycle", &GCJumpHelperUpdateNode::GetJumpStartCycle, &GCJumpHelperUpdateNode::SetJumpStartCycle)
        .addProperty("JumpEndCycle", &GCJumpHelperUpdateNode::GetJumpEndCycle, &GCJumpHelperUpdateNode::SetJumpEndCycle)
        .addProperty("CorrectionMethod", &GCJumpHelperUpdateNode::GetCorrectionMethod, &GCJumpHelperUpdateNode::SetCorrectionMethod)
        .addProperty("TranslationAxis", &GCJumpHelperUpdateNode::GetTranslationAxis, &GCJumpHelperUpdateNode::SetTranslationAxis)
        .addProperty("ScaleSpeed", &GCJumpHelperUpdateNode::GetScaleSpeed, &GCJumpHelperUpdateNode::SetScaleSpeed)
        .endClass();
}