#include "../../../core/scripting/generated/classes/GCLookAtUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCLookAtUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLookAtUpdateNode>("CLookAtUpdateNode")
        .addProperty("OpFixedSettings", &GCLookAtUpdateNode::GetOpFixedSettings, &GCLookAtUpdateNode::SetOpFixedSettings)
        .addProperty("Target", &GCLookAtUpdateNode::GetTarget, &GCLookAtUpdateNode::SetTarget)
        .addProperty("ParamIndex", &GCLookAtUpdateNode::GetParamIndex, &GCLookAtUpdateNode::SetParamIndex)
        .addProperty("WeightParamIndex", &GCLookAtUpdateNode::GetWeightParamIndex, &GCLookAtUpdateNode::SetWeightParamIndex)
        .addProperty("ResetChild", &GCLookAtUpdateNode::GetResetChild, &GCLookAtUpdateNode::SetResetChild)
        .addProperty("LockWhenWaning", &GCLookAtUpdateNode::GetLockWhenWaning, &GCLookAtUpdateNode::SetLockWhenWaning)
        .endClass();
}