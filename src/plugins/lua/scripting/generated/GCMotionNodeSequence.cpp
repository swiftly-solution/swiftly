#include "../../../core/scripting/generated/classes/GCMotionNodeSequence.h"
#include "../core.h"

void SetupLuaClassGCMotionNodeSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionNodeSequence>("CMotionNodeSequence")
        .addProperty("Tags", &GCMotionNodeSequence::GetTags, &GCMotionNodeSequence::SetTags)
        .addProperty("PlaybackSpeed", &GCMotionNodeSequence::GetPlaybackSpeed, &GCMotionNodeSequence::SetPlaybackSpeed)
        .endClass();
}