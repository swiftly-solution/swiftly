#include "../../../core/scripting/generated/classes/GCAnimReplayFrame.h"
#include "../core.h"

void SetupLuaClassGCAnimReplayFrame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimReplayFrame>("CAnimReplayFrame")
        .addProperty("TimeStamp", &GCAnimReplayFrame::GetTimeStamp, &GCAnimReplayFrame::SetTimeStamp)
        .endClass();
}