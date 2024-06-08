#include "../../../core/scripting/generated/classes/GCLeanMatrixUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCLeanMatrixUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLeanMatrixUpdateNode>("CLeanMatrixUpdateNode")
        .addProperty("Poses", &GCLeanMatrixUpdateNode::GetPoses, &GCLeanMatrixUpdateNode::SetPoses)
        .addProperty("Damping", &GCLeanMatrixUpdateNode::GetDamping, &GCLeanMatrixUpdateNode::SetDamping)
        .addProperty("BlendSource", &GCLeanMatrixUpdateNode::GetBlendSource, &GCLeanMatrixUpdateNode::SetBlendSource)
        .addProperty("ParamIndex", &GCLeanMatrixUpdateNode::GetParamIndex, &GCLeanMatrixUpdateNode::SetParamIndex)
        .addProperty("VerticalAxis", &GCLeanMatrixUpdateNode::GetVerticalAxis, &GCLeanMatrixUpdateNode::SetVerticalAxis)
        .addProperty("HorizontalAxis", &GCLeanMatrixUpdateNode::GetHorizontalAxis, &GCLeanMatrixUpdateNode::SetHorizontalAxis)
        .addProperty("MaxValue", &GCLeanMatrixUpdateNode::GetMaxValue, &GCLeanMatrixUpdateNode::SetMaxValue)
        .addProperty("SequenceMaxFrame", &GCLeanMatrixUpdateNode::GetSequenceMaxFrame, &GCLeanMatrixUpdateNode::SetSequenceMaxFrame)
        .endClass();
}