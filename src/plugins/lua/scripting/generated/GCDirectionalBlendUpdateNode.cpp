#include "../../../core/scripting/generated/classes/GCDirectionalBlendUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCDirectionalBlendUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDirectionalBlendUpdateNode>("CDirectionalBlendUpdateNode")
        .addProperty("Damping", &GCDirectionalBlendUpdateNode::GetDamping, &GCDirectionalBlendUpdateNode::SetDamping)
        .addProperty("BlendValueSource", &GCDirectionalBlendUpdateNode::GetBlendValueSource, &GCDirectionalBlendUpdateNode::SetBlendValueSource)
        .addProperty("ParamIndex", &GCDirectionalBlendUpdateNode::GetParamIndex, &GCDirectionalBlendUpdateNode::SetParamIndex)
        .addProperty("PlaybackSpeed", &GCDirectionalBlendUpdateNode::GetPlaybackSpeed, &GCDirectionalBlendUpdateNode::SetPlaybackSpeed)
        .addProperty("Duration", &GCDirectionalBlendUpdateNode::GetDuration, &GCDirectionalBlendUpdateNode::SetDuration)
        .addProperty("Loop", &GCDirectionalBlendUpdateNode::GetLoop, &GCDirectionalBlendUpdateNode::SetLoop)
        .addProperty("LockBlendOnReset", &GCDirectionalBlendUpdateNode::GetLockBlendOnReset, &GCDirectionalBlendUpdateNode::SetLockBlendOnReset)
        .endClass();
}