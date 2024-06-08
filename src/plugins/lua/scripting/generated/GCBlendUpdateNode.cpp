#include "../../../core/scripting/generated/classes/GCBlendUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCBlendUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlendUpdateNode>("CBlendUpdateNode")
        .addProperty("Children", &GCBlendUpdateNode::GetChildren, &GCBlendUpdateNode::SetChildren)
        .addProperty("SortedOrder", &GCBlendUpdateNode::GetSortedOrder, &GCBlendUpdateNode::SetSortedOrder)
        .addProperty("TargetValues", &GCBlendUpdateNode::GetTargetValues, &GCBlendUpdateNode::SetTargetValues)
        .addProperty("BlendValueSource", &GCBlendUpdateNode::GetBlendValueSource, &GCBlendUpdateNode::SetBlendValueSource)
        .addProperty("ParamIndex", &GCBlendUpdateNode::GetParamIndex, &GCBlendUpdateNode::SetParamIndex)
        .addProperty("Damping", &GCBlendUpdateNode::GetDamping, &GCBlendUpdateNode::SetDamping)
        .addProperty("BlendKeyType", &GCBlendUpdateNode::GetBlendKeyType, &GCBlendUpdateNode::SetBlendKeyType)
        .addProperty("LockBlendOnReset", &GCBlendUpdateNode::GetLockBlendOnReset, &GCBlendUpdateNode::SetLockBlendOnReset)
        .addProperty("SyncCycles", &GCBlendUpdateNode::GetSyncCycles, &GCBlendUpdateNode::SetSyncCycles)
        .addProperty("Loop", &GCBlendUpdateNode::GetLoop, &GCBlendUpdateNode::SetLoop)
        .addProperty("LockWhenWaning", &GCBlendUpdateNode::GetLockWhenWaning, &GCBlendUpdateNode::SetLockWhenWaning)
        .endClass();
}