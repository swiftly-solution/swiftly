#include "../../../core/scripting/generated/classes/GCNmClipNode.h"
#include "../core.h"

void SetupLuaClassGCNmClipNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmClipNode>("CNmClipNode")
        .addProperty("PlayInReverseValueNodeIdx", &GCNmClipNode::GetPlayInReverseValueNodeIdx, &GCNmClipNode::SetPlayInReverseValueNodeIdx)
        .addProperty("ResetTimeValueNodeIdx", &GCNmClipNode::GetResetTimeValueNodeIdx, &GCNmClipNode::SetResetTimeValueNodeIdx)
        .addProperty("SampleRootMotion", &GCNmClipNode::GetSampleRootMotion, &GCNmClipNode::SetSampleRootMotion)
        .addProperty("AllowLooping", &GCNmClipNode::GetAllowLooping, &GCNmClipNode::SetAllowLooping)
        .addProperty("DataSlotIdx", &GCNmClipNode::GetDataSlotIdx, &GCNmClipNode::SetDataSlotIdx)
        .endClass();
}