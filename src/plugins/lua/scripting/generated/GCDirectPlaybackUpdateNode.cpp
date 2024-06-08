#include "../../../core/scripting/generated/classes/GCDirectPlaybackUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCDirectPlaybackUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDirectPlaybackUpdateNode>("CDirectPlaybackUpdateNode")
        .addProperty("FinishEarly", &GCDirectPlaybackUpdateNode::GetFinishEarly, &GCDirectPlaybackUpdateNode::SetFinishEarly)
        .addProperty("ResetOnFinish", &GCDirectPlaybackUpdateNode::GetResetOnFinish, &GCDirectPlaybackUpdateNode::SetResetOnFinish)
        .addProperty("AllTags", &GCDirectPlaybackUpdateNode::GetAllTags, &GCDirectPlaybackUpdateNode::SetAllTags)
        .endClass();
}