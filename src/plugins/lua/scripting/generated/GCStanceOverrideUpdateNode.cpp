#include "../../../core/scripting/generated/classes/GCStanceOverrideUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCStanceOverrideUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStanceOverrideUpdateNode>("CStanceOverrideUpdateNode")
        .addProperty("FootStanceInfo", &GCStanceOverrideUpdateNode::GetFootStanceInfo, &GCStanceOverrideUpdateNode::SetFootStanceInfo)
        .addProperty("StanceSourceNode", &GCStanceOverrideUpdateNode::GetStanceSourceNode, &GCStanceOverrideUpdateNode::SetStanceSourceNode)
        .addProperty("Parameter", &GCStanceOverrideUpdateNode::GetParameter, &GCStanceOverrideUpdateNode::SetParameter)
        .addProperty("Mode", &GCStanceOverrideUpdateNode::GetMode, &GCStanceOverrideUpdateNode::SetMode)
        .endClass();
}