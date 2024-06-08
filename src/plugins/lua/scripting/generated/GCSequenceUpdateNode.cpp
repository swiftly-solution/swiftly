#include "../../../core/scripting/generated/classes/GCSequenceUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSequenceUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSequenceUpdateNode>("CSequenceUpdateNode")
        .addProperty("ParamSpans", &GCSequenceUpdateNode::GetParamSpans, &GCSequenceUpdateNode::SetParamSpans)
        .addProperty("Tags", &GCSequenceUpdateNode::GetTags, &GCSequenceUpdateNode::SetTags)
        .addProperty("PlaybackSpeed", &GCSequenceUpdateNode::GetPlaybackSpeed, &GCSequenceUpdateNode::SetPlaybackSpeed)
        .addProperty("Duration", &GCSequenceUpdateNode::GetDuration, &GCSequenceUpdateNode::SetDuration)
        .addProperty("Loop", &GCSequenceUpdateNode::GetLoop, &GCSequenceUpdateNode::SetLoop)
        .endClass();
}