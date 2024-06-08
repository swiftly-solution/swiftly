#include "../../../core/scripting/generated/classes/GCSelectorUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSelectorUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSelectorUpdateNode>("CSelectorUpdateNode")
        .addProperty("Children", &GCSelectorUpdateNode::GetChildren, &GCSelectorUpdateNode::SetChildren)
        .addProperty("Tags", &GCSelectorUpdateNode::GetTags, &GCSelectorUpdateNode::SetTags)
        .addProperty("BlendCurve", &GCSelectorUpdateNode::GetBlendCurve, &GCSelectorUpdateNode::SetBlendCurve)
        .addProperty("Parameter", &GCSelectorUpdateNode::GetParameter, &GCSelectorUpdateNode::SetParameter)
        .addProperty("TagIndex", &GCSelectorUpdateNode::GetTagIndex, &GCSelectorUpdateNode::SetTagIndex)
        .addProperty("TagBehavior", &GCSelectorUpdateNode::GetTagBehavior, &GCSelectorUpdateNode::SetTagBehavior)
        .addProperty("ResetOnChange", &GCSelectorUpdateNode::GetResetOnChange, &GCSelectorUpdateNode::SetResetOnChange)
        .addProperty("LockWhenWaning", &GCSelectorUpdateNode::GetLockWhenWaning, &GCSelectorUpdateNode::SetLockWhenWaning)
        .addProperty("SyncCyclesOnChange", &GCSelectorUpdateNode::GetSyncCyclesOnChange, &GCSelectorUpdateNode::SetSyncCyclesOnChange)
        .endClass();
}