#include "../../../core/scripting/generated/classes/GCBoneMaskUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCBoneMaskUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneMaskUpdateNode>("CBoneMaskUpdateNode")
        .addProperty("WeightListIndex", &GCBoneMaskUpdateNode::GetWeightListIndex, &GCBoneMaskUpdateNode::SetWeightListIndex)
        .addProperty("RootMotionBlend", &GCBoneMaskUpdateNode::GetRootMotionBlend, &GCBoneMaskUpdateNode::SetRootMotionBlend)
        .addProperty("BlendSpace", &GCBoneMaskUpdateNode::GetBlendSpace, &GCBoneMaskUpdateNode::SetBlendSpace)
        .addProperty("FootMotionTiming", &GCBoneMaskUpdateNode::GetFootMotionTiming, &GCBoneMaskUpdateNode::SetFootMotionTiming)
        .addProperty("UseBlendScale", &GCBoneMaskUpdateNode::GetUseBlendScale, &GCBoneMaskUpdateNode::SetUseBlendScale)
        .addProperty("BlendValueSource", &GCBoneMaskUpdateNode::GetBlendValueSource, &GCBoneMaskUpdateNode::SetBlendValueSource)
        .addProperty("BlendParameter", &GCBoneMaskUpdateNode::GetBlendParameter, &GCBoneMaskUpdateNode::SetBlendParameter)
        .endClass();
}