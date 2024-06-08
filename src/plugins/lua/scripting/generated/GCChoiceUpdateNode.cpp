#include "../../../core/scripting/generated/classes/GCChoiceUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCChoiceUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChoiceUpdateNode>("CChoiceUpdateNode")
        .addProperty("Children", &GCChoiceUpdateNode::GetChildren, &GCChoiceUpdateNode::SetChildren)
        .addProperty("Weights", &GCChoiceUpdateNode::GetWeights, &GCChoiceUpdateNode::SetWeights)
        .addProperty("BlendTimes", &GCChoiceUpdateNode::GetBlendTimes, &GCChoiceUpdateNode::SetBlendTimes)
        .addProperty("ChoiceMethod", &GCChoiceUpdateNode::GetChoiceMethod, &GCChoiceUpdateNode::SetChoiceMethod)
        .addProperty("ChoiceChangeMethod", &GCChoiceUpdateNode::GetChoiceChangeMethod, &GCChoiceUpdateNode::SetChoiceChangeMethod)
        .addProperty("BlendMethod", &GCChoiceUpdateNode::GetBlendMethod, &GCChoiceUpdateNode::SetBlendMethod)
        .addProperty("BlendTime", &GCChoiceUpdateNode::GetBlendTime, &GCChoiceUpdateNode::SetBlendTime)
        .addProperty("CrossFade", &GCChoiceUpdateNode::GetCrossFade, &GCChoiceUpdateNode::SetCrossFade)
        .addProperty("ResetChosen", &GCChoiceUpdateNode::GetResetChosen, &GCChoiceUpdateNode::SetResetChosen)
        .addProperty("DontResetSameSelection", &GCChoiceUpdateNode::GetDontResetSameSelection, &GCChoiceUpdateNode::SetDontResetSameSelection)
        .endClass();
}