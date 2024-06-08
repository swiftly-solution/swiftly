#include "../../../core/scripting/generated/classes/GCFootPinningUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFootPinningUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootPinningUpdateNode>("CFootPinningUpdateNode")
        .addProperty("PoseOpFixedData", &GCFootPinningUpdateNode::GetPoseOpFixedData, &GCFootPinningUpdateNode::SetPoseOpFixedData)
        .addProperty("TimingSource", &GCFootPinningUpdateNode::GetTimingSource, &GCFootPinningUpdateNode::SetTimingSource)
        .addProperty("Params", &GCFootPinningUpdateNode::GetParams, &GCFootPinningUpdateNode::SetParams)
        .addProperty("ResetChild", &GCFootPinningUpdateNode::GetResetChild, &GCFootPinningUpdateNode::SetResetChild)
        .endClass();
}